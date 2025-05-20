//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 20

// Define a structure to store record data
typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  float height;
} Record;

// Define a function to query a record in the database
void query_database(Record database[], int num_records) {
  char search_name[MAX_NAME_LENGTH];
  printf("Enter the name to search for: ");
  scanf("%s", search_name);

  // Loop through all the records in the database
  for (int i = 0; i < num_records; i++) {
    if (strcmp(database[i].name, search_name) == 0) {
      printf("Name: %s\n", database[i].name);
      printf("Age: %d\n", database[i].age);
      printf("Height: %.2f\n", database[i].height);
      return;
    }
  }

  // If we get here, the name was not found in the database
  printf("Record not found.\n");
}

int main() {
  // Initialize an empty database
  Record database[MAX_RECORDS];
  int num_records = 0;

  // Add some sample records to the database
  strcpy(database[num_records].name, "John");
  database[num_records].age = 25;
  database[num_records].height = 5.9;
  num_records++;

  strcpy(database[num_records].name, "Jane");
  database[num_records].age = 30;
  database[num_records].height = 6.0;
  num_records++;

  strcpy(database[num_records].name, "Bob");
  database[num_records].age = 20;
  database[num_records].height = 5.6;
  num_records++;

  // Query the database for a record
  query_database(database, num_records);

  return 0;
}