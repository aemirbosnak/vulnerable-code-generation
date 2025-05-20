//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  float amount;
} Expense;

int main() {
  printf("Welcome to the Expense Tracker!\n");

  int num_expenses;
  printf("How many expenses do you have?\n");
  scanf("%d", &num_expenses);

  Expense *expenses = malloc(num_expenses * sizeof(Expense));

  for (int i = 0; i < num_expenses; i++) {
    printf("Enter the name of the expense:\n");
    char *name = malloc(100);
    scanf("%s", name);

    printf("Enter the amount of the expense:\n");
    float amount;
    scanf("%f", &amount);

    expenses[i].name = name;
    expenses[i].amount = amount;
  }

  // Sort the expenses by amount
  for (int i = 0; i < num_expenses - 1; i++) {
    for (int j = i + 1; j < num_expenses; j++) {
      if (expenses[i].amount > expenses[j].amount) {
        Expense temp = expenses[i];
        expenses[i] = expenses[j];
        expenses[j] = temp;
      }
    }
  }

  // Print the sorted expenses
  printf("\nSorted expenses:\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
    free(expenses[i].name);
  }

  free(expenses);

  return 0;
}