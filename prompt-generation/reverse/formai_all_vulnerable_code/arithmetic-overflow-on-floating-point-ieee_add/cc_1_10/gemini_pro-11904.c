//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char name[50];
  double balance;
};

struct bank {
  char name[50];
  int num_accounts;
  struct account accounts[100];
};

int main() {
  struct bank bank1 = {"First National Bank", 0};
  char input[100];
  int choice;
  double amount;
  int account_num;
  while (1) {
    printf("1. Create account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Print account balance\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter your name: ");
        scanf("%s", bank1.accounts[bank1.num_accounts].name);
        printf("Enter your initial deposit: ");
        scanf("%lf", &bank1.accounts[bank1.num_accounts].balance);
        bank1.num_accounts++;
        break;
      case 2:
        printf("Enter your account number: ");
        scanf("%d", &account_num);
        printf("Enter the amount you want to deposit: ");
        scanf("%lf", &amount);
        bank1.accounts[account_num].balance += amount;
        break;
      case 3:
        printf("Enter your account number: ");
        scanf("%d", &account_num);
        printf("Enter the amount you want to withdraw: ");
        scanf("%lf", &amount);
        if (amount <= bank1.accounts[account_num].balance) {
          bank1.accounts[account_num].balance -= amount;
        } else {
          printf("Insufficient funds\n");
        }
        break;
      case 4:
        printf("Enter your account number: ");
        scanf("%d", &account_num);
        printf("Your account balance is: %.2lf\n", bank1.accounts[account_num].balance);
        break;
      case 5:
        exit(0);
    }
  }
  return 0;
}