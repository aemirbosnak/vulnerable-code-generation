//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float budget, expense, savings = 0;
  int choice;

  printf("Welcome to the Personal Finance Planner for the Post-Apocalyptic World.\n\n");

  printf("Enter your budget for the month: ");
  scanf("%f", &budget);

  while (1) {
    printf("\n\t\tMenu\n");
    printf("-------------------------------------\n");
    printf("[1] Enter a new expense\n");
    printf("[2] View savings\n");
    printf("[3] Exit\n");
    printf("-------------------------------------\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\n");
        printf("Enter your new expense: ");
        scanf("%f", &expense);

        if (expense > budget) {
          printf("You cannot spend more than your budget!\n");
        } else {
          budget -= expense;
          printf("Your remaining budget is: %.2f\n", budget);
          savings += expense * 0.1;
        }

        break;
      case 2:
        printf("\n");
        printf("Your current savings are: %.2f\n", savings);
        break;
      case 3:
        printf("\n\t\tGoodbye!\n");
        exit(0);
      default:
        printf("\nInvalid input! Please enter a valid choice.\n");
        break;
    }
  }

  return 0;
}