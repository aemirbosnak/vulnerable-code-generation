//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>

int main() {

  int choice;
  float income, expense, total=0;

  printf("Welcome to the Personal Finance Planner!\n");

  do {
    printf("\n-------------------------------------------\n");
    printf("1. Enter Income\n");
    printf("2. Enter Expense\n");
    printf("3. Show Balance\n");
    printf("4. Exit\n");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter income amount: $");
        scanf("%f", &income);
        total += income;
        printf("Income added successfully!\n");
        break;

      case 2:
        printf("\nEnter expense amount: $");
        scanf("%f", &expense);
        total -= expense;
        printf("Expense deducted successfully!\n");
        break;

      case 3:
        printf("\nYour current balance is: $%.2f\n", total);
        break;

      case 4:
        printf("\nThank you for using the Personal Finance Planner.\n");
        break;

      default:
        printf("\nInvalid choice, please enter a number between 1 and 4.\n");
        break;
    }

  } while (choice != 4);

  return 0;
}