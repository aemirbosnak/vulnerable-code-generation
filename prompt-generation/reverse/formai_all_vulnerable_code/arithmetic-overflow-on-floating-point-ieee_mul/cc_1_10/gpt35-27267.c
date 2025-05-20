//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>

/* Personal Finance Planner */
int main() {
  float balance, savings, income, expenses;
  int choice;

  printf("Welcome to the Personal Finance Planner!\n");
  
  /* Get initial balance and savings */
  printf("Enter your initial balance: $");
  scanf("%f", &balance);
  printf("Enter your initial savings: $");
  scanf("%f", &savings);

  while (choice != 5) {
    /* Display menu options */
    printf("\nWhat would you like to do?\n");
    printf("--------------------------\n");
    printf("1. Add income\n");
    printf("2. Add expenses\n");
    printf("3. View current balance and savings\n");
    printf("4. Project future balance and savings\n");
    printf("5. Quit\n");
    printf("--------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Perform selected action */
    switch (choice) {
      case 1:
        printf("\nEnter income amount: $");
        scanf("%f", &income);
        balance += income;
        printf("Your new balance is: $%.2f\n", balance);
        break;
      case 2:
        printf("\nEnter expense amount: $");
        scanf("%f", &expenses);
        balance -= expenses;
        printf("Your new balance is: $%.2f\n", balance);
        break;
      case 3:
        printf("\nYour current balance is: $%.2f\n", balance);
        printf("Your current savings is: $%.2f\n", savings);
        break;
      case 4:
        printf("\nEnter number of months to project: ");
        int months;
        scanf("%d", &months);
        float projected_balance = balance - (expenses * months);
        printf("Your projected balance after %d months is: $%.2f\n", months, projected_balance);
        break;
      case 5:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice!\n");
        break;
    }
  }

  return 0;
}