//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

struct Expense {
  char name[50];
  int amount;
  struct Expense* next;
};

void addExpense(struct Expense** head) {
  struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
  printf("Enter expense name: ");
  scanf("%s", newExpense->name);
  printf("Enter expense amount: ");
  scanf("%d", &newExpense->amount);

  if (*head == NULL) {
    *head = newExpense;
  } else {
    (*head)->next = newExpense;
    *head = newExpense;
  }
}

void printExpenses(struct Expense* head) {
  struct Expense* currentExpense = head;
  printf("Expenses:\n");
  while (currentExpense) {
    printf("%s - %d\n", currentExpense->name, currentExpense->amount);
    currentExpense = currentExpense->next;
  }
}

int main() {
  struct Expense* head = NULL;

  printf("Welcome to the Expense Tracker!\n");

  while (1) {
    char choice;
    printf("Enter 'a' to add an expense, 'p' to print expenses, or 'q' to quit: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        addExpense(&head);
        break;
      case 'p':
        printExpenses(head);
        break;
      case 'q':
        exit(0);
    }
  }

  return 0;
}