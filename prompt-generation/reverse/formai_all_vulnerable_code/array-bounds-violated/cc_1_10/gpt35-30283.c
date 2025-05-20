//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns
#define MAX_COLUMNS 10

// Define the maximum number of characters per column
#define MAX_CHARS 100

// Define the maximum line length
#define MAX_LINE_LENGTH (MAX_COLUMNS * MAX_CHARS)

int main() {
  // Define the file pointer and filename
  FILE *fp;
  char filename[MAX_CHARS];

  // Ask the user for the filename
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open the file in read mode
  fp = fopen(filename, "r");

  // If file is null, display an error message and exit
  if (fp == NULL) {
    printf("Error: File %s could not be found.\n", filename);
    exit(1);
  }

  // Define variables to read the file line by line
  char line[MAX_LINE_LENGTH];
  char *field;
  char *endptr;
  int i = 0, j = 0;

  // Define a 2D array to store the data
  char data[MAX_CHARS][MAX_COLUMNS];

  // Read each line of the file
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    // Remove the newline character from the end of the line
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    // Split the line into fields
    field = strtok(line, ",");
    j = 0;
    while (field != NULL && j < MAX_COLUMNS) {
      // Convert the field to a double
      double num = strtod(field, &endptr);

      // If the conversion was successful, store the number
      if (*endptr == '\0') {
        sprintf(data[i][j], "%f", num);
      } else {
        // If the conversion failed, store the string
        strcpy(data[i][j], field);
      }
      field = strtok(NULL, ",");
      j++;
    }
    i++;
  }

  // Close the file
  fclose(fp);

  // Print the data
  printf("\nData in the CSV file:\n");
  for (int k = 0; k < i; k++) {
    for (int l = 0; l < j; l++) {
      printf("%s ", data[k][l]);
    }
    printf("\n");
  }

  return 0;
}