//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char name[100];
  int account_number;
  int balance;
};

int main() {
  struct account accounts[100];
  int num_accounts = 0;

  while (1) {
    printf("1. Create account\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Print account\n6. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter name: ");
        scanf("%s", accounts[num_accounts].name);
        printf("Enter account number: ");
        scanf("%d", &accounts[num_accounts].account_number);
        printf("Enter balance: ");
        scanf("%d", &accounts[num_accounts].balance);
        num_accounts++;
        break;
      case 2:
        printf("Enter account number: ");
        int account_number;
        scanf("%d", &account_number);
        int index = -1;
        for (int i = 0; i < num_accounts; i++) {
          if (accounts[i].account_number == account_number) {
            index = i;
            break;
          }
        }
        if (index == -1) {
          printf("Account not found\n");
        } else {
          printf("Enter amount to deposit: ");
          int amount;
          scanf("%d", &amount);
          accounts[index].balance += amount;
          printf("New balance: %d\n", accounts[index].balance);
        }
        break;
      case 3:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        index = -1;
        for (int i = 0; i < num_accounts; i++) {
          if (accounts[i].account_number == account_number) {
            index = i;
            break;
          }
        }
        if (index == -1) {
          printf("Account not found\n");
        } else {
          printf("Enter amount to withdraw: ");
          int amount;
          scanf("%d", &amount);
          if (amount > accounts[index].balance) {
            printf("Insufficient funds\n");
          } else {
            accounts[index].balance -= amount;
            printf("New balance: %d\n", accounts[index].balance);
          }
        }
        break;
      case 4:
        printf("Enter account number to transfer from: ");
        int from_account_number;
        scanf("%d", &from_account_number);
        index = -1;
        for (int i = 0; i < num_accounts; i++) {
          if (accounts[i].account_number == from_account_number) {
            index = i;
            break;
          }
        }
        if (index == -1) {
          printf("Account not found\n");
        } else {
          printf("Enter account number to transfer to: ");
          int to_account_number;
          scanf("%d", &to_account_number);
          int to_index = -1;
          for (int i = 0; i < num_accounts; i++) {
            if (accounts[i].account_number == to_account_number) {
              to_index = i;
              break;
            }
          }
          if (to_index == -1) {
            printf("Account not found\n");
          } else {
            printf("Enter amount to transfer: ");
            int amount;
            scanf("%d", &amount);
            if (amount > accounts[index].balance) {
              printf("Insufficient funds\n");
            } else {
              accounts[index].balance -= amount;
              accounts[to_index].balance += amount;
              printf("Transfer successful\n");
            }
          }
        }
        break;
      case 5:
        printf("Enter account number: ");
        scanf("%d", &account_number);
        index = -1;
        for (int i = 0; i < num_accounts; i++) {
          if (accounts[i].account_number == account_number) {
            index = i;
            break;
          }
        }
        if (index == -1) {
          printf("Account not found\n");
        } else {
          printf("Name: %s\n", accounts[index].name);
          printf("Account number: %d\n", accounts[index].account_number);
          printf("Balance: %d\n", accounts[index].balance);
        }
        break;
      case 6:
        exit(0);
    }
  }

  return 0;
}