//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  // Declare variables
  char csv_file[256];
  FILE *fp;
  char **rows;
  int num_rows = 0;
  char *row;
  int i, j, k;

  // Get the CSV file name from the user
  printf("Enter the name of the CSV file: ");
  scanf("%s", csv_file);

  // Open the CSV file
  fp = fopen(csv_file, "r");

  // Check if the file is open
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  // Count the number of rows in the CSV file
  while (getline(fp, row, 256) != NULL) {
    num_rows++;
  }

  // Allocate memory for the rows
  rows = (char **)malloc(num_rows * sizeof(char *));

  // Read the CSV file again and store the rows in memory
  rewind(fp);
  i = 0;
  while (getline(fp, row, 256) != NULL) {
    rows[i++] = strdup(row);
  }

  // Print the rows
  for (k = 0; k < num_rows; k++) {
    printf("%s\n", rows[k]);
  }

  // Close the CSV file
  fclose(fp);

  // Free the memory allocated for the rows
  free(rows);

  return 0;
}