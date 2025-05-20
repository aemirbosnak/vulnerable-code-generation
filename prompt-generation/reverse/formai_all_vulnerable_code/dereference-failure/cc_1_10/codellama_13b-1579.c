//Code Llama-13B DATASET v1.0 Category: File handling ; Style: cheerful
/*
 * Program: Cheerful File Handling
 * Description: A program that demonstrates file handling in C in a cheerful style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to open a file and check for errors
int open_file(FILE **file, char *filename) {
  *file = fopen(filename, "r");
  if (*file == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return 1;
  }
  return 0;
}

// Function to close a file and check for errors
int close_file(FILE **file) {
  if (fclose(*file) != 0) {
    printf("Error: Could not close file\n");
    return 1;
  }
  return 0;
}

// Function to read a line from a file and check for errors
int read_line(FILE *file, char *line) {
  if (fgets(line, 100, file) == NULL) {
    printf("Error: Could not read line from file\n");
    return 1;
  }
  return 0;
}

// Function to write a line to a file and check for errors
int write_line(FILE *file, char *line) {
  if (fputs(line, file) < 0) {
    printf("Error: Could not write line to file\n");
    return 1;
  }
  return 0;
}

int main(void) {
  // Open a file
  FILE *file;
  if (open_file(&file, "example.txt") != 0) {
    return 1;
  }

  // Read a line from the file
  char line[100];
  if (read_line(file, line) != 0) {
    return 1;
  }
  printf("Read line from file: %s\n", line);

  // Write a line to the file
  if (write_line(file, "Hello, world!") != 0) {
    return 1;
  }

  // Close the file
  if (close_file(&file) != 0) {
    return 1;
  }

  return 0;
}