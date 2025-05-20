//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

struct Customer {
  char name[50];
  char address[50];
  char phone[20];
  double balance;
};

struct Transaction {
  char date[20];
  char description[50];
  double amount;
};

struct Bank {
  struct Customer customers[MAX_CUSTOMERS];
  struct Transaction transactions[MAX_TRANSACTIONS];
  int num_customers;
  int num_transactions;
};

int main() {
  struct Bank bank = {0};
  int i, j;

  // Add customers
  for (i = 0; i < MAX_CUSTOMERS; i++) {
    struct Customer customer = {0};
    scanf("%s %s %s %lf", customer.name, customer.address, customer.phone, &customer.balance);
    bank.customers[i] = customer;
    bank.num_customers++;
  }

  // Add transactions
  for (j = 0; j < MAX_TRANSACTIONS; j++) {
    struct Transaction transaction = {0};
    scanf("%s %s %lf", transaction.date, transaction.description, &transaction.amount);
    bank.transactions[j] = transaction;
    bank.num_transactions++;
  }

  // Print customers and transactions
  printf("Customers:\n");
  for (i = 0; i < bank.num_customers; i++) {
    printf("%s: %s, %s, $%f\n", bank.customers[i].name, bank.customers[i].address, bank.customers[i].phone, bank.customers[i].balance);
  }

  printf("Transactions:\n");
  for (j = 0; j < bank.num_transactions; j++) {
    printf("%s: %s, $%f\n", bank.transactions[j].date, bank.transactions[j].description, bank.transactions[j].amount);
  }

  return 0;
}