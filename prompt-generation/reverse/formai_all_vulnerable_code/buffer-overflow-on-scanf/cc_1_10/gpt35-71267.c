//FormAI DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct bankRecord {
  int accountNumber;
  char accountName[30];
  char accountType[10];
  float accountBalance;
};

void addRecord(struct bankRecord records[], int n) {
  printf("Enter Account Number: ");
  scanf("%d", &records[n].accountNumber);

  printf("Enter Account Name: ");
  scanf("%s", records[n].accountName);

  printf("Enter Account Type (Checking/Savings): ");
  scanf("%s", records[n].accountType);

  printf("Enter Account Balance: ");
  scanf("%f", &records[n].accountBalance);
}

void displayRecord(struct bankRecord record) {
  printf("\nAccount Number: %d", record.accountNumber);
  printf("\nAccount Name: %s", record.accountName);
  printf("\nAccount Type: %s", record.accountType);
  printf("\nAccount Balance: $%.2f\n", record.accountBalance);
}

void displayAllRecords(struct bankRecord records[], int n) {
  for (int i = 0; i < n; i++) {
    displayRecord(records[i]);
  }
}

void searchRecord(struct bankRecord records[], int n, int accountNumber) {
  for (int i = 0; i < n; i++) {
    if (records[i].accountNumber == accountNumber) {
      displayRecord(records[i]);
      return;
    }
  }
  printf("Record not found\n");
}

void updateRecord(struct bankRecord records[], int n, int accountNumber) {
  for (int i = 0; i < n; i++) {
    if (records[i].accountNumber == accountNumber) {
      printf("Enter New Account Name: ");
      scanf("%s", records[i].accountName);

      printf("Enter New Account Type (Checking/Savings): ");
      scanf("%s", records[i].accountType);

      printf("Enter New Account Balance: ");
      scanf("%f", &records[i].accountBalance);

      printf("Record updated\n");
      return;
    }
  }
  printf("Record not found\n");
}

void deleteRecord(struct bankRecord records[], int n, int accountNumber) {
  for (int i = 0; i < n; i++) {
    if (records[i].accountNumber == accountNumber) {
      // Shift all records after i to the left by 1
      for (int j = i; j < n - 1; j++) {
        records[j] = records[j+1];
      }
      printf("Record deleted\n");
      return;
    }
  }
  printf("Record not found\n");
}

int main() {
  int choice, n = 0;
  struct bankRecord records[100];

  printf("===== Banking Record System =====\n");
  while (1) {
    printf("\n1. Add Record\n");
    printf("2. Display Record\n");
    printf("3. Display All Records\n");
    printf("4. Search Record\n");
    printf("5. Update Record\n");
    printf("6. Delete Record\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addRecord(records, n);
        n++;
        break;
      case 2:
        if (n == 0) {
          printf("No records to display\n");
        } else {
          int accountNumber;
          printf("Enter Account Number: ");
          scanf("%d", &accountNumber);
          searchRecord(records, n, accountNumber);
        }
        break;
      case 3:
        if (n == 0) {
          printf("No records to display\n");
        } else {
          displayAllRecords(records, n);
        }
        break;
      case 4:
        if (n == 0) {
          printf("No records to search\n");
        } else {
          int accountNumber;
          printf("Enter Account Number: ");
          scanf("%d", &accountNumber);
          searchRecord(records, n, accountNumber);
        }
        break;
      case 5:
        if (n == 0) {
          printf("No records to update\n");
        } else {
          int accountNumber;
          printf("Enter Account Number: ");
          scanf("%d", &accountNumber);
          updateRecord(records, n, accountNumber);
        }
        break;
      case 6:
        if (n == 0) {
          printf("No records to delete\n");
        } else {
          int accountNumber;
          printf("Enter Account Number: ");
          scanf("%d", &accountNumber);
          deleteRecord(records, n, accountNumber);
          n--;
        }
        break;
      case 7:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}