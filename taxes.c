/**
 * This program computes income taxes based on adjusted
 * gross income and a child tax credit.
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  double agi = 0.0;
  char c = 'N';
  double tax = 0.0;
  double childCredit = 0.0;
  double totalTax = 0.0;
  int numChildren = 0;

  printf("Please enter your adjusted gross income (AGI): ");
  scanf("%lf", &agi);
  //remove the "enter" endline character
  getchar();

  printf("Do you have any children? (Y) or (N)? ");
  c = getchar();

  if(c == 'y' || c == 'Y') {
    printf("How many children do you have? ");
    scanf("%d", &numChildren);
  }

  //TODO: compute the tax, child credit, and total tax here
  if (numChildren < 0) {
    printf("Stop trying to find faults, come on...\n");
    return 0;
  } else {
    childCredit = numChildren * 1000;
  };

  if (agi <= 0) {
    printf("You must be poor, sorry...\n");
    childCredit = 0;
  } else if (agi > 0 && agi <= 17000) {
    tax = 0.1 * agi;
  } else if (agi > 17000 && agi <= 69000) {
    tax = 0.15 * (agi - 17000) + 1700;
  } else if (agi > 69000 && agi <= 139350) {
    tax = 0.25 * (agi - 69000) + 9500;
  } else if (agi > 139350 && agi <= 212300) {
    tax = 0.28 * (agi - 139350) + 27087.5;
  } else if (agi > 212300 && agi <= 379150) {
    tax = 0.33 * (agi - 212300) + 47513.5;
  } else if (agi > 379150) {
    tax = 0.35 * (agi - 379150) + 102574;
  };

  totalTax = tax - childCredit;
  if (totalTax < 0) {
    totalTax = 0;
  };

  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("Total Tax:    $%10.2f\n", totalTax);

  return 0;
}