//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defining structure for account details
typedef struct account {
   char name[30];
   int acc_no;
   float balance;
} Account;

// Function to add new account
void add_account(Account **customers, int *num_customers) {
   // Creating space for new account
   *customers = realloc(*customers, (*num_customers + 1) * sizeof(Account));

   // Getting details for new account
   printf("Enter name of account holder: ");
   scanf("%s", (*customers)[*num_customers].name);
   printf("Enter account number: ");
   scanf("%d", &(*customers)[*num_customers].acc_no);
   printf("Enter opening balance: ");
   scanf("%f", &(*customers)[*num_customers].balance);

   // Updating number of customers
   *num_customers += 1;
}

// Function to display account details
void display_accounts(Account *customers, int num_customers) {
   printf("-------------------------------------------\n");
   printf("|         NAME         | ACC NO. | BALANCE |\n");
   printf("-------------------------------------------\n");

   // Looping through all customers
   for (int i = 0; i < num_customers; i++) {
      printf("| %-20s | %6d | %7.2f |\n", customers[i].name, customers[i].acc_no, customers[i].balance);
   }

   printf("-------------------------------------------\n");
}

// Function to deposit money
void deposit_money(Account *customers, int num_customers) {
   int acc_no;
   float amount;

   printf("Enter account number: ");
   scanf("%d", &acc_no);
   printf("Enter amount to deposit: ");
   scanf("%f", &amount);

   // Looping through all customers and adding deposited amount to corresponding customer's account
   for (int i = 0; i < num_customers; i++) {
      if (customers[i].acc_no == acc_no) {
         customers[i].balance += amount;
         printf("Amount deposited successfully\n");
         printf("New balance for account %d: %.2f\n", acc_no, customers[i].balance);
         return;
      }
   }

   printf("Account not found\n");
}

// Function to withdraw money
void withdraw_money(Account *customers, int num_customers) {
   int acc_no;
   float amount;

   printf("Enter account number: ");
   scanf("%d", &acc_no);
   printf("Enter amount to withdraw: ");
   scanf("%f", &amount);

   // Looping through all customers and subtracting withdrawn amount from corresponding customer's account
   for (int i = 0; i < num_customers; i++) {
      if (customers[i].acc_no == acc_no) {
         if (amount > customers[i].balance) {
            printf("Insufficient balance\n");
            return;
         }

         customers[i].balance -= amount;
         printf("Amount withdrawn successfully\n");
         printf("New balance for account %d: %.2f\n", acc_no, customers[i].balance);
         return;
      }
   }

   printf("Account not found\n");
}

// Function to delete account
void delete_account(Account **customers, int *num_customers) {
   int acc_no;

   printf("Enter account number: ");
   scanf("%d", &acc_no);

   // Looping through all customers and deleting corresponding customer's account
   for (int i = 0; i < *num_customers; i++) {
      if ((*customers)[i].acc_no == acc_no) {
         for (int j = i; j < (*num_customers - 1); j++) {
            (*customers)[j] = (*customers)[j + 1];
         }

         *customers = realloc(*customers, (*num_customers - 1) * sizeof(Account));
         *num_customers -= 1;

         printf("Account deleted successfully\n");
         return;
      }
   }

   printf("Account not found\n");
}

int main() {
   int num_customers = 0;
   Account *customers = NULL;

   int choice;

   do {
      printf("\n");
      printf("1. Add account\n");
      printf("2. Display accounts\n");
      printf("3. Deposit money\n");
      printf("4. Withdraw money\n");
      printf("5. Delete account\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            add_account(&customers, &num_customers);
            break;

         case 2:
            display_accounts(customers, num_customers);
            break;

         case 3:
            deposit_money(customers, num_customers);
            break;

         case 4:
            withdraw_money(customers, num_customers);
            break;

         case 5:
            delete_account(&customers, &num_customers);
            break;

         case 6:
            printf("Exiting...\n");
            break;

         default:
            printf("Invalid choice\n");
      }
   } while (choice != 6);

   return 0;
}