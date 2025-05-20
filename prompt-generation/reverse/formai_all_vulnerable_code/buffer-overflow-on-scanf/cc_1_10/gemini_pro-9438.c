//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shock-tastic Spam Detection System v1.0

// Constants
#define MAX_WORD_LEN 20
#define MAX_WORDS 100
#define SPAM_THRESHOLD 0.5

// Global variables
char *words[MAX_WORDS];
int word_count;
double spam_score;

// Function prototypes
void init_words();
int is_spam(char *message);
void print_spam_score();

int main() {
  // Initialize the words
  init_words();

  // Get the message from the user
  char message[256];
  printf("Enter your message: ");
  scanf("%[^\n]s", message);

  // Check if the message is spam
  int is_spam_result = is_spam(message);

  // Print the spam score
  print_spam_score();

  // Display the result
  if (is_spam_result) {
    printf("HOLY SPAM! This message is definitely spam!\n");
  } else {
    printf("Whew! This message looks clean...\n");
  }

  return 0;
}

void init_words() {
  // Initialize the words array with common spam words
  words[0] = "free";
  words[1] = "money";
  words[2] = "click";
  words[3] = "here";
  words[4] = "offer";
  words[5] = "sale";
  words[6] = "urgent";
  words[7] = "limited";
  words[8] = "time";
  words[9] = "win";
  // ...

  // Set the word count
  word_count = 10;
}

int is_spam(char *message) {
  // Initialize the spam score
  spam_score = 0.0;

  // Tokenize the message
  char *token = strtok(message, " ");
  while (token != NULL) {
    // Check if the token is a spam word
    for (int i = 0; i < word_count; i++) {
      if (strcmp(token, words[i]) == 0) {
        // Increment the spam score
        spam_score += 1.0;
        break;
      }
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Check if the spam score is above the threshold
  return spam_score >= SPAM_THRESHOLD;
}

void print_spam_score() {
  printf("Spam score: %.2f\n", spam_score);
}