//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char *text;
  int length, words, lines, characters, ignored;
  int i, j, inWord;

  // Get the text from the user
  printf("Enter your text:\n");
  text = malloc(1000);
  gets(text);

  // Initialize the variables
  length = strlen(text);
  words = 0;
  lines = 0;
  characters = 0;
  ignored = 0;
  inWord = 0;

  // Count the words, lines, and characters
  for (i = 0; i < length; i++) {
    // Ignore whitespace characters
    if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
      ignored++;
      continue;
    }

    // Count the characters
    characters++;

    // Count the lines
    if (text[i] == '\n') {
      lines++;
    }

    // Count the words
    if (!inWord) {
      words++;
      inWord = 1;
    }

    // Check if the current character is the last character in a word
    if (i == length - 1 || text[i + 1] == ' ' || text[i + 1] == '\t' || text[i + 1] == '\n') {
      inWord = 0;
    }
  }

  // Print the results
  printf("Words: %d\n", words);
  printf("Lines: %d\n", lines);
  printf("Characters: %d\n", characters);
  printf("Ignored characters: %d\n", ignored);

  // Free the allocated memory
  free(text);

  return 0;
}