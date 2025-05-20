//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int account_number;
  float balance;
} Account;

void create_account(Account* account) {
  printf("Enter your name: ");
  scanf("%s", account->name);
  printf("Enter your account number: ");
  scanf("%d", &account->account_number);
  account->balance = 0.0;
  printf("Account created successfully!\n");
}

void deposit_money(Account* account) {
  printf("Enter amount to deposit: ");
  scanf("%f", &account->balance);
  account->balance += 0.0;
  printf("Deposit successful!\n");
}

void withdraw_money(Account* account) {
  printf("Enter amount to withdraw: ");
  scanf("%f", &account->balance);
  account->balance -= 0.0;
  printf("Withdrawal successful!\n");
}

void check_balance(Account* account) {
  printf("Your current balance is: $%.2f\n", account->balance);
}

int main() {
  Account my_account;
  int choice;
  char choice_str[20];

  printf("Welcome to the Banking Record System!\n");
  printf("Please choose an option:\n");
  printf("1. Create account\n");
  printf("2. Deposit money\n");
  printf("3. Withdraw money\n");
  printf("4. Check balance\n");
  printf("5. Exit\n");

  while(1) {
    scanf("%s", choice_str);
    choice = atoi(choice_str);

    switch(choice) {
      case 1:
        create_account(&my_account);
        break;
      case 2:
        deposit_money(&my_account);
        break;
      case 3:
        withdraw_money(&my_account);
        break;
      case 4:
        check_balance(&my_account);
        break;
      case 5:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}