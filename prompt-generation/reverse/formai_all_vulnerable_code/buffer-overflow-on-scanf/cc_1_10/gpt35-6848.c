//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

/* Define a constant for the maximum number of records */
#define MAX_RECORDS 10

/* Define a structure for a single record */
struct Record {
  int account_number;
  float balance;
};

/* Define an array to hold all records */
struct Record records[MAX_RECORDS];

/* Define a variable to keep track of the number of records */
int num_records = 0;

/* Function to add a new record */
void add_record() {
  /* If the maximum number of records has been reached */
  if (num_records >= MAX_RECORDS) {
    printf("Maximum number of records reached!\n");
    return;
  }

  /* Get the account number from the user */
  printf("Enter account number: ");
  scanf("%d", &records[num_records].account_number);

  /* Get the balance from the user */
  printf("Enter balance: ");
  scanf("%f", &records[num_records].balance);

  /* Increment the number of records */
  num_records++;

  /* Print a success message */
  printf("Record added successfully!\n");
}

/* Function to display all records */
void display_records() {
  /* If there are no records */
  if (num_records == 0) {
    printf("No records found!\n");
    return;
  }

  /* Print header */
  printf("Account Number\tBalance\n");

  /* Loop through all records and print them */
  for (int i = 0; i < num_records; i++) {
    printf("%d\t\t%.2f\n", records[i].account_number, records[i].balance);
  }
}

/* Function to search for a record by account number */
void search_record() {
  /* If there are no records */
  if (num_records == 0) {
    printf("No records found!\n");
    return;
  }

  /* Get the account number to search for */
  int account_number;
  printf("Enter account number to search for: ");
  scanf("%d", &account_number);

  /* Loop through all records looking for a match */
  for (int i = 0; i < num_records; i++) {
    if (records[i].account_number == account_number) {
      /* If a match was found, print the record */
      printf("Account Number\tBalance\n");
      printf("%d\t\t%.2f\n", records[i].account_number, records[i].balance);
      return;
    }
  }

  /* If no match was found, print an error message */
  printf("Record not found!\n");
}

/* Function to update an existing record */
void update_record() {
  /* If there are no records */
  if (num_records == 0) {
    printf("No records found!\n");
    return;
  }

  /* Get the account number to update */
  int account_number;
  printf("Enter account number to update: ");
  scanf("%d", &account_number);

  /* Loop through all records looking for a match */
  for (int i = 0; i < num_records; i++) {
    if (records[i].account_number == account_number) {
      /* If a match was found, get the new balance from the user */
      printf("Enter new balance: ");
      scanf("%f", &records[i].balance);

      /* Print a success message */
      printf("Record updated successfully!\n");
      return;
    }
  }

  /* If no match was found, print an error message */
  printf("Record not found!\n");
}

/* Function to delete an existing record */
void delete_record() {
  /* If there are no records */
  if (num_records == 0) {
    printf("No records found!\n");
    return;
  }

  /* Get the account number to delete */
  int account_number;
  printf("Enter account number to delete: ");
  scanf("%d", &account_number);

  /* Loop through all records looking for a match */
  for (int i = 0; i < num_records; i++) {
    if (records[i].account_number == account_number) {
      /* If a match was found, move all records after it back by one */
      for (int j = i+1; j < num_records; j++) {
        records[j-1] = records[j];
      }

      /* Decrement the number of records */
      num_records--;

      /* Print a success message */
      printf("Record deleted successfully!\n");
      return;
    }
  }

  /* If no match was found, print an error message */
  printf("Record not found!\n");
}

/* Main function */
int main() {
  /* Declare a variable to hold the user's choice */
  int choice;

  /* Loop until the user chooses to quit */
  while (1) {
    /* Print the menu */
    printf("Banking Record System:\n");
    printf("1. Add new record\n");
    printf("2. Display all records\n");
    printf("3. Search for a record\n");
    printf("4. Update an existing record\n");
    printf("5. Delete an existing record\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");

    /* Get the user's choice */
    scanf("%d", &choice);

    /* Perform the appropriate action based on the user's choice */
    switch (choice) {
      case 1:
        add_record();
        break;
      case 2:
        display_records();
        break;
      case 3:
        search_record();
        break;
      case 4:
        update_record();
        break;
      case 5:
        delete_record();
        break;
      case 6:
        /* Quit the program */
        printf("Goodbye!\n");
        return 0;
      default:
        /* If an invalid choice was made, print an error message */
        printf("Invalid choice, please try again!\n");
    }
  }
}