//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome the user to our text processing extravaganza
  printf("Welcome to the Text Processing Extravaganza!\n");
  printf("Where we'll twist, turn, and transform your words with glee.\n");

  // Get the user's input text
  char input[1000];
  printf("Enter your text (up to 1000 characters): ");
  fgets(input, sizeof(input), stdin);

  // Trim any leading or trailing whitespace
  size_t trimmed_length = strlen(input);
  while (trimmed_length > 0 && (input[trimmed_length - 1] == ' ' || input[trimmed_length - 1] == '\n')) {
    input[--trimmed_length] = '\0';
  }

  // Show the user the trimmed text
  printf("\nTrimmed text:\n%s\n", input);

  // Remove all punctuation from the text
  char* punctuation = ".,:;?!()[]{}<>\"'`";
  size_t input_length = strlen(input);
  for (size_t i = 0; i < input_length; i++) {
    if (strchr(punctuation, input[i]) != NULL) {
      input[i] = ' ';
    }
  }

  // Show the user the punctuation-free text
  printf("\nPunctuation-free text:\n%s\n", input);

  // Convert the text to uppercase
  for (size_t i = 0; i < input_length; i++) {
    input[i] = toupper(input[i]);
  }

  // Show the user the uppercase text
  printf("\nUppercase text:\n%s\n", input);

  // Reverse the order of the words in the text
  char* words[100];
  size_t num_words = 0;
  char* word = strtok(input, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }
  for (size_t i = num_words - 1; i >= 0; i--) {
    printf("%s ", words[i]);
  }
  printf("\n");

  // Thank the user for playing
  printf("\nThanks for playing the Text Processing Extravaganza!\n");
  return 0;
}