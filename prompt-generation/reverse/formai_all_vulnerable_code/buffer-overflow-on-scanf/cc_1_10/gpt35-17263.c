//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct BankRecord {
   char accountNum[10];
   char name[20];
   char address[30];
   char phoneNum[15];
   float balance;
} record[MAX];

int numRecords = 0; // Number of Records Existing

/* Function to Add a Record */
void addRecord() {
   printf("\nEnter Account Number: ");
   scanf("%s", record[numRecords].accountNum);
   printf("Enter Name: ");
   scanf("%s", record[numRecords].name);
   printf("Enter Address: ");
   scanf("%s", record[numRecords].address);
   printf("Enter Phone Number: ");
   scanf("%s", record[numRecords].phoneNum);
   printf("Enter Balance: ");
   scanf("%f", &record[numRecords].balance);
   numRecords++;
   printf("\nRecord Added Successfully!\n");
}

/* Function to View All Records */
void viewRecords() {
   int i;
   if (numRecords == 0) {
      printf("\nNo Records Found!\n");
   } else {
      printf("\n%-15s %-20s %-30s %-15s %-10s\n", "Account Number", "Name", "Address",
             "Phone Number", "Balance");
      for (i = 0; i < numRecords; i++) {
         printf("%-15s %-20s %-30s %-15s $%-9.2f\n", record[i].accountNum, record[i].name,
                record[i].address, record[i].phoneNum, record[i].balance);
      }
   }
}

/* Function to Search Records */
void searchRecord() {
   char accountNum[10];
   int i, recordFound = 0;
   printf("\nEnter Account Number to Search: ");
   scanf("%s", accountNum);
   for (i = 0; i < numRecords; i++) {
      if (strcmp(record[i].accountNum, accountNum) == 0) {
         printf("\n%-15s %-20s %-30s %-15s %-10s\n", "Account Number", "Name", "Address",
                "Phone Number", "Balance");
         printf("%-15s %-20s %-30s %-15s $%-9.2f\n", record[i].accountNum, record[i].name,
                record[i].address, record[i].phoneNum, record[i].balance);
         recordFound = 1;
         break;
      }
   }
   if (recordFound == 0) {
      printf("\nRecord Not Found!\n");
   }
}

int main() {
   int choice;
   printf("\n*** Welcome to Genius Banking Record System ***\n");
   while (1) {
      printf("\n1. Add a Record\n");
      printf("2. View All Records\n");
      printf("3. Search Records\n");
      printf("4. Exit\n");
      printf("\nEnter Your Choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
         addRecord();
         break;
      case 2:
         viewRecords();
         break;
      case 3:
         searchRecord();
         break;
      case 4:
         printf("\nThank You For Using Genius Banking Record System!\n");
         exit(0);
      default:
         printf("\nInvalid Choice! Try Again.\n");
      }
   }
   return 0;
}