//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
// Welcome to the Banking Record System
// This program allows you to keep track of multiple bank accounts
// Are you ready to begin? 

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the bank account
struct bank_account {
   char account_name[20];
   int account_number;
   float balance;
};

// Function to add a new account to the system
void add_account(struct bank_account *accounts, int num_accounts) {
   printf("Enter the account name: ");
   scanf("%s", accounts[num_accounts].account_name);
   printf("Enter the account number: ");
   scanf("%d", &accounts[num_accounts].account_number);
   printf("Enter the initial balance: ");
   scanf("%f", &accounts[num_accounts].balance);
   printf("New account successfully added!\n");
}

// Function to display all accounts in the system
void display_all(struct bank_account *accounts, int num_accounts) {
   if (num_accounts == 0) {
       printf("No accounts in the system.\n");
   } else {
       for (int i = 0; i < num_accounts; i++) {
           printf("%s (%d) - $%.2f\n", accounts[i].account_name, accounts[i].account_number, accounts[i].balance);
       }
   }
}

int main(void) {

   // Initialize variables
   int num_accounts = 0;
   int choice = 0;
   struct bank_account accounts[10];

   // Welcome message
   printf("Welcome to the Banking Record System!\n");

   // Main program loop
   while (choice != 3) {

       // Display menu options
       printf("\nPlease choose an option: \n");
       printf("1. Add a new account\n");
       printf("2. View all accounts\n");
       printf("3. Exit\n");
       scanf("%d", &choice);

       // Determine choice and perform action
       switch (choice) {
           case 1:
               add_account(accounts, num_accounts);
               num_accounts++;
               break;
           case 2:
               display_all(accounts, num_accounts);
               break;
           case 3:
               printf("Thank you for using the Banking Record System!\n");
               break;
           default:
               printf("Invalid choice. Please try again.\n");
               break;
       }
   }

   return 0;
}