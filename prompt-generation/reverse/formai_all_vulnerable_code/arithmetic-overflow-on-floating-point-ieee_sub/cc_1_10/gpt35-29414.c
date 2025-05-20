//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>

int main() {
  float income;
  float expenses;
  float savings;
  float debt;
  char choice;

  printf("Welcome to your Personal Finance Planner!\n");
  printf("What would you like to do?\n");
  printf("A: Record an income\n");
  printf("B: Record an expense\n");
  printf("C: View your savings\n");
  printf("D: View your debt\n");
  printf("E: Exit\n");

  do {
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(choice) {
      case 'A':
        printf("Enter income amount: ");
        scanf("%f", &income);
        savings += income;
        printf("Income recorded! Your savings now: %.2f\n", savings);
        break;

      case 'B':
        printf("Enter expense amount: ");
        scanf("%f", &expenses);
        if(savings - expenses < 0) {
          printf("Error: Insufficient savings.\n");
        } else {
          savings -= expenses;
          printf("Expense recorded! Your savings now: %.2f\n", savings);
        }
        break;

      case 'C':
        printf("Current savings: %.2f\n", savings);
        break;

      case 'D':
        printf("Enter debt amount: ");
        scanf("%f", &debt);
        printf("Debt recorded! Your total debt is: %.2f\n", debt);
        break;

      case 'E':
        printf("Exiting Personal Finance Planner.\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

  } while(choice != 'E');

  return 0;
}