//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem {
  char name[50];
  int amount;
  struct ExpenseItem* next;
} ExpenseItem;

void addExpenseItem(ExpenseItem** head) {
  ExpenseItem* newExpenseItem = malloc(sizeof(ExpenseItem));
  newExpenseItem->next = NULL;

  printf("Enter expense name: ");
  scanf("%s", newExpenseItem->name);

  printf("Enter expense amount: ");
  scanf("%d", &newExpenseItem->amount);

  if (*head == NULL) {
    *head = newExpenseItem;
  } else {
    (*head)->next = newExpenseItem;
  }
}

void printExpenseItems(ExpenseItem* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->amount);
    head = head->next;
  }
}

int main() {
  ExpenseItem* head = NULL;

  printf("Enter 'add' to add an expense item, 'print' to print all expense items, or 'exit' to exit: ");
  char command[20];
  scanf("%s", command);

  while (strcmp(command, "exit") != 0) {
    if (strcmp(command, "add") == 0) {
      addExpenseItem(&head);
    } else if (strcmp(command, "print") == 0) {
      printExpenseItems(head);
    } else {
      printf("Invalid command.\n");
    }

    printf("Enter 'add' to add an expense item, 'print' to print all expense items, or 'exit' to exit: ");
    scanf("%s", command);
  }

  printf("Goodbye.\n");

  return 0;
}