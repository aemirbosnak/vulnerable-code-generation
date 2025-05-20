//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: artistic
// Artistic C Expense Tracker Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

struct expense {
  char category[20];
  char description[50];
  float amount;
};

int main() {
  struct expense expenses[MAX_EXPENSES];
  int num_expenses = 0;
  char choice;

  while (1) {
    printf("Welcome to the C Expense Tracker Program!\n");
    printf("What would you like to do?\n");
    printf("a) Add an expense\n");
    printf("b) View expenses\n");
    printf("c) Quit\n");

    scanf("%c", &choice);

    if (choice == 'a') {
      char category[20];
      char description[50];
      float amount;

      printf("Enter the category: ");
      scanf("%s", category);
      printf("Enter the description: ");
      scanf("%s", description);
      printf("Enter the amount: ");
      scanf("%f", &amount);

      struct expense new_expense = {category, description, amount};
      expenses[num_expenses] = new_expense;
      num_expenses++;
    } else if (choice == 'b') {
      for (int i = 0; i < num_expenses; i++) {
        printf("Expense %d: %s - %s - $%.2f\n", i + 1, expenses[i].category, expenses[i].description, expenses[i].amount);
      }
    } else if (choice == 'c') {
      break;
    } else {
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}