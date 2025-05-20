//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records and the length of the strings
#define MAX_RECORDS 100
#define MAX_LENGTH 50

// Define the structure of a record
typedef struct {
  int id;
  char name[MAX_LENGTH];
  char address[MAX_LENGTH];
} Record;

// Define global variables
Record database[MAX_RECORDS];
int num_records = 0;

// Define function prototypes
void insert_record();
void display_record();
void search_record();

int main() {
  char choice;

  // Display menu and loop until user exits
  do {
    printf("\n      MENU\n");
    printf("------------------\n");
    printf("1. Insert Record\n");
    printf("2. Display Record\n");
    printf("3. Search Record\n");
    printf("0. Exit\n");
    printf("------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        insert_record();
        break;
      case '2':
        display_record();
        break;
      case '3':
        search_record();
        break;
      case '0':
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while (choice != '0');

  return 0;
}

// Function to insert a record into the database
void insert_record() {
  // Check if maximum number of records has been reached
  if (num_records >= MAX_RECORDS) {
    printf("\nMaximum number of records reached. Cannot insert more.\n");
    return;
  }

  // Get input from user
  printf("\nEnter the following information:\n");
  printf("ID: ");
  scanf("%d", &database[num_records].id);
  printf("Name: ");
  scanf("%s", database[num_records].name);
  printf("Address: ");
  scanf("%s", database[num_records].address);

  // Increment the number of records
  num_records++;

  printf("\nRecord inserted successfully.\n");
}

// Function to display all records in the database
void display_record() {
  // Check if the database is empty
  if (num_records == 0) {
    printf("\nThe database is empty.\n");
    return;
  }

  printf("\n%-5s%-20s%-20s\n", "ID", "NAME", "ADDRESS");
  printf("--------------------------------------------------\n");
  for (int i = 0; i < num_records; i++) {
    printf("%-5d%-20s%-20s\n", database[i].id, database[i].name, database[i].address);
  }
}

// Function to search for a record in the database by ID
void search_record() {
  int search_id, found = 0;

  // Check if the database is empty
  if (num_records == 0) {
    printf("\nThe database is empty.\n");
    return;
  }

  // Get input from user
  printf("\nEnter the ID to search for: ");
  scanf("%d", &search_id);

  // Search for the record by ID
  for (int i = 0; i < num_records; i++) {
    if (database[i].id == search_id) {
      printf("\n%-5s%-20s%-20s\n", "ID", "NAME", "ADDRESS");
      printf("--------------------------------------------------\n");
      printf("%-5d%-20s%-20s\n", database[i].id, database[i].name, database[i].address);
      found = 1; // Set flag to indicate record was found
      break;
    }
  }

  if (!found) {
    printf("\nRecord not found.\n");
  }
}