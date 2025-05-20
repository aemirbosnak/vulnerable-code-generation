//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_EMAIL_ADDRESS_LENGTH 256

// Function prototypes
int is_spam(char *email_address);

// Main function
int main() {
  // Define variables
  char email_address[MAX_EMAIL_ADDRESS_LENGTH];

  // Prompt the user for an email address
  printf("Enter an email address: ");
  scanf("%s", email_address);

  // Check if the email address is spam
  if (is_spam(email_address)) {
    printf("The email address is spam.\n");
  } else {
    printf("The email address is not spam.\n");
  }

  return 0;
}

// Function to check if an email address is spam
int is_spam(char *email_address) {
  // Define variables
  int i;
  int length;
  int score;

  // Initialize the score
  score = 0;

  // Check the length of the email address
  length = strlen(email_address);
  if (length > MAX_EMAIL_ADDRESS_LENGTH) {
    score += 1;
  }

  // Check for the presence of certain keywords in the email address
  for (i = 0; i < length; i++) {
    if (email_address[i] == 's' || email_address[i] == 'p' || email_address[i] == 'a' || email_address[i] == 'm') {
      score += 1;
    }
  }

  // Check for the presence of certain patterns in the email address
  if (strstr(email_address, "@free.com") != NULL) {
    score += 1;
  }
  if (strstr(email_address, "@myfreemails.com") != NULL) {
    score += 1;
  }
  if (strstr(email_address, "@youraccount.com") != NULL) {
    score += 1;
  }

  // Return the score
  return score;
}