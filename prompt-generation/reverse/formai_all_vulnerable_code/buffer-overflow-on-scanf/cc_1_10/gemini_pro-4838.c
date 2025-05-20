//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers
#define MAX_CUSTOMERS 100

// Define the structure of a customer record
typedef struct {
  char name[50];
  char address[100];
  char phone[20];
  double balance;
} customer_record;

// Declare the array of customer records
customer_record customers[MAX_CUSTOMERS];

// Declare the number of customers
int num_customers = 0;

// Function to add a new customer
void add_customer() {
  // Get the customer's name, address, and phone number
  printf("Enter the customer's name: ");
  scanf("%s", customers[num_customers].name);
  printf("Enter the customer's address: ");
  scanf("%s", customers[num_customers].address);
  printf("Enter the customer's phone number: ");
  scanf("%s", customers[num_customers].phone);

  // Set the customer's balance to zero
  customers[num_customers].balance = 0.0;

  // Increment the number of customers
  num_customers++;
}

// Function to deposit money into a customer's account
void deposit_money() {
  // Get the customer's account number
  int account_number;
  printf("Enter the customer's account number: ");
  scanf("%d", &account_number);

  // Get the amount of money to deposit
  double amount;
  printf("Enter the amount of money to deposit: ");
  scanf("%lf", &amount);

  // Deposit the money into the customer's account
  customers[account_number].balance += amount;
}

// Function to withdraw money from a customer's account
void withdraw_money() {
  // Get the customer's account number
  int account_number;
  printf("Enter the customer's account number: ");
  scanf("%d", &account_number);

  // Get the amount of money to withdraw
  double amount;
  printf("Enter the amount of money to withdraw: ");
  scanf("%lf", &amount);

  // Withdraw the money from the customer's account
  customers[account_number].balance -= amount;
}

// Function to print the customer's account statement
void print_statement() {
  // Get the customer's account number
  int account_number;
  printf("Enter the customer's account number: ");
  scanf("%d", &account_number);

  // Print the customer's account statement
  printf("Account number: %d\n", account_number);
  printf("Name: %s\n", customers[account_number].name);
  printf("Address: %s\n", customers[account_number].address);
  printf("Phone number: %s\n", customers[account_number].phone);
  printf("Balance: $%.2f\n", customers[account_number].balance);
}

// Main function
int main() {
  // Add some sample customers
  add_customer();
  add_customer();
  add_customer();

  // Deposit some money into a customer's account
  deposit_money();

  // Withdraw some money from a customer's account
  withdraw_money();

  // Print a customer's account statement
  print_statement();

  return 0;
}