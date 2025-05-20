//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *string) {
  int wordCount = 0;
  int inWord = 0;

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
      inWord = 0;
    } else if (!inWord) {
      wordCount++;
      inWord = 1;
    }
  }

  return wordCount;
}

// Function to print a message of gratitude
void printGratitude() {
  printf("Thank you for using the C Word Count Tool!\n");
  printf("We are grateful for your support.\n");
  printf("We hope you find this tool helpful.\n");
  printf("Please let us know if you have any questions or feedback.\n");
}

// Main function
int main() {
  // Declare variables
  char string[100];
  int wordCount;

  // Get the string from the user
  printf("Please enter a string: ");
  scanf("%s", string);

  // Count the number of words in the string
  wordCount = countWords(string);

  // Print the word count
  printf("The string \"%s\" contains %d words.\n", string, wordCount);

  // Print a message of gratitude
  printGratitude();

  return 0;
}