//FormAI DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the structure of the bank records
struct bankRecord {
  char name[50];
  int accountNo;
  float balance;
};

// function to add a new record to the bank system
struct bankRecord* addRecord() {
  printf("\nEnter Account Holder Name: ");
  char name[50];
  scanf(" %[^\n]s", name);

  printf("Enter Account Number: ");
  int accNum;
  scanf("%d", &accNum);

  printf("Enter Initial Balance: ");
  float bal;
  scanf("%f", &bal);

  struct bankRecord *newRecord = malloc(sizeof(struct bankRecord));
  strcpy(newRecord->name, name);
  newRecord->accountNo = accNum;
  newRecord->balance = bal;

  printf("\nRecord Added Successfully!\n");

  return newRecord;
}

// function to display all records in the bank system
void displayAllRecords(struct bankRecord **records, int numOfRecords) {
  printf("\nName\tAccount No\tBalance\n");

  for (int i = 0; i < numOfRecords; i++) {
    printf("%s\t%d\t%.2f\n", records[i]->name, records[i]->accountNo, records[i]->balance);
  }
  printf("\n");
}

// function to search for a record using account number and display its details
void searchRecord(struct bankRecord **records, int numOfRecords) {
  printf("\nEnter Account Number to Search: ");
  int accNumToSearch;
  scanf("%d", &accNumToSearch);

  int foundRecord = 0;

  for (int i = 0; i < numOfRecords; i++) {
    if (records[i]->accountNo == accNumToSearch) {
      foundRecord = 1;
      printf("\nName: %s\n", records[i]->name);
      printf("Account Number: %d\n", records[i]->accountNo);
      printf("Balance: %.2f\n\n", records[i]->balance);
      break;
    }
  }

  if (!foundRecord) {
    printf("\nRecord Not Found!\n\n");
  }
}

int main() {
  int option, numOfRecords = 0, maxRecords = 10;

  printf("\nWelcome to the ABC Banking Record System\n\n");

  // array of pointer to structures to store bank records
  struct bankRecord **records = malloc(maxRecords * sizeof(struct bankRecord *));

  while (1) {
    printf("Choose an Option:\n");
    printf("1. Add New Record\n");
    printf("2. Display All Records\n");
    printf("3. Search for a Record\n");
    printf("4. Exit Program\n");

    scanf("%d", &option);

    switch (option) {
      case 1:
        if (numOfRecords == maxRecords) {
          printf("\nMaximum Capacity Reached!\n\n");
          break;
        }
        records[numOfRecords++] = addRecord();
        break;

      case 2:
        displayAllRecords(records, numOfRecords);
        break;

      case 3:
        searchRecord(records, numOfRecords);
        break;

      case 4:
        printf("\nExiting ABC Banking Record System...\n\n");
        exit(0);

      default:
        printf("\nInvalid Option Selected! Please Try Again.\n\n");
    }
  }

  return 0;
}