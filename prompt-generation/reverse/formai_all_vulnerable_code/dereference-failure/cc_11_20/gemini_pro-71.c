//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Open the CSV file
  FILE *file = fopen("data.csv", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the header line
  char line[1024];
  if (fgets(line, sizeof(line), file) == NULL) {
    perror("Error reading header line");
    fclose(file);
    return EXIT_FAILURE;
  }

  // Get the number of columns
  int num_columns = 0;
  char *column;
  column = strtok(line, ",");
  while (column != NULL) {
    num_columns++;
    column = strtok(NULL, ",");
  }

  // Create an array to store the column names
  char **column_names = malloc(sizeof(char *) * num_columns);
  if (column_names == NULL) {
    perror("Error allocating memory for column names");
    fclose(file);
    return EXIT_FAILURE;
  }

  // Get the column names
  int i;
  column = strtok(line, ",");
  for (i = 0; i < num_columns; i++) {
    column_names[i] = strdup(column);
    column = strtok(NULL, ",");
  }

  // Read the data lines
  while (fgets(line, sizeof(line), file) != NULL) {
    // Get the values for each column
    char **values = malloc(sizeof(char *) * num_columns);
    if (values == NULL) {
      perror("Error allocating memory for values");
      fclose(file);
      return EXIT_FAILURE;
    }

    column = strtok(line, ",");
    for (i = 0; i < num_columns; i++) {
      values[i] = strdup(column);
      column = strtok(NULL, ",");
    }

    // Print the values
    for (i = 0; i < num_columns; i++) {
      printf("%s: %s\n", column_names[i], values[i]);
    }

    // Free the memory for the values
    for (i = 0; i < num_columns; i++) {
      free(values[i]);
    }
    free(values);
  }

  // Free the memory for the column names
  for (i = 0; i < num_columns; i++) {
    free(column_names[i]);
  }
  free(column_names);

  // Close the file
  fclose(file);

  return EXIT_SUCCESS;
}