//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: configurable
// Banking Record System

#include <stdio.h>
#include <stdlib.h>

// Define structure for bank account
typedef struct {
  int id;
  char name[50];
  double balance;
} BankAccount;

// Define structure for bank transaction
typedef struct {
  int account_id;
  double amount;
  char type[10];
  char date[10];
} BankTransaction;

// Define structure for bank statement
typedef struct {
  BankAccount *account;
  BankTransaction *transactions;
  int num_transactions;
} BankStatement;

// Define function to create a new bank account
BankAccount* create_account(int id, char* name, double balance) {
  BankAccount* account = malloc(sizeof(BankAccount));
  account->id = id;
  strcpy(account->name, name);
  account->balance = balance;
  return account;
}

// Define function to create a new bank transaction
BankTransaction* create_transaction(int account_id, double amount, char* type, char* date) {
  BankTransaction* transaction = malloc(sizeof(BankTransaction));
  transaction->account_id = account_id;
  transaction->amount = amount;
  strcpy(transaction->type, type);
  strcpy(transaction->date, date);
  return transaction;
}

// Define function to create a new bank statement
BankStatement* create_statement(BankAccount* account, BankTransaction* transactions, int num_transactions) {
  BankStatement* statement = malloc(sizeof(BankStatement));
  statement->account = account;
  statement->transactions = transactions;
  statement->num_transactions = num_transactions;
  return statement;
}

// Define function to print a bank statement
void print_statement(BankStatement* statement) {
  printf("Bank Statement for Account %d\n", statement->account->id);
  printf("Name: %s\n", statement->account->name);
  printf("Balance: $%.2f\n", statement->account->balance);
  printf("Transactions:\n");
  for (int i = 0; i < statement->num_transactions; i++) {
    printf("  %s: $%.2f on %s\n", statement->transactions[i].type, statement->transactions[i].amount, statement->transactions[i].date);
  }
}

// Test code
int main() {
  // Create a new bank account
  BankAccount* account = create_account(12345, "John Doe", 1000.00);

  // Create a new bank transaction
  BankTransaction* transaction = create_transaction(12345, 50.00, "deposit", "2022-03-21");

  // Create a new bank statement
  BankStatement* statement = create_statement(account, &transaction, 1);

  // Print the bank statement
  print_statement(statement);

  // Free memory
  free(account);
  free(transaction);
  free(statement);

  return 0;
}