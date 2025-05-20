//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: portable
// banking_record_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_BALANCE 100000000
#define MAX_ACCOUNT_NUMBER 999999999

typedef struct {
  char name[MAX_NAME_LENGTH];
  int account_number;
  double balance;
} Account;

int main() {
  Account accounts[10];
  int num_accounts = 0;
  char input[MAX_NAME_LENGTH];
  char command;
  int account_number;
  double amount;

  while (1) {
    printf("Enter a command (D/W/S/B): ");
    scanf(" %c", &command);

    switch (command) {
      case 'D':
        printf("Enter account number: ");
        scanf("%d", &account_number);
        if (account_number >= 0 && account_number < 10) {
          printf("Enter name: ");
          scanf("%s", accounts[account_number].name);
          printf("Enter balance: ");
          scanf("%lf", &accounts[account_number].balance);
          num_accounts++;
        } else {
          printf("Invalid account number\n");
        }
        break;
      case 'W':
        printf("Enter account number: ");
        scanf("%d", &account_number);
        if (account_number >= 0 && account_number < 10) {
          printf("Enter amount: ");
          scanf("%lf", &amount);
          accounts[account_number].balance += amount;
        } else {
          printf("Invalid account number\n");
        }
        break;
      case 'S':
        printf("Enter account number: ");
        scanf("%d", &account_number);
        if (account_number >= 0 && account_number < 10) {
          printf("Enter amount: ");
          scanf("%lf", &amount);
          accounts[account_number].balance -= amount;
        } else {
          printf("Invalid account number\n");
        }
        break;
      case 'B':
        for (int i = 0; i < num_accounts; i++) {
          printf("%s\n", accounts[i].name);
          printf("Account number: %d\n", accounts[i].account_number);
          printf("Balance: %lf\n\n", accounts[i].balance);
        }
        break;
      default:
        printf("Invalid command\n");
        break;
    }
  }

  return 0;
}