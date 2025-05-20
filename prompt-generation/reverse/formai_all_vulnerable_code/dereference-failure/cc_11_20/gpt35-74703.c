//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

/*
 * This program reads a CSV file and prints its contents to the console.
 */

int main(int argc, char* argv[]) {

  // Check if the input filename is provided
  if (argc != 2) {
    printf("Usage: %s <input-file>\n", argv[0]);
    return -1;
  }

  // Open the input file
  FILE* input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Failed to open file %s\n", argv[1]);
    return -1;
  }

  // Allocate memory for the line buffer
  char* line_buffer = malloc(MAX_LINE_LENGTH);
  if (line_buffer == NULL) {
    printf("Failed to allocate memory\n");
    return -1;
  }

  // Read the first line, which contains the header row
  if (fgets(line_buffer, MAX_LINE_LENGTH, input_file) == NULL) {
    printf("Failed to read header row from file %s\n", argv[1]);
    return -1;
  }

  // Parse the header row to get the number of columns
  int num_columns = 1;
  for (int i = 0; i < strlen(line_buffer); i++) {
    if (line_buffer[i] == ',') {
      num_columns++;
    }
  }

  // Allocate memory for the column names
  char** column_names = malloc(num_columns * sizeof(char*));
  if (column_names == NULL) {
    printf("Failed to allocate memory\n");
    return -1;
  }

  // Tokenize the header row and store the column names
  int column_index = 0;
  char* token = strtok(line_buffer, ",");
  while (token != NULL) {
    column_names[column_index] = malloc(strlen(token) + 1);
    if (column_names[column_index] == NULL) {
      printf("Failed to allocate memory\n");
      return -1;
    }
    strcpy(column_names[column_index], token);
    column_index++;
    token = strtok(NULL, ",");
  }

  // Print the header row
  for (int i = 0; i < num_columns; i++) {
    printf("%s\t", column_names[i]);
  }
  printf("\n");

  // Read the rest of the file line by line
  while (fgets(line_buffer, MAX_LINE_LENGTH, input_file) != NULL) {

    // Tokenize the line
    column_index = 0;
    token = strtok(line_buffer, ",");
    while (token != NULL) {

      // Print the column value
      printf("%s\t", token);

      // Move to the next column
      column_index++;
      token = strtok(NULL, ",");
    }

    // Print a new line
    printf("\n");
  }

  // Close the input file
  fclose(input_file);

  // Free memory
  free(line_buffer);
  for (int i = 0; i < num_columns; i++) {
    free(column_names[i]);
  }
  free(column_names);

  return 0;

}