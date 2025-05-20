//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of characters in a token.
#define MAX_TOKEN_LENGTH 256

// Define the number of tokens to be checked.
#define NUM_TOKENS 3

// Define the list of tokens to be checked.
char *tokens[] = {"free", "money", "offer"};

// Define the function to check if a string contains a spam token.
bool contains_spam(char *str) {
  // Initialize the flag to indicate that no spam token has been found.
  bool found = false;

  // Iterate over the list of tokens.
  for (int i = 0; i < NUM_TOKENS; i++) {
    // Check if the token is present in the string.
    if (strstr(str, tokens[i]) != NULL) {
      // Set the flag to indicate that a spam token has been found.
      found = true;

      // Break out of the loop.
      break;
    }
  }

  // Return the flag.
  return found;
}

// Define the main function.
int main() {
  // Get the input string from the user.
  char str[MAX_TOKEN_LENGTH];
  printf("Enter a string: ");
  scanf("%s", str);

  // Check if the string contains a spam token.
  bool spam = contains_spam(str);

  // Print the result.
  if (spam) {
    printf("The string contains spam.\n");
  } else {
    printf("The string does not contain spam.\n");
  }

  // Return 0 to indicate that the program has terminated successfully.
  return 0;
}