//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the maximum number of spam words
#define MAX_SPAM_WORDS 100

// Define the array of spam words
char *spam_words[] = {"free", "money", "click", "here", "win", "prize", "offer", "urgent", "important", "limited time"};

// Function to check if a message is spam
int is_spam(char *message) {
  // Tokenize the message
  char *tokens[MAX_MESSAGE_LENGTH];
  char *token = strtok(message, " ");
  int i = 0;
  while (token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, " ");
  }

  // Check if any of the tokens are spam words
  for (int j = 0; j < i; j++) {
    for (int k = 0; k < MAX_SPAM_WORDS; k++) {
      if (strcmp(tokens[j], spam_words[k]) == 0) {
        return 1;
      }
    }
  }

  // If no spam words are found, return 0
  return 0;
}

// Main function
int main() {
  // Get the message from the user
  char message[MAX_MESSAGE_LENGTH];
  printf("Enter the message: ");
  gets(message);

  // Check if the message is spam
  if (is_spam(message)) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}