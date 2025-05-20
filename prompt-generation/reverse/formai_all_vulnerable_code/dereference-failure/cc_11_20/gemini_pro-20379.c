//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
  // Open the CSV file
  FILE *file = fopen("data.csv", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the first line of the file to get the header
  char line[MAX_LINE_LENGTH];
  if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
    perror("Error reading header");
    fclose(file);
    return EXIT_FAILURE;
  }

  // Parse the header and get the number of columns
  char *header = strtok(line, ",");
  int num_columns = 1;
  while (header != NULL) {
    header = strtok(NULL, ",");
    num_columns++;
  }

  // Allocate memory for the data array
  char **data = malloc(sizeof(char *) * num_columns);
  for (int i = 0; i < num_columns; i++) {
    data[i] = malloc(sizeof(char) * MAX_LINE_LENGTH);
  }

  // Read the rest of the file and store the data in the array
  int row = 0;
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    // Parse the line and get the data
    char *token = strtok(line, ",");
    for (int i = 0; i < num_columns; i++) {
      strcpy(data[i][row], token);
      token = strtok(NULL, ",");
    }
    row++;
  }

  // Close the file
  fclose(file);

  // Print the data
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < num_columns; j++) {
      printf("%s", data[i][j]);
      if (j < num_columns - 1) {
        printf(",");
      }
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < num_columns; i++) {
    free(data[i]);
  }
  free(data);

  return EXIT_SUCCESS;
}