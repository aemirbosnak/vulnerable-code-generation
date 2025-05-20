//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of records */
#define MAX_RECORDS 100

/* Define the structure of the record */
struct Record {
  int id;
  char name[30];
  char email[30];
};

/* Declare an array of records */
struct Record records[MAX_RECORDS];

/* Declare a counter to keep track of the number of records */
int record_count = 0;

/* Declare a function to add a new record */
void add_record() {
  /* Declare variables to hold the user input */
  int id;
  char name[30];
  char email[30];
  
  /* Ask the user for the information */
  printf("Enter the ID: ");
  scanf("%d", &id);
  
  printf("Enter the name: ");
  scanf("%s", name);
  
  printf("Enter the email: ");
  scanf("%s", email);
  
  /* Create a new record */
  struct Record new_record;
  new_record.id = id;
  strcpy(new_record.name, name);
  strcpy(new_record.email, email);
  
  /* Add the new record to the end of the array */
  records[record_count] = new_record;
  record_count++;
  
  printf("Record added successfully!\n");
}

/* Declare a function to search for a record by ID */
void search_record() {
  /* Declare a variable to hold the user input */
  int id;
  
  /* Ask the user for the ID to search */
  printf("Enter the ID to search: ");
  scanf("%d", &id);
  
  /* Loop through all the records to find a match */
  for (int i = 0; i < record_count; i++) {
    if (records[i].id == id) {
      printf("Found record:\n");
      printf("ID: %d\n", records[i].id);
      printf("Name: %s\n", records[i].name);
      printf("Email: %s\n", records[i].email);
      return;
    }
  }
  
  /* If we looped through all the records and didn't find a match */
  printf("Record not found!\n");
}

/* Declare a function to delete a record by ID */
void delete_record() {
  /* Declare a variable to hold the user input */
  int id;
  
  /* Ask the user for the ID to delete */
  printf("Enter the ID to delete: ");
  scanf("%d", &id);
  
  /* Loop through all the records to find a match */
  for (int i = 0; i < record_count; i++) {
    if (records[i].id == id) {
      /* Shift all the elements after this one back by one */
      for (int j = i; j < record_count - 1; j++) {
        records[j] = records[j + 1];
      }
      
      /* Decrement the counter since we removed a record */
      record_count--;
      
      printf("Record deleted successfully!\n");
      return;
    }
  }
  
  /* If we looped through all the records and didn't find a match */
  printf("Record not found!\n");
}

/* Declare a function to display all the records */
void display_records() {
  /* Loop through all the records and print them */
  for (int i = 0; i < record_count; i++) {
    printf("Record %d:\n", i + 1);
    printf("ID: %d\n", records[i].id);
    printf("Name: %s\n", records[i].name);
    printf("Email: %s\n\n", records[i].email);
  }
}

/* Define the main function */
int main() {
  /* Declare a variable to hold the user input */
  int choice;
  
  /* Display the menu until the user quits */
  while (1) {
    printf("DATABASE SIMULATION\n");
    printf("1. Add a new record\n");
    printf("2. Search for a record by ID\n");
    printf("3. Delete a record by ID\n");
    printf("4. Display all the records\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    /* Call the appropriate function based on the user's choice */
    switch (choice) {
      case 1:
        add_record();
        break;
      case 2:
        search_record();
        break;
      case 3:
        delete_record();
        break;
      case 4:
        display_records();
        break;
      case 5:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice! Try again.\n");
        break;
    }
  }
  
  return 0;
}