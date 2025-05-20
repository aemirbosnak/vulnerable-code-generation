//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 100
#define MAX_COLS 20

int main() {
  char ***csv_data = NULL;
  int num_lines = 0;
  int num_cols = 0;

  char csv_file_name[] = "data.csv";

  FILE *csv_file = fopen(csv_file_name, "r");
  if (csv_file == NULL) {
    perror("Error opening CSV file");
    return EXIT_FAILURE;
  }

  // Allocate memory for the CSV data
  csv_data = malloc(MAX_LINES * sizeof(char ***));
  if (csv_data == NULL) {
    perror("Error allocating memory");
    return EXIT_FAILURE;
  }

  // Read the CSV file line by line
  char line[MAX_LINES][MAX_COLS];
  while (fgets(line, MAX_LINES, csv_file) != NULL) {
    // Count the number of columns in the line
    int num_cols_line = 0;
    for (int i = 0; line[i] != '\0'; i++) {
      if (line[i] == ',') {
        num_cols_line++;
      }
    }

    // If the number of columns in the line is greater than the number of columns in the CSV data,
    // update the number of columns in the CSV data
    if (num_cols_line > num_cols) {
      num_cols = num_cols_line;
      csv_data = realloc(csv_data, MAX_LINES * sizeof(char ***));
    }

    // Add the line to the CSV data
    csv_data[num_lines] = malloc(num_cols * sizeof(char *));
    if (csv_data[num_lines] == NULL) {
      perror("Error allocating memory");
      return EXIT_FAILURE;
    }

    for (int i = 0; line[i] != '\0'; i++) {
      csv_data[num_lines][i] = strdup(line[i]);
    }

    num_lines++;
  }

  fclose(csv_file);

  // Print the CSV data
  for (int i = 0; i < num_lines; i++) {
    for (int j = 0; j < num_cols; j++) {
      printf("%s,", csv_data[i][j]);
    }
    printf("\n");
  }

  free(csv_data);

  return EXIT_SUCCESS;
}