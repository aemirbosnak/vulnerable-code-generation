//FormAI DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for bank account details
struct BankAccount {
  char name[50];
  char address[100];
  char accountNumber[20];
  char accountType[20];
  double balance;
};

// method to add new account to the bank
void addNewAccount(struct BankAccount *bankAccounts, int *totalAccounts) {
  printf("\nEnter your name: ");
  scanf("%s", bankAccounts[*totalAccounts].name);
  printf("Enter your address: ");
  scanf("%s", bankAccounts[*totalAccounts].address);
  printf("Enter your account number: ");
  scanf("%s", bankAccounts[*totalAccounts].accountNumber);
  printf("Enter your account type: ");
  scanf("%s", bankAccounts[*totalAccounts].accountType);
  printf("Enter your balance: ");
  scanf("%lf", &bankAccounts[*totalAccounts].balance);
  
  (*totalAccounts)++;
  
  printf("\nAccount added successfully!\n");
}

// method to display all the existing accounts in the bank
void displayAccounts(struct BankAccount *bankAccounts, int totalAccounts) {
  printf("\n===================\n");
  printf("Bank Account Details\n");
  printf("===================\n\n");
  
  for (int i = 0; i < totalAccounts; i++) {
    printf("Name: %s\n", bankAccounts[i].name);
    printf("Address: %s\n", bankAccounts[i].address);
    printf("Account Number: %s\n", bankAccounts[i].accountNumber);
    printf("Account Type: %s\n", bankAccounts[i].accountType);
    printf("Balance: %.2lf\n", bankAccounts[i].balance);
    printf("\n");
  }
}

// method to search an account by account number
void searchAccount(struct BankAccount *bankAccounts, int totalAccounts) {
  char accountNumber[20];
  printf("\nEnter the account number: ");
  scanf("%s", accountNumber);
  
  int found = 0;
  
  for (int i = 0; i < totalAccounts; i++) {
    if (strcmp(accountNumber, bankAccounts[i].accountNumber) == 0) {
      printf("\nAccount details found!\n");
      printf("Name: %s\n", bankAccounts[i].name);
      printf("Address: %s\n", bankAccounts[i].address);
      printf("Account Number: %s\n", bankAccounts[i].accountNumber);
      printf("Account Type: %s\n", bankAccounts[i].accountType);
      printf("Balance: %.2lf\n", bankAccounts[i].balance);
      found = 1;
      break;
    }
  }
  
  if (!found) {
    printf("\nAccount not found!\n");
  }
}

// method to update account details by account number
void updateAccount(struct BankAccount *bankAccounts, int totalAccounts) {
  char accountNumber[20];
  printf("\nEnter the account number: ");
  scanf("%s", accountNumber);
  
  int found = 0;
  
  for (int i = 0; i < totalAccounts; i++) {
    if (strcmp(accountNumber, bankAccounts[i].accountNumber) == 0) {
      printf("\nEnter new name: ");
      scanf("%s", bankAccounts[i].name);
      printf("Enter new address: ");
      scanf("%s", bankAccounts[i].address);
      printf("Enter new account type: ");
      scanf("%s", bankAccounts[i].accountType);
      printf("Enter new balance: ");
      scanf("%lf", &bankAccounts[i].balance);
      printf("\nAccount details updated successfully!\n");
      found = 1;
      break;
    }
  }
  
  if (!found) {
    printf("\nAccount not found!\n");
  }
}

// method to delete an account by account number
void deleteAccount(struct BankAccount *bankAccounts, int *totalAccounts) {
  char accountNumber[20];
  printf("\nEnter the account number: ");
  scanf("%s", accountNumber);
  
  int found = 0;
  
  for (int i = 0; i < *totalAccounts; i++) {
    if (strcmp(accountNumber, bankAccounts[i].accountNumber) == 0) {
      for (int j = i; j < *totalAccounts - 1; j++) {
        bankAccounts[j] = bankAccounts[j+1];
      }
      (*totalAccounts)--;
      printf("\nAccount deleted successfully!\n");
      found = 1;
      break;
    }
  }
  
  if (!found) {
    printf("\nAccount not found!\n");
  }
}

int main() {
  int option, totalAccounts = 0;
  struct BankAccount bankAccounts[100];
  
  do {
    printf("\nBanking Record System\n");
    printf("1. Add New Account\n");
    printf("2. Display All Accounts\n");
    printf("3. Search Account by Account Number\n");
    printf("4. Update Account Details\n");
    printf("5. Delete Account by Account Number\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        addNewAccount(bankAccounts, &totalAccounts);
        break;
      case 2:
        displayAccounts(bankAccounts, totalAccounts);
        break;
      case 3:
        searchAccount(bankAccounts, totalAccounts);
        break;
      case 4:
        updateAccount(bankAccounts, totalAccounts);
        break;
      case 5:
        deleteAccount(bankAccounts, &totalAccounts);
        break;
      case 6:
        printf("\nThank you for using the Banking Record System!\n");
        exit(0);
        break;
      default:
        printf("\nInvalid option!\n");
    }
  } while (1);
  
  return 0;
}