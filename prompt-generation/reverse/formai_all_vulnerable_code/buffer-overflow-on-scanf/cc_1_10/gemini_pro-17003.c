//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
  int id;
  char *name;
  int age;
} person;

// Define the database
person database[] = {
  {1, "John", 20},
  {2, "Jane", 21},
  {3, "Bob", 22},
  {4, "Alice", 23},
  {5, "Tom", 24}
};

// Define the number of records in the database
int num_records = sizeof(database) / sizeof(person);

// Define the query function
person* query(int id) {
  // Iterate over the database
  for (int i = 0; i < num_records; i++) {
    // If the ID matches, return the record
    if (database[i].id == id) {
      return &database[i];
    }
  }

  // If the ID does not match any records, return NULL
  return NULL;
}

// Define the main function
int main() {
  // Get the ID of the record to query from the user
  int id;
  printf("Enter the ID of the record to query: ");
  scanf("%d", &id);

  // Query the database
  person *record = query(id);

  // If the record was found, print the information
  if (record != NULL) {
    printf("Record found:\n");
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
  } else {
    printf("Record not found.\n");
  }

  return 0;
}