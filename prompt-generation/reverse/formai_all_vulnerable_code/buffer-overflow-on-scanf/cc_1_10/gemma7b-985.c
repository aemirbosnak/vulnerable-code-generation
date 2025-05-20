//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSE_NUM 10

typedef struct Expense {
  char name[20];
  float amount;
  char category[20];
} Expense;

void calculateTotalExpense(Expense expenses[], int numExpenses) {
  float totalExpense = 0;
  for (int i = 0; i < numExpenses; i++) {
    totalExpense += expenses[i].amount;
  }
  printf("Total expense: $%.2f", totalExpense);
}

int main() {
  Expense expenses[MAX_EXPENSE_NUM];
  int numExpenses = 0;

  // Create a loop to add expenses
  while (1) {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[numExpenses].category);

    numExpenses++;

    // Check if the user wants to add more expenses
    char answer;
    printf("Do you want to add another expense? (y/n): ");
    scanf(" %c", &answer);

    if (answer == 'n') {
      break;
    }
  }

  // Calculate the total expense
  calculateTotalExpense(expenses, numExpenses);

  return 0;
}