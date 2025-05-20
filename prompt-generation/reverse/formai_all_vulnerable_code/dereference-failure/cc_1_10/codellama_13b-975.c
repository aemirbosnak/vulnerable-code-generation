//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: secure
// C Word Count Tool Example Program in Secure Style
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to count the number of words in a string
int count_words(char *str) {
  int count = 0;
  char *word = strtok(str, " ");
  while (word != NULL) {
    count++;
    word = strtok(NULL, " ");
  }
  return count;
}

// Function to count the number of characters in a string
int count_chars(char *str) {
  int count = 0;
  while (*str != '\0') {
    count++;
    str++;
  }
  return count;
}

// Function to count the number of lines in a string
int count_lines(char *str) {
  int count = 0;
  while (*str != '\0') {
    if (*str == '\n') {
      count++;
    }
    str++;
  }
  return count;
}

// Main function
int main(int argc, char **argv) {
  // Check if the correct number of arguments are provided
  if (argc != 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  // Open the file and read its contents
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }
  char *buffer = malloc(1024 * sizeof(char));
  fread(buffer, 1, 1024, file);
  fclose(file);

  // Count the number of words, characters, and lines in the file
  int words = count_words(buffer);
  int chars = count_chars(buffer);
  int lines = count_lines(buffer);

  // Print the results
  printf("File %s contains:\n", argv[1]);
  printf(" - %d words\n", words);
  printf(" - %d characters\n", chars);
  printf(" - %d lines\n", lines);

  // Free the memory allocated for the buffer
  free(buffer);
  return 0;
}