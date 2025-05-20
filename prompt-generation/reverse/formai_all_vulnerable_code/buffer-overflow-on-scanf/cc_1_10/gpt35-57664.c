//FormAI DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure for the bank record system
struct bankRecord {
  char name[50];
  char accountNum[20];
  float balance;
};

// Function to display the bank records
void display(struct bankRecord record[], int numRecords) {
  printf("\n%-20s %-20s %-20s\n\n", "Name", "Account Number", "Balance");
  
  // Loop through all the bank records and display them
  for (int i = 0; i < numRecords; i++) {
    printf("%-20s %-20s %-20.2f\n", record[i].name, record[i].accountNum, record[i].balance);
  }
}

// Function to add a new bank record
void addRecord(struct bankRecord record[], int numRecords) {
  if (numRecords < 50) { // Make sure we don't exceed our maximum record limit
    char name[50];
    char accountNum[20];
    float balance;

    printf("\nEnter the name:");
    scanf("%s", name);
    printf("Enter the account number:");
    scanf("%s", accountNum);
    printf("Enter the balance:");
    scanf("%f", &balance);

    // Set the values of the new record and increment the number of records
    strcpy(record[numRecords].name, name);
    strcpy(record[numRecords].accountNum, accountNum);
    record[numRecords].balance = balance;

    printf("\nRecord added successfully!\n");
  } else {
    printf("\nMaximum number of records have been reached, cannot add more.\n");
  }
}

int main(void) {
  struct bankRecord record[50];
  int numRecords = 0;
  int option;

  do {
    // Display the menu
    printf("\nBank Record System\n");
    printf("1. Display Records\n");
    printf("2. Add New Record\n");
    printf("3. Exit\n");
    printf("Choose an option:");

    scanf("%d", &option);

    switch (option) {
      case 1:
        // Call the display function to show all the records
        display(record, numRecords);
        break;
      case 2:
        // Call the addRecord function to add a new record
        addRecord(record, numRecords);
        numRecords++;
        break;
      case 3:
        // Exit the program
        printf("\nExiting program...\n");
        break;
      default:
        // Invalid option
        printf("\nInvalid option, please try again.\n");
        break;
    }
  } while (option != 3);

  return 0;
}