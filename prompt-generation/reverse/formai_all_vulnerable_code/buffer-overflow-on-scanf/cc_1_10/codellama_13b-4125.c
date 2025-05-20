//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: standalone
// Banking Record System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
  int account_number;
  char name[50];
  float balance;
  int age;
  char address[100];
} Customer;

typedef struct {
  int transaction_id;
  char transaction_type[10];
  int account_number;
  float amount;
  char date[20];
} Transaction;

// Functions
void add_customer(Customer *customer) {
  printf("Enter customer details:\n");
  printf("Name: ");
  scanf("%s", customer->name);
  printf("Age: ");
  scanf("%d", &customer->age);
  printf("Address: ");
  scanf("%s", customer->address);
  printf("Account number: ");
  scanf("%d", &customer->account_number);
  printf("Balance: ");
  scanf("%f", &customer->balance);
}

void display_customer(Customer *customer) {
  printf("Name: %s\n", customer->name);
  printf("Age: %d\n", customer->age);
  printf("Address: %s\n", customer->address);
  printf("Account number: %d\n", customer->account_number);
  printf("Balance: %.2f\n", customer->balance);
}

void add_transaction(Transaction *transaction) {
  printf("Enter transaction details:\n");
  printf("Transaction type (deposit/withdrawal): ");
  scanf("%s", transaction->transaction_type);
  printf("Account number: ");
  scanf("%d", &transaction->account_number);
  printf("Amount: ");
  scanf("%f", &transaction->amount);
  printf("Date (DD/MM/YYYY): ");
  scanf("%s", transaction->date);
}

void display_transaction(Transaction *transaction) {
  printf("Transaction type: %s\n", transaction->transaction_type);
  printf("Account number: %d\n", transaction->account_number);
  printf("Amount: %.2f\n", transaction->amount);
  printf("Date: %s\n", transaction->date);
}

int main() {
  Customer customer;
  Transaction transaction;

  add_customer(&customer);
  display_customer(&customer);

  add_transaction(&transaction);
  display_transaction(&transaction);

  return 0;
}