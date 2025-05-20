//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {
  int count = 0; // Initialize the word count to 0
  int inWord = 0; // Initialize the in-word flag to 0

  // Iterate over each character in the string
  for (int i = 0; i < strlen(str); i++) {
    // Check if the current character is a letter
    if (isalpha(str[i])) {
      // If the current character is a letter, set the in-word flag to 1
      inWord = 1;
    } else {
      // If the current character is not a letter, check if the in-word flag is set
      if (inWord) {
        // If the in-word flag is set, increment the word count and set the in-word flag to 0
        count++;
        inWord = 0;
      }
    }
  }

  // Check if the in-word flag is set at the end of the string
  if (inWord) {
    // If the in-word flag is set at the end of the string, increment the word count
    count++;
  }

  // Return the word count
  return count;
}

// Function to test the word count function
int main() {
  // Declare a string to store the input
  char str[100];

  // Prompt the user to enter a string
  printf("Enter a string: ");
  gets(str);

  // Count the number of words in the string
  int wordCount = countWords(str);

  // Print the word count
  printf("The number of words in the string is: %d\n", wordCount);

  return 0;
}