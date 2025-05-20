//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
// Ada Lovelace's C Spam Detection System

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of a spam word
#define MAX_SPAM_WORD_LENGTH 20

// Define the maximum number of spam words in a message
#define MAX_SPAM_WORDS 100

// Define the list of spam words
char *spam_words[] = {
  "free", "money", "win", "prize", "offer",
  "click here", "limited time", "act now", "don't miss out", "special offer"
};

// Function to check if a word is in the spam word list
int is_spam_word(char *word) {
  for (int i = 0; i < MAX_SPAM_WORDS; i++) {
    if (strcmp(word, spam_words[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a message is spam
int is_spam(char *message) {
  // Tokenize the message into words
  char *words[MAX_SPAM_WORDS];
  char *token = strtok(message, " ");
  int word_count = 0;
  while (token != NULL) {
    words[word_count++] = token;
    token = strtok(NULL, " ");
  }

  // Check if any of the words in the message are in the spam word list
  for (int i = 0; i < word_count; i++) {
    if (is_spam_word(words[i])) {
      return 1;
    }
  }

  // The message is not spam
  return 0;
}

// Main function
int main() {
  // Get the message from the user
  char message[1024];
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