//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_LINE_LENGTH 100

// Function to read a file line by line
void readFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    printf("%s\n", line);
  }

  fclose(file);
}

// Function to write a file line by line
void writeFile(const char* filename) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  char line[MAX_LINE_LENGTH];
  printf("Writing file %s...\n", filename);

  // Ask user for lines to write
  char* line_input;
  while (scanf("%s", &line_input) == 1) {
    printf("Writing line: %s\n", line_input);
    fputs(line_input, file);
  }

  fclose(file);
}

int main() {
  // Read a file
  readFile("example.txt");

  // Write a new file
  writeFile("new_file.txt");

  return 0;
}