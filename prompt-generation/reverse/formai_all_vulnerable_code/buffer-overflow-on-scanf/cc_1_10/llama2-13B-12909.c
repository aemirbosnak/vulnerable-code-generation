//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum amount that can be withdrawn
#define MAX_WITHDRAWAL 1000

// Define the account balance for the user
int balance = 0;

// Function to deposit money into the account
void deposit(int amount) {
  balance += amount;
  printf("Deposited %d into account\n", amount);
}

// Function to withdraw money from the account
void withdraw(int amount) {
  if (amount > balance) {
    printf("Insufficient balance: %d\n", balance);
    return;
  }
  balance -= amount;
  printf("Withdrawn %d from account\n", amount);
}

int main() {
  // Ask the user for their account balance
  printf("Your current balance is: %d\n", balance);

  // Prompt the user to deposit or withdraw
  char command;
  printf("Please enter a command (d for deposit or w for withdraw): ");
  scanf(" %c", &command);

  // Handle the user's command
  if (command == 'd') {
    int amount;
    printf("Enter the amount to deposit: ");
    scanf(" %d", &amount);
    deposit(amount);
  } else if (command == 'w') {
    int amount;
    printf("Enter the amount to withdraw: ");
    scanf(" %d", &amount);
    withdraw(amount);
  } else {
    printf("Invalid command\n");
  }

  // Check for errors
  if (balance < 0) {
    printf("Account balance is negative: %d\n", balance);
  }

  return 0;
}