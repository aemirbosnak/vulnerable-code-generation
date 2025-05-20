//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error handling function
void handle_error(const char *error_message) {
  fprintf(stderr, "An error occurred: %s\n", error_message);
  exit(EXIT_FAILURE);
}

// Function to open a file and check for errors
FILE *open_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    handle_error("Could not open file");
  }
  return file;
}

// Function to read a line from a file and check for errors
char *read_line(FILE *file) {
  char *line = NULL;
  size_t len = 0;
  if (getline(&line, &len, file) == -1) {
    handle_error("Could not read line from file");
  }
  return line;
}

// Function to parse a line of text and extract a number
int parse_number(const char *line) {
  char *endptr;
  int number = strtol(line, &endptr, 10);
  if (*endptr != '\0') {
    handle_error("Could not parse number from line");
  }
  return number;
}

// Main function
int main() {
  // Open the input file
  FILE *file = open_file("input.txt");

  // Read the first line from the file
  char *line = read_line(file);

  // Parse the first line as a number
  int number = parse_number(line);

  // Print the number to the console
  printf("The number is: %d\n", number);

  // Close the input file
  fclose(file);

  // Free the allocated memory
  free(line);

  return EXIT_SUCCESS;
}