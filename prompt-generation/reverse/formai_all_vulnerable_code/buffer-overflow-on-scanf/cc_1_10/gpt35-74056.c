//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a structure to store account information
struct account {
  char name[100];
  int accNumber;
  float balance;
};

//Declare global variables
int numAccounts = 0; //number of accounts in the system
struct account accounts[100]; //array to store account information

//Function to add a new account
void addAccount() {
  printf("\nAdding new account...\n");

  //Get account information from user
  printf("Enter name: ");
  scanf("%s", accounts[numAccounts].name);
  printf("Enter account number: ");
  scanf("%d", &accounts[numAccounts].accNumber);
  printf("Enter opening balance: ");
  scanf("%f", &accounts[numAccounts].balance);

  numAccounts++;

  //Notify user of successful addition
  printf("\nAccount added successfully!\n\n");
}

//Function to view account information
void viewAccount() {
  printf("\nViewing account information...\n");

  //Get account number from user
  int accNumber;
  printf("Enter account number: ");
  scanf("%d", &accNumber);

  //Search for account in the array
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accNumber == accNumber) {
      //Display account information
      printf("Name: %s\n", accounts[i].name);
      printf("Account Number: %d\n", accounts[i].accNumber);
      printf("Balance: %.2f\n\n", accounts[i].balance);
      return;
    }
  }

  //Notify user if account is not found
  printf("Account not found.\n\n");
}

//Function to make a deposit
void deposit() {
  printf("\nMaking a deposit...\n");

  //Get account number from user
  int accNumber;
  printf("Enter account number: ");
  scanf("%d", &accNumber);

  //Search for account in the array
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accNumber == accNumber) {
      //Get deposit amount from user and add to balance
      float depositAmount;
      printf("Enter deposit amount: ");
      scanf("%f", &depositAmount);
      accounts[i].balance += depositAmount;

      //Notify user of successful deposit
      printf("\nDeposit successful!\n\n");
      return;
    }
  }

  //Notify user if account is not found
  printf("Account not found.\n\n");
}

//Function to make a withdrawal
void withdraw() {
  printf("\nMaking a withdrawal...\n");

  //Get account number from user
  int accNumber;
  printf("Enter account number: ");
  scanf("%d", &accNumber);

  //Search for account in the array
  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accNumber == accNumber) {
      //Get withdrawal amount from user and subtract from balance
      float withdrawAmount;
      printf("Enter withdrawal amount: ");
      scanf("%f", &withdrawAmount);
      if (withdrawAmount > accounts[i].balance) {
        //Notify user if withdrawal amount is greater than balance
        printf("\nInsufficient funds!\n\n");
      } else {
        accounts[i].balance -= withdrawAmount;
        //Notify user of successful withdrawal
        printf("\nWithdrawal successful!\n\n");
      }
      return;
    }
  }

  //Notify user if account is not found
  printf("Account not found.\n\n");
}

//Function to display all accounts
void displayAll() {
  printf("\nDisplaying all accounts...\n");

  //Loop through array and display account information for each account
  for (int i = 0; i < numAccounts; i++) {
    printf("Name: %s\n", accounts[i].name);
    printf("Account Number: %d\n", accounts[i].accNumber);
    printf("Balance: %.2f\n\n", accounts[i].balance);
  }
}

//Main function
int main() {
  int choice;

  while (1) {
    //Display menu and get user choice
    printf("Banking Record System\n");
    printf("======================\n");
    printf("1. Add account\n");
    printf("2. View account information\n");
    printf("3. Make a deposit\n");
    printf("4. Make a withdrawal\n");
    printf("5. Display all accounts\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    //Perform selected action
    switch (choice) {
      case 1:
        addAccount();
        break;
      case 2:
        viewAccount();
        break;
      case 3:
        deposit();
        break;
      case 4:
        withdraw();
        break;
      case 5:
        displayAll();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n\n");
    }
  }

  return 0;
}