//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TRANSACTIONS 1000

struct Transaction {
  char date[20];
  char description[100];
  double amount;
};

struct TransactionList {
  int size;
  struct Transaction transactions[MAX_TRANSACTIONS];
  double balance;
};

void printMenu() {
  printf("Expense Tracker\n");
  printf("1. Add transaction\n");
  printf("2. View transactions\n");
  printf("3. View balance\n");
  printf("4. Exit\n");
}

int getMenuChoice() {
  int choice;
  printf("Enter choice (1-4): ");
  scanf("%d", &choice);
  return choice;
}

void addTransaction(struct TransactionList *list) {
  struct Transaction transaction;
  printf("Enter transaction date (mm/dd/yyyy): ");
  scanf("%s", transaction.date);
  printf("Enter transaction description: ");
  scanf("%s", transaction.description);
  printf("Enter transaction amount: ");
  scanf("%lf", &transaction.amount);

  if (list->size < MAX_TRANSACTIONS) {
    list->transactions[list->size++] = transaction;
    list->balance += transaction.amount;
    printf("Transaction added.\n");
  } else {
    printf("Transaction list is full.\n");
  }
}

void viewTransactions(struct TransactionList *list) {
  printf("Transactions:\n");
  for (int i = 0; i < list->size; i++) {
    printf("Date: %s\tDescription: %s\tAmount: $%.2lf\n", list->transactions[i].date, list->transactions[i].description, list->transactions[i].amount);
  }
}

void viewBalance(struct TransactionList *list) {
  printf("Current balance: $%.2lf\n", list->balance);
}

int main() {
  struct TransactionList list = {0};
  bool running = true;

  while (running) {
    printMenu();
    int choice = getMenuChoice();

    switch (choice) {
      case 1:
        addTransaction(&list);
        break;
      case 2:
        viewTransactions(&list);
        break;
      case 3:
        viewBalance(&list);
        break;
      case 4:
        printf("Exiting...\n");
        running = false;
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }

  return 0;
}