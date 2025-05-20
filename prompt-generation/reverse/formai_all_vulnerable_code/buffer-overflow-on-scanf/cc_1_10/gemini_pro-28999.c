//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int acc_no;
  double balance;
} account;

account accounts[100];
int num_accounts = 0;

void create_account() {
  printf("Enter name: ");
  scanf("%s", accounts[num_accounts].name);
  printf("Enter account number: ");
  scanf("%d", &accounts[num_accounts].acc_no);
  printf("Enter balance: ");
  scanf("%lf", &accounts[num_accounts].balance);
  num_accounts++;
}


void withdraw_money() {
  int acc_no;
  double amount;
  printf("Enter account number: ");
  scanf("%d", &acc_no);
  printf("Enter amount to withdraw: ");
  scanf("%lf", &amount);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].acc_no == acc_no) {
      if (accounts[i].balance >= amount) {
        accounts[i].balance -= amount;
        printf("Withdrawal successful!\n");
      } else {
        printf("Insufficient balance!\n");
      }
      return;
    }
  }
  printf("Account not found!\n");
}


void deposit_money() {
  int acc_no;
  double amount;
  printf("Enter account number: ");
  scanf("%d", &acc_no);
  printf("Enter amount to deposit: ");
  scanf("%lf", &amount);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].acc_no == acc_no) {
      accounts[i].balance += amount;
      printf("Deposit successful!\n");
      return;
    }
  }
  printf("Account not found!\n");
}


void display_accounts() {
  printf("----------------------------------------\n");
  printf("Account Name     Account Number    Balance\n");
  printf("----------------------------------------\n");
  for (int i = 0; i < num_accounts; i++) {
    printf("%-15s", accounts[i].name);
    printf("%-15d", accounts[i].acc_no);
    printf("%-15lf\n", accounts[i].balance);
  }
  printf("----------------------------------------\n");
}


int main() {
  int choice;
  do {
    printf("1. Create account\n");
    printf("2. Withdraw money\n");
    printf("3. Deposit money\n");
    printf("4. Display accounts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        create_account();
        break;
      case 2:
        withdraw_money();
        break;
      case 3:
        deposit_money();
        break;
      case 4:
        display_accounts();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);
  return 0;
}