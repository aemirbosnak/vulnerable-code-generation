//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>

#define DATABASE_SIZE 1000
#define MAX_RECORDS 100
#define FIELD_SIZE 20

// Structure to hold one record (i.e., one row) of data
typedef struct {
  char name[FIELD_SIZE];
  int age;
  float income;
} record_t;

// Function to read in a database of records from a file
record_t *read_database(const char *file_name) {
  // Open the file and allocate memory for the database
  FILE *file = fopen(file_name, "r");
  record_t *database = malloc(DATABASE_SIZE * sizeof(record_t));

  // Read in the records and store them in the database
  int i = 0;
  while (i < DATABASE_SIZE && fscanf(file, "%s%d%f", database[i].name, &database[i].age, &database[i].income) == 3) {
    i++;
  }

  // Return the database
  return database;
}

// Function to print out the records in the database
void print_database(record_t *database) {
  int i;
  for (i = 0; i < DATABASE_SIZE; i++) {
    printf("%s (%d, %f)\n", database[i].name, database[i].age, database[i].income);
  }
}

// Function to find the average income for all records in the database
float find_average_income(record_t *database) {
  int i;
  float sum = 0;
  for (i = 0; i < DATABASE_SIZE; i++) {
    sum += database[i].income;
  }
  return sum / DATABASE_SIZE;
}

int main() {
  // Read in the database from a file
  record_t *database = read_database("database.dat");

  // Print out the records in the database
  print_database(database);

  // Find the average income for all records in the database
  float average_income = find_average_income(database);
  printf("Average income: %f\n", average_income);

  // Free the memory for the database
  free(database);

  return 0;
}