//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
  char name[50];
  int age;
  char occupation[50];
} person_t;

// Define the database
person_t database[] = {
  { "Sir Reginald", 35, "Knight" },
  { "Lady Eleanor", 28, "Lady-in-waiting" },
  { "Master William", 42, "Scribe" },
  { "Mistress Alice", 30, "Healer" },
  { "Brother Thomas", 25, "Monk" }
};

// Define the number of records in the database
#define NUM_RECORDS (sizeof(database) / sizeof(person_t))

// Function to print the database
void print_database() {
  for (int i = 0; i < NUM_RECORDS; i++) {
    printf("%s, %d, %s\n", database[i].name, database[i].age, database[i].occupation);
  }
}

// Function to add a record to the database
void add_record(person_t *person) {
  if (NUM_RECORDS >= 50) {
    printf("The database is full.\n");
    return;
  }

  database[NUM_RECORDS] = *person;
}

// Function to delete a record from the database
void delete_record(int index) {
  if (index < 0 || index >= NUM_RECORDS) {
    printf("Invalid index.\n");
    return;
  }

  for (int i = index; i < NUM_RECORDS - 1; i++) {
    database[i] = database[i + 1];
  }
}

// Function to search the database for a record
int search_record(char *name) {
  for (int i = 0; i < NUM_RECORDS; i++) {
    if (strcmp(database[i].name, name) == 0) {
      return i;
    }
  }

  return -1;
}

// Main function
int main() {
  // Print the database
  printf("The database contains the following records:\n");
  print_database();

  // Add a record to the database
  person_t new_person = { "Sir Lancelot", 29, "Knight" };
  add_record(&new_person);

  // Print the database again
  printf("\nThe database now contains the following records:\n");
  print_database();

  // Delete a record from the database
  delete_record(2);

  // Print the database again
  printf("\nThe database now contains the following records:\n");
  print_database();

  // Search for a record in the database
  int index = search_record("Lady Eleanor");
  if (index == -1) {
    printf("The record could not be found.\n");
  } else {
    printf("The record was found at index %d.\n", index);
  }

  return 0;
}