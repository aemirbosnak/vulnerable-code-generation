//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct bankRecord {
   char name[50];
   int accountNumber;
   float balance;
} records[100];

int recordCount = 0;

void addRecord() {
   if(recordCount >= 100) {
      printf("Record limit reached.\n");
      return;
   }
   
   struct bankRecord newRecord;
   printf("Enter name:\n");
   scanf("%s", &newRecord.name);
   printf("Enter account number:\n");
   scanf("%d", &newRecord.accountNumber);
   printf("Enter balance:\n");
   scanf("%f", &newRecord.balance);
   
   records[recordCount] = newRecord;
   recordCount++;
   
   printf("Record added successfully.\n");
}

void displayRecord() {
   if(recordCount == 0) {
      printf("No records found.\n");
      return;
   }
   
   int accountNumber;
   printf("Enter account number to display:\n");
   scanf("%d", &accountNumber);
   
   for(int i=0; i<recordCount; i++) {
      if(records[i].accountNumber == accountNumber) {
         printf("Name: %s\n", records[i].name);
         printf("Account Number: %d\n", records[i].accountNumber);
         printf("Balance: %.2f\n", records[i].balance);
         return;
      }
   }
   
   printf("No record found with account number %d.\n", accountNumber);
}

void deposit() {
   if(recordCount == 0) {
      printf("No records found.\n");
      return;
   }
   
   int accountNumber, amount;
   printf("Enter account number to deposit to:\n");
   scanf("%d", &accountNumber);
   
   for(int i=0; i<recordCount; i++) {
      if(records[i].accountNumber == accountNumber) {
         printf("Enter amount to deposit:\n");
         scanf("%d", &amount);
         records[i].balance += amount;
         printf("Deposit successful. New balance: %.2f\n", records[i].balance);
         return;
      }
   }
   
   printf("No record found with account number %d.\n", accountNumber);
}

void withdraw() {
   if(recordCount == 0) {
      printf("No records found.\n");
      return;
   }
   
   int accountNumber, amount;
   printf("Enter account number to withdraw from:\n");
   scanf("%d", &accountNumber);
   
   for(int i=0; i<recordCount; i++) {
      if(records[i].accountNumber == accountNumber) {
         printf("Enter amount to withdraw:\n");
         scanf("%d", &amount);
         if(records[i].balance < amount) {
            printf("Insufficient balance.\n");
            return;
         }
         records[i].balance -= amount;
         printf("Withdrawal successful. New balance: %.2f\n", records[i].balance);
         return;
      }
   }
   
   printf("No record found with account number %d.\n", accountNumber);
}

int main() {
   int choice;
   
   while(1) {
      printf("\nBanking Record System\n");
      printf("----------------------\n");
      printf("1. Add record\n");
      printf("2. Display record\n");
      printf("3. Deposit\n");
      printf("4. Withdraw\n");
      printf("5. Exit\n");
      printf("Enter your choice:\n");
      
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            addRecord();
            break;
         case 2:
            displayRecord();
            break;
         case 3:
            deposit();
            break;
         case 4:
            withdraw();
            break;
         case 5:
            exit(0);
         default:
            printf("Invalid choice.\n");
      }
   }
   
   return 0;
}