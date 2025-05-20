//FormAI DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Define a structure to hold account information
struct account {
   int id;
   char name[30];
   float balance;
};

// Define a function to read account information from keyboard
struct account readAccount() {
   struct account acc;
   printf("Enter account ID: "); scanf("%d", &(acc.id));
   printf("Enter account name: "); scanf("%s", acc.name);
   printf("Enter account balance: "); scanf("%f", &(acc.balance));
   return acc;
}

// Define a function to display account information on screen
void printAccount(struct account acc) {
  printf("\n== Account Information ==\n");
  printf("ID: %d\n", acc.id);
  printf("Name: %s\n", acc.name);
  printf("Balance: %.2f\n", acc.balance);
}

// Define a function to search for an account by ID
struct account findAccountByID(struct account* accounts, int n, int id) {
   int i;
   for (i = 0; i < n; ++i) {
      if (accounts[i].id == id) {
         return accounts[i];
      }
   }
   struct account notFound = { -1, "", 0.0 };
   return notFound;
}

// Define a function to sort accounts by ID
void sortAccountsByID(struct account *accounts, int n) {
   int i, j;
   for (i = 0; i < n; ++i) {
      for (j = i + 1; j < n; ++j) {
         if (accounts[i].id > accounts[j].id) {
            struct account temp = accounts[i];
            accounts[i] = accounts[j];
            accounts[j] = temp;
         }
      }
   }
}

int main() {
   int n, i, id;
   // Read number of accounts from keyboard
   printf("Enter number of accounts: ");
   scanf("%d", &n);
   // Allocate memory to hold account information
   struct account *accounts = (struct account*) malloc(n * sizeof(struct account));
   // Read account information from keyboard
   for (i = 0; i < n; ++i) {
      accounts[i] = readAccount();
      printf("==========================\n");
   }
   // Sort accounts by ID
   sortAccountsByID(accounts, n);
   // Print all accounts
   printf("All accounts:\n");
   for (i = 0; i < n; ++i) {
      printAccount(accounts[i]);
   }
   // Ask user to search for an account
   printf("Enter account ID to search: ");
   scanf("%d", &id);
   // Search for account
   struct account acc = findAccountByID(accounts, n, id);
   if (acc.id == -1) {
      printf("Account not found!\n");
   } else {
      printAccount(acc);
   }
   // Free memory
   free(accounts);
   return 0;
}