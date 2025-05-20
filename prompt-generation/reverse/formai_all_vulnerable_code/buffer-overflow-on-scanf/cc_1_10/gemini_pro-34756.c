//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_SPAM_SCORE 100

// Global variables
char *spam_words[MAX_SPAM_WORDS];
int spam_scores[MAX_SPAM_WORDS];

// Function prototypes
void init_spam_filter();
int check_spam(char *mail_content);

// Main function
int main() {
  // Initialize the spam filter
  init_spam_filter();

  // Read the email content from the user
  char *mail_content = (char *)malloc(1024);
  printf("Enter the email content:\n");
  scanf("%s", mail_content);

  // Check if the email is spam
  int spam_score = check_spam(mail_content);

  // Print the spam score
  printf("Spam score: %d\n", spam_score);

  // Free the allocated memory
  free(mail_content);

  return 0;
}

// Function to initialize the spam filter
void init_spam_filter() {
  // Initialize the spam words and scores
  spam_words[0] = "free";
  spam_scores[0] = 20;
  spam_words[1] = "discount";
  spam_scores[1] = 15;
  spam_words[2] = "win";
  spam_scores[2] = 10;
  // ... Add more spam words and scores here ...
}

// Function to check if the email is spam
int check_spam(char *mail_content) {
  // Initialize the spam score
  int spam_score = 0;

  // Tokenize the email content
  char *token = strtok(mail_content, " ");
  while (token != NULL) {
    // Check if the token is a spam word
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
      if (strcmp(token, spam_words[i]) == 0) {
        // Increment the spam score
        spam_score += spam_scores[i];
        break;
      }
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Return the spam score
  return spam_score;
}