//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the word count to 0
int word_count = 0;

// Function to count the number of words in a string
int count_words(char *string) {
  // Check if the string is empty
  if (string[0] == '\0') {
    return 0;
  }

  // Split the string into words by spaces
  char *words[100];
  int word_index = 0;
  char *word = strtok(string, " ");
  while (word != NULL) {
    words[word_index] = word;
    word_index++;
    word = strtok(NULL, " ");
  }

  // Count the number of words in the array
  word_count = word_index;

  // Return the word count
  return word_count;
}

// Function to print the word count
void print_word_count() {
  printf("The word count is: %d\n", word_count);
}

// Main function
int main() {
  // Get the input string from the user
  char string[100];
  printf("Enter a string: ");
  gets(string);

  // Count the number of words in the string
  count_words(string);

  // Print the word count
  print_word_count();

  return 0;
}