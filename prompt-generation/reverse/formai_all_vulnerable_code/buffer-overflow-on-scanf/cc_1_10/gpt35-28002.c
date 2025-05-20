//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
  int account_number;
  char account_name[50];
  float balance;
};

struct Transaction {
  int transaction_id;
  int account_number;
  char transaction_date[10];
  float amount;
  char transaction_type[10];
};

struct Account accounts[100];
struct Transaction transactions[500];
int num_accounts = 0;
int num_transactions = 0;

void add_account() {
  struct Account new_account;
  printf("Enter account number: ");
  scanf("%d", &new_account.account_number);
  printf("Enter account name: ");
  scanf("%s", new_account.account_name);
  printf("Enter initial balance: ");
  scanf("%f", &new_account.balance);
  accounts[num_accounts++] = new_account;
  printf("Account added!\n");
}

void deposit() {
  int account_number;
  printf("Enter account number: ");
  scanf("%d", &account_number);
  float amount;
  printf("Enter amount to deposit: ");
  scanf("%f", &amount);
  for(int i = 0; i < num_accounts; i++) {
    if(accounts[i].account_number == account_number) {
      accounts[i].balance += amount;
      struct Transaction new_transaction;
      new_transaction.transaction_id = num_transactions++;
      new_transaction.account_number = account_number;
      strcpy(new_transaction.transaction_date, "Today");
      new_transaction.amount = amount;
      strcpy(new_transaction.transaction_type, "Deposit");
      transactions[num_transactions-1] = new_transaction;
      printf("Amount deposited!\n");
      return;
    }
  }
  printf("Account not found.\n");
}

void withdraw() {
  int account_number;
  printf("Enter account number: ");
  scanf("%d", &account_number);
  float amount;
  printf("Enter amount to withdraw: ");
  scanf("%f", &amount);
  for(int i = 0; i < num_accounts; i++) {
    if(accounts[i].account_number == account_number) {
      if(accounts[i].balance >= amount) {
        accounts[i].balance -= amount;
        struct Transaction new_transaction;
        new_transaction.transaction_id = num_transactions++;
        new_transaction.account_number = account_number;
        strcpy(new_transaction.transaction_date, "Today");
        new_transaction.amount = amount;
        strcpy(new_transaction.transaction_type, "Withdrawal");
        transactions[num_transactions-1] = new_transaction;
        printf("Amount withdrawn!\n");
        return;
      } else {
        printf("Insufficient balance.\n");
        return;
      }
    }
  }
  printf("Account not found.\n");
}

void display_statement() {
  int account_number;
  printf("Enter account number: ");
  scanf("%d", &account_number);
  printf("\nStatement for Account %d\n", account_number);
  printf("--------------------------------------------\n");
  printf("%-5s %-12s %-12s %-12s %-12s\n", "ID", "Date", "Type", "Amount", "Balance");
  printf("--------------------------------------------\n");
  float balance = 0;
  for(int i = 0; i < num_transactions; i++) {
    if(transactions[i].account_number == account_number) {
      printf("%-5d %-12s %-12s %-12.2f %-12.2f\n", transactions[i].transaction_id, transactions[i].transaction_date, transactions[i].transaction_type, transactions[i].amount, balance);
      if(strcmp(transactions[i].transaction_type, "Deposit") == 0) {
        balance += transactions[i].amount;
      } else {
        balance -= transactions[i].amount;
      }
    }
  }
}

int main() {
  char choice = ' ';
  while(choice != 'X') {
    printf("\n");
    printf("C Bank Record System\n");
    printf("=====================\n");
    printf("1. Add Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Display Statement\n");
    printf("X. Exit\n");
    printf("=====================\n");
    printf("Enter option: ");
    scanf(" %c", &choice);
    switch(choice) {
      case '1': add_account(); break;
      case '2': deposit(); break;
      case '3': withdraw(); break;
      case '4': display_statement(); break;
      case 'X': printf("Goodbye!\n"); break;
      default: printf("Invalid option.\n"); break;
    }
  }
  return 0;
}