//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the database structure
typedef struct {
  char name[MAX_RECORD_LENGTH];
  int age;
  float salary;
} record;

// Define the database
record database[MAX_RECORDS];

// Define the current number of records in the database
int num_records = 0;

// Define the menu options
enum menu_options {
  ADD_RECORD,
  DELETE_RECORD,
  SEARCH_RECORD,
  PRINT_DATABASE,
  QUIT
};

// Function to print the menu
void print_menu() {
  printf("\nPlease select an option:\n");
  printf("1. Add a record\n");
  printf("2. Delete a record\n");
  printf("3. Search for a record\n");
  printf("4. Print the database\n");
  printf("5. Quit\n");
}

// Function to get the user's choice
int get_choice() {
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Function to add a record to the database
void add_record() {
  // Get the record from the user
  printf("Enter the name: ");
  scanf("%s", database[num_records].name);
  printf("Enter the age: ");
  scanf("%d", &database[num_records].age);
  printf("Enter the salary: ");
  scanf("%f", &database[num_records].salary);

  // Increment the number of records
  num_records++;
}

// Function to delete a record from the database
void delete_record() {
  // Get the name of the record to delete
  char name[MAX_RECORD_LENGTH];
  printf("Enter the name of the record to delete: ");
  scanf("%s", name);

  // Find the record to delete
  int index = -1;
  for (int i = 0; i < num_records; i++) {
    if (strcmp(database[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // If the record was found, delete it
  if (index != -1) {
    for (int i = index; i < num_records - 1; i++) {
      database[i] = database[i + 1];
    }
    num_records--;
    printf("Record deleted.\n");
  } else {
    printf("Record not found.\n");
  }
}

// Function to search for a record in the database
void search_record() {
  // Get the name of the record to search for
  char name[MAX_RECORD_LENGTH];
  printf("Enter the name of the record to search for: ");
  scanf("%s", name);

  // Find the record
  int index = -1;
  for (int i = 0; i < num_records; i++) {
    if (strcmp(database[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // If the record was found, print it
  if (index != -1) {
    printf("Record found:\n");
    printf("Name: %s\n", database[index].name);
    printf("Age: %d\n", database[index].age);
    printf("Salary: %f\n", database[index].salary);
  } else {
    printf("Record not found.\n");
  }
}

// Function to print the database
void print_database() {
  printf("\nDatabase:\n");
  for (int i = 0; i < num_records; i++) {
    printf("Record %d:\n", i + 1);
    printf("Name: %s\n", database[i].name);
    printf("Age: %d\n", database[i].age);
    printf("Salary: %f\n", database[i].salary);
  }
}

// Main function
int main() {
  // Print the welcome message
  printf("Welcome to the database simulation program!\n");

  // Loop until the user quits
  int choice;
  do {
    // Print the menu
    print_menu();

    // Get the user's choice
    choice = get_choice();

    // Perform the selected action
    switch (choice) {
      case ADD_RECORD:
        add_record();
        break;
      case DELETE_RECORD:
        delete_record();
        break;
      case SEARCH_RECORD:
        search_record();
        break;
      case PRINT_DATABASE:
        print_database();
        break;
    }
  } while (choice != QUIT);

  // Print the goodbye message
  printf("Goodbye!\n");

  return 0;
}