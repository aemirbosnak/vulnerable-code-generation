//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text) {
  // Allocate memory for the summary
  char *summary = malloc(strlen(text) / 2 + 1);
  if (summary == NULL) {
    return NULL;
  }

  // Initialize the summary to an empty string
  summary[0] = '\0';

  // Tokenize the text into words
  char *tokens[1000];
  int num_tokens = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Find the most frequent words
  int frequencies[1000];
  for (int i = 0; i < num_tokens; i++) {
    frequencies[i] = 0;
  }
  for (int i = 0; i < num_tokens; i++) {
    for (int j = 0; j < num_tokens; j++) {
      if (strcmp(tokens[i], tokens[j]) == 0) {
        frequencies[i]++;
      }
    }
  }

  // Sort the words by frequency
  for (int i = 0; i < num_tokens; i++) {
    for (int j = i + 1; j < num_tokens; j++) {
      if (frequencies[i] < frequencies[j]) {
        int temp = frequencies[i];
        frequencies[i] = frequencies[j];
        frequencies[j] = temp;
        char *temp2 = tokens[i];
        tokens[i] = tokens[j];
        tokens[j] = temp2;
      }
    }
  }

  // Add the most frequent words to the summary
  int num_words = 0;
  for (int i = 0; i < num_tokens; i++) {
    if (num_words >= 10) {
      break;
    }
    strcat(summary, tokens[i]);
    strcat(summary, " ");
    num_words++;
  }

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize(text);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the memory allocated for the summary
  free(summary);

  return 0;
}