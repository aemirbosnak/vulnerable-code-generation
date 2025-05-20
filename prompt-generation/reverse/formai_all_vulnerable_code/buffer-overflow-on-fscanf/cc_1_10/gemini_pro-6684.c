//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
  char name[50];
  char address[100];
  char phone[20];
  int account_number;
  double balance;
} customer;

typedef struct transaction {
  int account_number;
  char type[20];
  double amount;
  char date[20];
} transaction;

int main() {
  // Create an array of customers
  customer customers[100];

  // Create an array of transactions
  transaction transactions[1000];

  // Read the data from the files
  FILE *customers_file = fopen("customers.txt", "r");
  if (customers_file == NULL) {
    printf("Error opening customers file\n");
    return 1;
  }

  int num_customers = 0;
  while (fscanf(customers_file, "%s %s %s %d %lf", customers[num_customers].name, customers[num_customers].address, customers[num_customers].phone, &customers[num_customers].account_number, &customers[num_customers].balance) != EOF) {
    num_customers++;
  }

  fclose(customers_file);

  FILE *transactions_file = fopen("transactions.txt", "r");
  if (transactions_file == NULL) {
    printf("Error opening transactions file\n");
    return 1;
  }

  int num_transactions = 0;
  while (fscanf(transactions_file, "%d %s %lf %s", &transactions[num_transactions].account_number, transactions[num_transactions].type, &transactions[num_transactions].amount, transactions[num_transactions].date) != EOF) {
    num_transactions++;
  }

  fclose(transactions_file);

  // Get the user's input
  int account_number;
  printf("Enter your account number: ");
  scanf("%d", &account_number);

  // Find the customer's record
  int customer_index = -1;
  for (int i = 0; i < num_customers; i++) {
    if (customers[i].account_number == account_number) {
      customer_index = i;
      break;
    }
  }

  if (customer_index == -1) {
    printf("Invalid account number\n");
    return 1;
  }

  // Print the customer's information
  printf("Name: %s\n", customers[customer_index].name);
  printf("Address: %s\n", customers[customer_index].address);
  printf("Phone: %s\n", customers[customer_index].phone);
  printf("Balance: %lf\n", customers[customer_index].balance);

  // Print the customer's transactions
  printf("Transactions:\n");
  for (int i = 0; i < num_transactions; i++) {
    if (transactions[i].account_number == account_number) {
      printf("%s %s %lf %s\n", transactions[i].type, transactions[i].amount, transactions[i].date);
    }
  }

  return 0;
}