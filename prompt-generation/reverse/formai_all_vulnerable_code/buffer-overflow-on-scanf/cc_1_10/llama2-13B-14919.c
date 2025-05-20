//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file line by line
void readFile(char *filename) {
  FILE *file = fopen(filename, "r");
  char line[100];

  // Check if the file opening was successful
  if (file == NULL) {
    printf("Error: Unable to open file %s\n", filename);
    return;
  }

  // Read each line of the file
  while (fgets(line, 100, file) != NULL) {
    // Print each line
    printf("%s\n", line);
  }

  // Close the file
  fclose(file);
}

// Function to write a file line by line
void writeFile(char *filename) {
  FILE *file = fopen(filename, "w");
  char line[100];

  // Check if the file opening was successful
  if (file == NULL) {
    printf("Error: Unable to open file %s\n", filename);
    return;
  }

  // Read each line of the file
  char *line_ptr;
  printf("Enter the lines to be written to the file:\n");
  scanf("%s", line);
  while (line_ptr = strtok(line, "\n")) {
    // Write each line to the file
    fputs(line_ptr, file);
  }

  // Close the file
  fclose(file);
}

int main() {
  // Read a file line by line
  readFile("peaceful.txt");

  // Write a file line by line
  writeFile("new_peaceful.txt");

  return 0;
}