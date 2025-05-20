//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Data structure for banking record
struct banking_record {
  int account_number;
  char name[50];
  char address[100];
  char phone_number[20];
  long balance;
};

// Function to add a new record
void add_record(struct banking_record records[], int *num_records) {
  // Prompt for user input
  printf("Enter account number: ");
  scanf("%d", &records[*num_records].account_number);

  printf("Enter name: ");
  scanf(" %[^\n]s", records[*num_records].name);

  printf("Enter address: ");
  scanf(" %[^\n]s", records[*num_records].address);

  printf("Enter phone number: ");
  scanf(" %[^\n]s", records[*num_records].phone_number);

  printf("Enter balance: ");
  scanf("%ld", &records[*num_records].balance);

  // Increment the number of records
  *num_records += 1;

  printf("\nRecord added successfully.\n");
}

// Function to view a record
void view_record(struct banking_record records[], int num_records) {
  // Prompt for user input
  int account_number;
  printf("Enter account number: ");
  scanf("%d", &account_number);

  // Find the record with the given account number
  int i;
  for (i = 0; i < num_records; i++) {
    if (records[i].account_number == account_number) {
      // Print the details of the record
      printf("\nAccount number: %d\n", records[i].account_number);
      printf("Name: %s\n", records[i].name);
      printf("Address: %s\n", records[i].address);
      printf("Phone number: %s\n", records[i].phone_number);
      printf("Balance: %ld\n", records[i].balance);
      return;
    }
  }

  printf("\nRecord not found.\n");
}

// Function to modify a record
void modify_record(struct banking_record records[], int num_records) {
  // Prompt for user input
  int account_number;
  printf("Enter account number: ");
  scanf("%d", &account_number);

  // Find the record with the given account number
  int i;
  for (i = 0; i < num_records; i++) {
    if (records[i].account_number == account_number) {
      // Prompt for user input
      printf("Enter name: ");
      scanf(" %[^\n]s", records[i].name);

      printf("Enter address: ");
      scanf(" %[^\n]s", records[i].address);

      printf("Enter phone number: ");
      scanf(" %[^\n]s", records[i].phone_number);

      printf("Enter balance: ");
      scanf("%ld", &records[i].balance);

      printf("\nRecord modified successfully.\n");
      return;
    }
  }

  printf("\nRecord not found.\n");
}

int main() {
  struct banking_record records[100];
  int num_records = 0;

  while (1) {
    // Prompt for user input
    int choice;
    printf("\nSelect an option (1-4):\n");
    printf("1. Add a new record\n");
    printf("2. View a record\n");
    printf("3. Modify a record\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // Perform the selected operation
    switch (choice) {
      case 1:
        add_record(records, &num_records);
        break;
      case 2:
        view_record(records, num_records);
        break;
      case 3:
        modify_record(records, num_records);
        break;
      case 4:
        printf("\nExiting...\n");
        return 0;
      default:
        printf("\nInvalid choice. Try again.\n");
    }
  }
}