//FormAI DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char name[50];
  char address[100];
  char phone[15];
  char account_number[10];
  int balance;
};

int main() {
  struct account accounts[100];
  int num_accounts = 0;

  while(1) {
    printf("Welcome to the Bank Record System.\n");
    printf("Please choose an option:\n");
    printf("1. Add an account\n");
    printf("2. Edit an account\n");
    printf("3. Delete an account\n");
    printf("4. View all accounts\n");
    printf("5. Exit\n");

    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
      printf("Please enter name: ");
      scanf("%s", accounts[num_accounts].name);
      printf("Please enter address: ");
      scanf("%s", accounts[num_accounts].address);
      printf("Please enter phone: ");
      scanf("%s", accounts[num_accounts].phone);
      printf("Please enter account number: ");
      scanf("%s", accounts[num_accounts].account_number);
      printf("Please enter starting balance: ");
      scanf("%d", &accounts[num_accounts].balance);
      printf("Account added successfully!\n");
      num_accounts++;
    }
    else if(choice == 2) {
      printf("Please enter account number to edit: ");
      char account_number[10];
      scanf("%s", account_number);

      for(int i=0; i<num_accounts; i++) {
        if(strcmp(account_number, accounts[i].account_number) == 0) {
          printf("Please enter new name: ");
          scanf("%s", accounts[i].name);
          printf("Please enter new address: ");
          scanf("%s", accounts[i].address);
          printf("Please enter new phone: ");
          scanf("%s", accounts[i].phone);
          printf("Please enter new balance: ");
          scanf("%d", &accounts[i].balance);
          printf("Account edited successfully!\n");
          break;
        }
        else if(i == num_accounts-1) {
          printf("Account not found.\n");
        }
      }
    }
    else if(choice == 3) {
      printf("Please enter account number to delete: ");
      char account_number[10];
      scanf("%s", account_number);

      for(int i=0; i<num_accounts; i++) {
        if(strcmp(account_number, accounts[i].account_number) == 0) {
          for(int j=i; j<num_accounts-1; j++) {
            accounts[j] = accounts[j+1];
          }
          num_accounts--;
          printf("Account deleted successfully!\n");
          break;
        }
        else if(i == num_accounts-1) {
          printf("Account not found.\n");
        }
      }
    }
    else if(choice == 4) {
      printf("All accounts:\n");
      for(int i=0; i<num_accounts; i++) {
        printf("----------\n");
        printf("Name: %s\n", accounts[i].name);
        printf("Address: %s\n", accounts[i].address);
        printf("Phone: %s\n", accounts[i].phone);
        printf("Account Number: %s\n", accounts[i].account_number);
        printf("Balance: %d\n", accounts[i].balance);
      }
    }
    else if(choice == 5) {
      printf("Exiting program...\n");
      exit(0);
    }
    else {
      printf("Invalid option. Please try again.\n");
    }
  }

  return 0;
}