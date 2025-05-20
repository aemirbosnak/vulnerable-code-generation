//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct customer {
   char name[50];
   int accountNum;
   float balance;
};

void printMenu() {
   printf("Welcome to the Banking Record System!\n----------------------------------------------------\n");
   printf("1. View Account Details\n");
   printf("2. Deposit Money into Account\n");
   printf("3. Withdraw Money from Account\n");
   printf("4. Exit\n");
   printf("Please enter your choice: ");
}

int main() {
   int customerCount = 0, menuChoice = 0, accountNum = 0;
   float depositAmount = 0.0, withdrawAmount = 0.0;
   char name[50];
   struct customer customers[100];

   printf("Banking Record System Initializing...\n");

   while (menuChoice != 4) {
      printMenu();
      scanf("%d", &menuChoice);

      switch(menuChoice) {
         case 1:
            printf("Enter account number: ");
            scanf("%d", &accountNum);
            for (int i=0; i<customerCount; i++) {
               if (customers[i].accountNum == accountNum) {
                  printf("\nAccount Details\n-------------------------\n");
                  printf("Name: %s\n", customers[i].name);
                  printf("Account Number: %d\n", customers[i].accountNum);
                  printf("Balance: $%.2f\n", customers[i].balance);
                  break;
               }
               if (i == customerCount - 1) {
                  printf("Customer with account number %d not found!\n", accountNum);
               }
            }
            break;
         case 2:
            printf("Enter account number: ");
            scanf("%d", &accountNum);
            for (int i=0; i<customerCount; i++) {
               if (customers[i].accountNum == accountNum) {
                  printf("Enter deposit amount: ");
                  scanf("%f", &depositAmount);
                  customers[i].balance += depositAmount;
                  printf("Deposit successful!\n");
                  printf("New balance for account number %d is: $%.2f\n", customers[i].accountNum, customers[i].balance);
                  break;
               }
               if (i == customerCount - 1) {
                  printf("Customer with account number %d not found!\n", accountNum);
               }
            }
            break;
         case 3:
            printf("Enter account number: ");
            scanf("%d", &accountNum);
            for (int i=0; i<customerCount; i++) {
               if (customers[i].accountNum == accountNum) {
                  printf("Enter withdraw amount: ");
                  scanf("%f", &withdrawAmount);
                  if (customers[i].balance >= withdrawAmount) {
                     customers[i].balance -= withdrawAmount;
                     printf("Withdrawal successful!\n");
                     printf("New balance for account number %d is: $%.2f\n", customers[i].accountNum, customers[i].balance);

                  } else {
                     printf("Insufficient balance!\n");
                  }
                  break;
               }
               if (i == customerCount - 1) {
                  printf("Customer with account number %d not found!\n", accountNum);
               }
            }
            break;
         case 4:
            printf("Exiting Banking Record System...\n");
            exit(0);
         default:
            printf("Invalid selection.\n");
            break;
      }
   }
   return 0;
}