//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS_PER_CUSTOMER 10

// Structure to represent a customer
typedef struct {
  char name[50];
  char email[50];
  char phone[20];
  int num_accounts;
  int account_ids[MAX_ACCOUNTS_PER_CUSTOMER];
} Customer;

// Structure to represent an account
typedef struct {
  int id;
  double balance;
  char type; // S - savings, C - current
} Account;

// Function to add a new customer
void add_customer(Customer *customers, int *num_customers) {
  if (*num_customers >= MAX_CUSTOMERS) {
    printf("Maximum number of customers reached.\n");
    return;
  }

  Customer customer;
  printf("Enter customer name: ");
  scanf("%s", customer.name);
  printf("Enter customer email: ");
  scanf("%s", customer.email);
  printf("Enter customer phone: ");
  scanf("%s", customer.phone);
  customer.num_accounts = 0;

  customers[*num_customers] = customer;
  (*num_customers)++;
}

// Function to add a new account
void add_account(Customer *customers, int *num_customers, int *num_accounts) {
  if (*num_accounts >= MAX_ACCOUNTS_PER_CUSTOMER) {
    printf("Maximum number of accounts reached.\n");
    return;
  }

  int customer_index = 0;
  printf("Enter customer index: ");
  scanf("%d", &customer_index);

  if (customer_index < 0 || customer_index >= *num_customers) {
    printf("Invalid customer index.\n");
    return;
  }

  Customer *customer = &customers[customer_index];
  Account account;
  printf("Enter account id: ");
  scanf("%d", &account.id);
  printf("Enter account balance: ");
  scanf("%lf", &account.balance);
  printf("Enter account type (S or C): ");
  scanf(" %c", &account.type);

  customer->account_ids[customer->num_accounts] = account.id;
  customer->num_accounts++;

  (*num_accounts)++;
}

// Function to print customer details
void print_customer(Customer *customers, int *num_customers) {
  for (int i = 0; i < *num_customers; i++) {
    Customer *customer = &customers[i];
    printf("Customer %d: %s\n", i, customer->name);
    printf("Email: %s\n", customer->email);
    printf("Phone: %s\n", customer->phone);
    printf("Number of accounts: %d\n", customer->num_accounts);
    for (int j = 0; j < customer->num_accounts; j++) {
      printf("Account %d: %d\n", j, customer->account_ids[j]);
    }
  }
}

int main() {
  Customer customers[MAX_CUSTOMERS];
  int num_customers = 0;
  int num_accounts = 0;

  // Add customers and accounts
  for (int i = 0; i < 3; i++) {
    add_customer(customers, &num_customers);
    for (int j = 0; j < 2; j++) {
      add_account(customers, &num_customers, &num_accounts);
    }
  }

  // Print customer details
  print_customer(customers, &num_customers);

  return 0;
}