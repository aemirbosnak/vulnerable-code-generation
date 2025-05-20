//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int account_number;
  double balance;
} customer_t;

void create_account(customer_t *customer) {
  printf("Enter your name: ");
  scanf("%s", customer->name);

  printf("Enter your account number: ");
  scanf("%d", &customer->account_number);

  printf("Enter your initial deposit: ");
  scanf("%lf", &customer->balance);
}

void deposit(customer_t *customer) {
  double amount;
  printf("Enter the amount you want to deposit: ");
  scanf("%lf", &amount);

  customer->balance += amount;
  printf("Your new balance is: %.2lf\n", customer->balance);
}

void withdraw(customer_t *customer) {
  double amount;
  printf("Enter the amount you want to withdraw: ");
  scanf("%lf", &amount);

  if (amount > customer->balance) {
    printf("Insufficient funds\n");
  } else {
    customer->balance -= amount;
    printf("Your new balance is: %.2lf\n", customer->balance);
  }
}

void print_statement(customer_t *customer) {
  printf("Name: %s\n", customer->name);
  printf("Account number: %d\n", customer->account_number);
  printf("Balance: %.2lf\n", customer->balance);
}

int main() {
  int choice;
  customer_t customer;

  do {
    printf("1. Create account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Print statement\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        create_account(&customer);
        break;
      case 2:
        deposit(&customer);
        break;
      case 3:
        withdraw(&customer);
        break;
      case 4:
        print_statement(&customer);
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (1);

  return 0;
}