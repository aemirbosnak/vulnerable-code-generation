//FormAI DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure declaration for bank account
struct bank_account {
   int account_number;
   char name[30];
   float balance;
};

// Function to create a new account
struct bank_account create_account(int account_number, char* name, float balance) {
   struct bank_account new_account;

   new_account.account_number = account_number;
   strcpy(new_account.name, name);
   new_account.balance = balance;

   return new_account;
}

// Function to print account details
void print_account(struct bank_account account) {
   printf("Account Number: %d\n", account.account_number);
   printf("Name: %s\n", account.name);
   printf("Balance: %.2f\n", account.balance);
}

// Main function
int main() {
   int choice, account_number;
   char name[30];
   float balance;
   struct bank_account accounts[10];
   int num_accounts = 0;
   int i;

   while (1) {
      printf("Menu:\n");
      printf("1. Create new account\n");
      printf("2. Print all accounts\n");
      printf("3. Search for account\n");
      printf("4. Exit\n");

      printf("Enter choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            if (num_accounts == 10) {
               printf("Cannot create more accounts\n");
            } else {
               printf("Enter account number: ");
               scanf("%d", &account_number);
               getchar(); // eat up the \n character
               printf("Enter name: ");
               fgets(name, 30, stdin);
               name[strlen(name) - 1] = '\0'; // remove the \n character
               printf("Enter balance: ");
               scanf("%f", &balance);

               accounts[num_accounts] = create_account(account_number, name, balance);
               num_accounts++;
            }
            break;
         case 2:
            for (i = 0; i < num_accounts; i++) {
               printf("Account %d:\n", i + 1);
               print_account(accounts[i]);
            }
            break;
         case 3:
            printf("Enter account number to search for: ");
            scanf("%d", &account_number);
            for (i = 0; i < num_accounts; i++) {
               if (accounts[i].account_number == account_number) {
                  printf("Account found!\n");
                  print_account(accounts[i]);
                  break;
               }
            }
            if (i == num_accounts) {
               printf("Account not found\n");
            }
            break;
         case 4:
            printf("Exiting program...\n");
            exit(0);
         default:
            printf("Invalid choice\n");
      }
   }

   return 0;
}