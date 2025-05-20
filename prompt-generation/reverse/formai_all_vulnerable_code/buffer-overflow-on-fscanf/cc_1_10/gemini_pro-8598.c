//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in the CSV file
#define MAX_COLS 10

// Define the maximum number of characters in a single CSV field
#define MAX_FIELD_LENGTH 100

// Define the delimiter character for the CSV file
#define DELIMITER ','

// Declare the main function
int main(void) {
  // Declare the file pointer
  FILE *file;

  // Declare the array of column headers
  char *headers[MAX_COLS];

  // Declare the array of field values
  char *fields[MAX_COLS];

  // Open the CSV file for reading
  file = fopen("data.csv", "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the header line from the CSV file
  for (int i = 0; i < MAX_COLS; i++) {
    headers[i] = malloc(MAX_FIELD_LENGTH);
    fscanf(file, "%s", headers[i]);
  }

  // Read the data lines from the CSV file
  while (!feof(file)) {
    // Read the next line from the CSV file
    char line[1024];
    fgets(line, 1024, file);

    // Split the line into fields
    char *field = strtok(line, DELIMITER);
    int field_count = 0;
    while (field != NULL) {
      fields[field_count] = malloc(MAX_FIELD_LENGTH);
      strcpy(fields[field_count], field);
      field = strtok(NULL, DELIMITER);
      field_count++;
    }

    // Print the field values
    for (int i = 0; i < field_count; i++) {
      printf("%s: %s\n", headers[i], fields[i]);
    }
  }

  // Close the CSV file
  fclose(file);

  // Free the memory allocated for the column headers and field values
  for (int i = 0; i < MAX_COLS; i++) {
    free(headers[i]);
    free(fields[i]);
  }

  return 0;
}