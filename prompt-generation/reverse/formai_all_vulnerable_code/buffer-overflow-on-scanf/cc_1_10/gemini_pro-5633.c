//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the spam filter function
int is_spam(char *message);

int main() {
  // Get the message from the user
  char message[1024];
  printf("Enter the message: ");
  scanf("%s", message);

  // Check if the message is spam
  int result = is_spam(message);

  // Print the result
  if (result == 1) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}

// Implement the spam filter function
int is_spam(char *message) {
  // Convert the message to lowercase
  char *lowercase_message = malloc(strlen(message) + 1);
  strcpy(lowercase_message, message);
  for (int i = 0; lowercase_message[i]; i++) {
    lowercase_message[i] = tolower(lowercase_message[i]);
  }

  // Check for common spam keywords
  char *spam_keywords[] = {"free", "money", "win", "prize", "urgent", "act now", "click here"};
  int num_spam_keywords = sizeof(spam_keywords) / sizeof(char *);
  for (int i = 0; i < num_spam_keywords; i++) {
    if (strstr(lowercase_message, spam_keywords[i]) != NULL) {
      free(lowercase_message);
      return 1; // Spam detected
    }
  }

  // Check for excessive punctuation
  int num_punctuation_marks = 0;
  for (int i = 0; message[i]; i++) {
    if (ispunct(message[i])) {
      num_punctuation_marks++;
    }
  }
  if (num_punctuation_marks > strlen(message) / 10) {
    free(lowercase_message);
    return 1; // Spam detected
  }

  // Check for suspicious links
  char *links[100];
  int num_links = 0;
  char *start = message;
  while ((start = strstr(start, "http")) != NULL) {
    links[num_links++] = start;
    start++;
  }
  if (num_links > 5) {
    free(lowercase_message);
    return 1; // Spam detected
  }

  // Check for a suspicious sender address
  char *sender_address = strstr(message, "From: ");
  if (sender_address == NULL) {
    free(lowercase_message);
    return 1; // Spam detected
  }
  sender_address += 6;
  if (strstr(sender_address, "@unknown.com") != NULL || strstr(sender_address, "@spam.com") != NULL) {
    free(lowercase_message);
    return 1; // Spam detected
  }

  // No spam detected
  free(lowercase_message);
  return 0;
}