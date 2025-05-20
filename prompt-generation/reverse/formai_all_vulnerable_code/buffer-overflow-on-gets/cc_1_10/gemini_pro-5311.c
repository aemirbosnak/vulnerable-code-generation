//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Declare an array to store the words
char words[MAX_WORD_LENGTH];

// Declare a variable to store the number of words
int wordCount = 0;

// Function to count the number of words in a string
int countWords(char *string) {
  // Initialize the word count to 0
  wordCount = 0;

  // Loop through the string until the end of the string is reached
  while (*string != '\0') {
    // If the current character is a letter, then increment the word count
    if (isalpha(*string)) {
      wordCount++;

      // Loop through the string until the end of the word is reached
      while (isalpha(*string)) {
        string++;
      }
    }

    // Skip over any non-letter characters
    while (!isalpha(*string)) {
      string++;
    }
  }

  // Return the word count
  return wordCount;
}

// Function to print the words in a string
void printWords(char *string) {
  // Initialize the word count to 0
  wordCount = 0;

  // Loop through the string until the end of the string is reached
  while (*string != '\0') {
    // If the current character is a letter, then increment the word count
    if (isalpha(*string)) {
      wordCount++;

      // Loop through the string until the end of the word is reached
      while (isalpha(*string)) {
        string++;
      }

      // Print the word
      printf("%s\n", words);
    }

    // Skip over any non-letter characters
    while (!isalpha(*string)) {
      string++;
    }
  }
}

// Main function
int main() {
  // Get the input string from the user
  printf("Enter a string: ");
  gets(words);

  // Count the number of words in the string
  int wordCount = countWords(words);

  // Print the number of words in the string
  printf("The string contains %d words.\n", wordCount);

  // Print the words in the string
  printf("The words in the string are:\n");
  printWords(words);

  return 0;
}