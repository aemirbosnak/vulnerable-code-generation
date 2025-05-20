//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input text
#define MAX_SIZE 10000

// Function to count the number of words in a string
int countWords(char *text) {
  int wordCount = 0;
  int inWord = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] != ' ' && text[i] != '\n' && text[i] != '\t') {
      if (!inWord) {
        wordCount++;
        inWord = 1;
      }
    } else {
      inWord = 0;
    }
  }
  return wordCount;
}

// Function to count the number of characters in a string
int countCharacters(char *text) {
  return strlen(text);
}

// Function to count the number of lines in a string
int countLines(char *text) {
  int lineCount = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '\n') {
      lineCount++;
    }
  }
  return lineCount;
}

// Main function
int main() {
  // Get the input text from the user
  char text[MAX_SIZE];
  printf("Enter the text:\n");
  scanf("%[^\n]s", text);

  // Count the number of words, characters, and lines in the text
  int wordCount = countWords(text);
  int characterCount = countCharacters(text);
  int lineCount = countLines(text);

  // Print the results
  printf("Word count: %d\n", wordCount);
  printf("Character count: %d\n", characterCount);
  printf("Line count: %d\n", lineCount);

  return 0;
}