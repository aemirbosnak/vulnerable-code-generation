//FormAI DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct Account {
  int accountNumber;
  char name[50];
  float balance;
};

void printMenu();
void addAccount(struct Account accounts[MAX_RECORDS], int *numAccounts);
void displayAccount(struct Account account);
void displayAllAccounts(struct Account accounts[MAX_RECORDS], int numAccounts);
int findAccount(struct Account accounts[MAX_RECORDS], int numAccounts, int accountNumber);
void deposit(struct Account accounts[MAX_RECORDS], int numAccounts, int accountNumber);
void withdraw(struct Account accounts[MAX_RECORDS], int numAccounts, int accountNumber);
void deleteAccount(struct Account accounts[MAX_RECORDS], int *numAccounts, int accountNumber);

int main() {
  struct Account accounts[MAX_RECORDS];
  int numAccounts = 0;
  int choice;

  do {
    printMenu();
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: addAccount(accounts, &numAccounts); break;
      case 2: displayAllAccounts(accounts, numAccounts); break;
      case 3: {
          int accountNumber;
          printf("\nEnter account number: ");
          scanf("%d", &accountNumber);
          int index = findAccount(accounts, numAccounts, accountNumber);
          if (index >= 0) {
            displayAccount(accounts[index]);
          } else {
            printf("\nAccount not found.\n");
          }
          break;
      }
      case 4: {
          int accountNumber;
          printf("\nEnter account number: ");
          scanf("%d", &accountNumber);
          int index = findAccount(accounts, numAccounts, accountNumber);
          if (index >= 0) {
            deposit(accounts, numAccounts, accountNumber);
          } else {
            printf("\nAccount not found.\n");
          }
          break;
      }
      case 5: {
          int accountNumber;
          printf("\nEnter account number: ");
          scanf("%d", &accountNumber);
          int index = findAccount(accounts, numAccounts, accountNumber);
          if (index >= 0) {
            withdraw(accounts, numAccounts, accountNumber);
          } else {
            printf("\nAccount not found.\n");
          }
          break;
      }
      case 6: {
          int accountNumber;
          printf("\nEnter account number: ");
          scanf("%d", &accountNumber);
          int index = findAccount(accounts, numAccounts, accountNumber);
          if (index >= 0) {
            deleteAccount(accounts, &numAccounts, accountNumber);
          } else {
            printf("\nAccount not found.\n");
          }
          break;
      }
      case 7: printf("\nExiting program.\n"); break;
      default: printf("\nInvalid choice.\n"); break;
    }
  } while (choice != 7);

  return 0;
}

void printMenu() {
  printf("\nMain Menu\n");
  printf("1. Add account\n");
  printf("2. Display all accounts\n");
  printf("3. Display account\n");
  printf("4. Deposit\n");
  printf("5. Withdraw\n");
  printf("6. Delete account\n");
  printf("7. Exit\n");
}

void addAccount(struct Account accounts[MAX_RECORDS], int *numAccounts) {
  if (*numAccounts >= MAX_RECORDS) {
    printf("\nCannot add another account. Maximum number of accounts reached.\n");
    return;
  }

  printf("\nEnter account number: ");
  scanf("%d", &accounts[*numAccounts].accountNumber);
  for (int i = 0; i < *numAccounts; i++) {
    if (accounts[i].accountNumber == accounts[*numAccounts].accountNumber) {
      printf("\nAccount number already exists. Account not added.\n");
      return;
    }
  }

  printf("Enter name: ");
  scanf("%s", accounts[*numAccounts].name);
  printf("Enter balance: ");
  scanf("%f", &accounts[*numAccounts].balance);

  (*numAccounts)++;
}

void displayAccount(struct Account account) {
  printf("\nAccount Number: %d", account.accountNumber);
  printf("\nName: %s", account.name);
  printf("\nBalance: %.2f\n", account.balance);
}

void displayAllAccounts(struct Account accounts[MAX_RECORDS], int numAccounts) {
  if (numAccounts > 0) {
    printf("\nAll Accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
      displayAccount(accounts[i]);
    }
  } else {
    printf("\nNo accounts to display.\n");
  }
}

int findAccount(struct Account accounts[MAX_RECORDS], int numAccounts, int accountNumber) {
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accountNumber == accountNumber) {
      return i;
    }
  }
  return -1;
}

void deposit(struct Account accounts[MAX_RECORDS], int numAccounts, int accountNumber) {
  int index = findAccount(accounts, numAccounts, accountNumber);
  if (index >= 0) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    accounts[index].balance += amount;
    printf("\nAmount deposited successfully.\n");
  } else {
    printf("\nAccount not found.\n");
  }
}

void withdraw(struct Account accounts[MAX_RECORDS], int numAccounts, int accountNumber) {
  int index = findAccount(accounts, numAccounts, accountNumber);
  if (index >= 0) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > accounts[index].balance) {
      printf("\nInsufficient funds.\n");
    } else {
      accounts[index].balance -= amount;
      printf("\nAmount withdrawn successfully.\n");
    }
  } else {
    printf("\nAccount not found.\n");
  }
}

void deleteAccount(struct Account accounts[MAX_RECORDS], int *numAccounts, int accountNumber) {
  int index = findAccount(accounts, *numAccounts, accountNumber);
  if (index >= 0) {
    for (int i = index; i < *numAccounts - 1; i++) {
      accounts[i] = accounts[i + 1];
    }
    (*numAccounts)--;
    printf("\nAccount deleted successfully.\n");
  } else {
    printf("\nAccount not found.\n");
  }
}