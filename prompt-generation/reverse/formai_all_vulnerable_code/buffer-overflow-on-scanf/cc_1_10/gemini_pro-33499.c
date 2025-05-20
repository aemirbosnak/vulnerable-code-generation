//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 256

// Define the number of keywords to check for
#define NUM_KEYWORDS 10

// Define the keywords to check for
char *keywords[] = {"free", "money", "win", "prize", "offer", "sale", "limited time", "act now", "click here"};

// Function to check if an email address is valid
int is_valid_email(char *email) {
  // Check if the email address is empty
  if (strlen(email) == 0) {
    return 0;
  }

  // Check if the email address is too long
  if (strlen(email) > MAX_EMAIL_LENGTH) {
    return 0;
  }

  // Check if the email address contains any invalid characters
  for (int i = 0; i < strlen(email); i++) {
    if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '_') {
      return 0;
    }
  }

  // Check if the email address contains an '@' symbol
  if (strchr(email, '@') == NULL) {
    return 0;
  }

  // Check if the email address contains a '.' symbol
  if (strchr(email, '.') == NULL) {
    return 0;
  }

  // Return 1 if the email address is valid
  return 1;
}

// Function to check if an email message contains any spam keywords
int is_spam(char *message) {
  // Check if the message is empty
  if (strlen(message) == 0) {
    return 0;
  }

  // Convert the message to lowercase
  char *lowercase_message = malloc(strlen(message) + 1);
  strcpy(lowercase_message, message);
  for (int i = 0; i < strlen(lowercase_message); i++) {
    lowercase_message[i] = tolower(lowercase_message[i]);
  }

  // Check if the message contains any spam keywords
  for (int i = 0; i < NUM_KEYWORDS; i++) {
    if (strstr(lowercase_message, keywords[i]) != NULL) {
      free(lowercase_message);
      return 1;
    }
  }

  // Free the memory allocated for the lowercase message
  free(lowercase_message);

  // Return 0 if the message does not contain any spam keywords
  return 0;
}

// Main function
int main() {
  // Get the email address from the user
  char email[MAX_EMAIL_LENGTH];
  printf("Enter your email address: ");
  scanf("%s", email);

  // Check if the email address is valid
  if (!is_valid_email(email)) {
    printf("Invalid email address.\n");
    return 1;
  }

  // Get the email message from the user
  char message[4096];
  printf("Enter the email message: ");
  scanf(" %[^\n]s", message);

  // Check if the email message contains any spam keywords
  if (is_spam(message)) {
    printf("This email is spam.\n");
  } else {
    printf("This email is not spam.\n");
  }

  return 0;
}