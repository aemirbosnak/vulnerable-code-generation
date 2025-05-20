//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file;
  char filename[50], line[100], *pointer;
  int num_of_lines = 0, num_of_columns = 0, i, j;

  printf("What is the filename of the CSV file you want to read? ");
  scanf("%s", filename);

  file = fopen(filename, "r");

  if (!file) {
    printf("Unable to open file\n");
    exit(1);
  }

  // Count the number of lines in the CSV file
  while (fgets(line, sizeof(line), file)) {
    num_of_lines++;
  }

  rewind(file); // Reset the file pointer to the beginning of the file

  // Get the number of columns in the CSV file
  fgets(line, sizeof(line), file);
  num_of_columns = 1;
  pointer = strtok(line, ",");
  while (pointer != NULL) {
    num_of_columns++;
    pointer = strtok(NULL, ",");
  }

  rewind(file); // Reset the file pointer to the beginning of the file

  // Declare a 2D array to hold the CSV data
  char data[num_of_lines][num_of_columns * 10];

  // Read the CSV data into the 2D array
  for (i = 0; i < num_of_lines; i++) {
    fgets(line, sizeof(line), file);
    pointer = strtok(line, ",");
    for (j = 0; j < num_of_columns; j++) {
      strcpy(data[i][j], pointer);
      pointer = strtok(NULL, ",");
    }
  }

  // Print the CSV data
  printf("\nCSV data:\n");
  for (i = 0; i < num_of_lines; i++) {
    for (j = 0; j < num_of_columns; j++) {
      printf("%s\t", data[i][j]);
    }
    printf("\n");
  }

  fclose(file);
  return 0;
}