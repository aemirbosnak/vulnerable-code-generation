//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  char name[50];
  int accountNum;
  float balance;
} Record;

int readInput(Record records[]);
void displayRecords(Record records[], int numRecords);
void modifyRecord(Record records[], int numRecords);

int main() {
  Record records[MAX_RECORDS];
  int numRecords = readInput(records);

  int choice;
  do {
    printf("\n1. Display all records\n2. Modify a record\n3. Exit\n> ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        displayRecords(records, numRecords);
        break;
      case 2:
        modifyRecord(records, numRecords);
        break;
      case 3:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 3);

  return 0;
}

int readInput(Record records[]) {
  int numRecords;
  do {
    printf("Enter number of records (max %d): ", MAX_RECORDS);
    scanf("%d", &numRecords);
  } while (numRecords < 1 || numRecords > MAX_RECORDS);

  for (int i = 0; i < numRecords; i++) {
    printf("\nEnter record %d:\nName: ", i+1);
    scanf("%s", records[i].name);
    printf("Account number: ");
    scanf("%d", &records[i].accountNum);
    printf("Balance: ");
    scanf("%f", &records[i].balance);
  }

  return numRecords;
}

void displayRecords(Record records[], int numRecords) {
  printf("\nBanking Records:\n");
  for (int i = 0; i < numRecords; i++) {
    printf("Record %d:\nName: %s\nAccount number: %d\nBalance: $%.2f\n\n",
            i+1, records[i].name, records[i].accountNum, records[i].balance);
  }
}

void modifyRecord(Record records[], int numRecords) {
  int accountNum, index = -1;
  printf("\nEnter account number to modify: ");
  scanf("%d", &accountNum);

  for (int i = 0; i < numRecords; i++) {
    if (records[i].accountNum == accountNum) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Record not found.\n");
    return;
  }

  printf("Enter new balance for %s: ", records[index].name);
  scanf("%f", &records[index].balance);
  printf("Record updated.\n");
}