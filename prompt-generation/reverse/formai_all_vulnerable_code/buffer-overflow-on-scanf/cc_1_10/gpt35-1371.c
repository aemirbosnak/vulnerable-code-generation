//FormAI DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold banking record data
struct bank_record {
  char name[50];
  int account_number;
  double balance;
};

//Function to display main menu
void display_menu() {
  printf("\n*****Banking Record System*****\n\n");
  printf("1. Create Record\n");
  printf("2. Display Records\n");
  printf("3. Search Record\n");
  printf("4. Update Record\n");
  printf("5. Delete Record\n");
  printf("6. Exit\n\n");
  printf("Enter your choice (1-6): ");
}

//Function to create a new record
void create_record(struct bank_record* record) {
  printf("\nEnter name: ");
  scanf("%s", record->name);
  printf("Enter account number: ");
  scanf("%d", &record->account_number);
  printf("Enter balance: ");
  scanf("%lf", &record->balance);
  printf("\nRecord created successfully!\n");
}

//Function to display all records
void display_records(struct bank_record* records, int count) {
  printf("\nAll Records:\n");
  printf("Name\t\tAccount Number\t\tBalance\n");
  printf("----------------------------------------------------\n");
  for (int i = 0; i < count; i++) {
    printf("%s\t\t%d\t\t\t$%.2lf\n", records[i].name, records[i].account_number, records[i].balance);
  }
  printf("\n");
}

//Function to search for a record by account number
void search_record(struct bank_record* records, int count) {
  int account_number;
  printf("\nEnter account number: ");
  scanf("%d", &account_number);
  for (int i = 0; i < count; i++) {
    if (records[i].account_number == account_number) {
      printf("\nRecord Found:\n");
      printf("Name: %s\n", records[i].name);
      printf("Account Number: %d\n", records[i].account_number);
      printf("Balance: $%.2lf\n", records[i].balance);
      return;
    }
  }
  printf("\nRecord not found!\n");
}

//Function to update a record
void update_record(struct bank_record* records, int count) {
  int account_number;
  printf("\nEnter account number: ");
  scanf("%d", &account_number);
  for (int i = 0; i < count; i++) {
    if (records[i].account_number == account_number) {
      printf("\nEnter new balance: ");
      scanf("%lf", &records[i].balance);
      printf("\nRecord updated successfully!\n");
      return;
    }
  }
  printf("\nRecord not found!\n");
}

//Function to delete a record by account number
void delete_record(struct bank_record* records, int* count) {
  int account_number;
  printf("\nEnter account number: ");
  scanf("%d", &account_number);
  for (int i = 0; i < *count; i++) {
    if (records[i].account_number == account_number) {
      for (int j = i; j < *count - 1; j++) {
        records[j] = records[j + 1];
      }
      (*count)--;
      printf("\nRecord deleted successfully!\n");
      return;
    }
  }
  printf("\nRecord not found!\n");
}

int main() {
  int choice, count = 0;
  struct bank_record records[100];
  do {
    display_menu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        if (count < 100) {
          create_record(&records[count]);
          count++;
        }
        else {
          printf("\nMaximum number of records reached!\n");
        }
        break;
      case 2:
        if (count > 0) {
          display_records(records, count);
        }
        else {
          printf("\nNo records found!\n");
        }
        break;
      case 3:
        if (count > 0) {
          search_record(records, count);
        }
        else {
          printf("\nNo records found!\n");
        }
        break;
      case 4:
        if (count > 0) {
          update_record(records, count);
        }
        else {
          printf("\nNo records found!\n");
        }
        break;
      case 5:
        if (count > 0) {
          delete_record(records, &count);
        }
        else {
          printf("\nNo records found!\n");
        }
        break;
      case 6:
        printf("\nThank you for using the Banking Record System!\n");
        break;
      default:
        printf("\nInvalid choice! Please enter a valid choice (1-6).\n");
    }
  } while (choice != 6);
  return 0;
}