//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
// C Spam Detection System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a spam message
#define MAX_SPAM_SIZE 1024

// Define the number of features to use for spam detection
#define NUM_FEATURES 10

// Define the weights for each feature
float weights[NUM_FEATURES] = {
  0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0
};

// Calculate the score of a message
float calculate_score(char *message) {
  // Calculate the number of occurrences of each feature in the message
  int features[NUM_FEATURES];
  for (int i = 0; i < NUM_FEATURES; i++) {
    features[i] = 0;
  }
  // The "words" are the features
  char *words[] = {"love", "free", "money", "urgent", "click", "here", "dear", "friend", "win", "now"};
  for (int i = 0; i < NUM_FEATURES; i++) {
    char *word = words[i];
    int len = strlen(word);
    char *p = message;
    while ((p = strstr(p, word)) != NULL) {
      features[i]++;
      p += len;
    }
  }
  // Calculate the score of the message
  float score = 0.0;
  for (int i = 0; i < NUM_FEATURES; i++) {
    score += weights[i] * features[i];
  }
  return score;
}

// Classify a message as spam or not spam
int classify(char *message) {
  // Calculate the score of the message
  float score = calculate_score(message);

  // If the score is greater than 0.5, the message is classified as spam
  if (score > 0.5) {
    return 1;
  } else {
    return 0;
  }
}

// Main function
int main() {
  // Get the input message from the user
  char message[MAX_SPAM_SIZE];
  printf("Enter the message: ");
  scanf("%s", message);

  // Classify the message as spam or not spam
  int is_spam = classify(message);

  // Print the result
  if (is_spam) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}