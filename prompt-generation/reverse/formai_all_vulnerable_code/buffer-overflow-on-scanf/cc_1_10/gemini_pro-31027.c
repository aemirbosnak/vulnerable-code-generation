//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables and initialize them to 0
  int num_words = 0;
  int num_lines = 0;
  int num_chars = 0;
  int num_spaces = 0;

  // Get the filename from the user
  char filename[256];
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open the file
  FILE *file = fopen(filename, "r");

  // If the file is not found, print an error message and exit the program
  if (file == NULL) {
    printf("Error: File not found!\n");
    return 1;
  }

  // Read the file character by character
  int c;
  while ((c = fgetc(file)) != EOF) {
    // Count the number of characters
    num_chars++;

    // Count the number of spaces
    if (c == ' ' || c == '\n') {
      num_spaces++;
    }

    // Count the number of lines
    if (c == '\n') {
      num_lines++;
    }

    // Count the number of words
    if (c == ' ') {
      num_words++;
    }
  }

  // Close the file
  fclose(file);

  // Print the results
  printf("Number of words: %d\n", num_words);
  printf("Number of lines: %d\n", num_lines);
  printf("Number of characters: %d\n", num_chars);
  printf("Number of spaces: %d\n", num_spaces);

  return 0;
}