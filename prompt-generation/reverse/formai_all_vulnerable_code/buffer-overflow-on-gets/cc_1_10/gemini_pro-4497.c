//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a spam message
#define MAX_SPAM_LENGTH 1024

// Define the minimum number of spammy words required to classify a message as spam
#define MIN_SPAMMY_WORDS 3

// Define an array of spammy words
const char *spammyWords[] = {
  "free",
  "money",
  "win",
  "prize",
  "click here",
  "unsubscribe",
  "urgent",
  "limited time offer",
  "act now",
  "don't miss out"
};

// Define the number of spammy words in the array
#define NUM_SPAMMY_WORDS (sizeof(spammyWords) / sizeof(char *))

// Function to check if a message is spam
int isSpam(const char *message) {
  // Initialize the count of spammy words to 0
  int spammyWordsCount = 0;

  // Iterate over the array of spammy words
  for (int i = 0; i < NUM_SPAMMY_WORDS; i++) {
    // Check if the message contains the current spammy word
    if (strstr(message, spammyWords[i]) != NULL) {
      // Increment the count of spammy words
      spammyWordsCount++;
    }
  }

  // Return true if the message contains at least the minimum number of spammy words
  return spammyWordsCount >= MIN_SPAMMY_WORDS;
}

// Main function
int main() {
  // Get the message from the user
  char message[MAX_SPAM_LENGTH];
  printf("Enter the message: ");
  gets(message);

  // Check if the message is spam
  int isSpamResult = isSpam(message);

  // Print the result
  if (isSpamResult) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}