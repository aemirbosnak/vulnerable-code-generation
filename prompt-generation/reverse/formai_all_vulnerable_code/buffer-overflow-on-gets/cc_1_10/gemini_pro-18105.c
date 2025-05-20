//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char* summarize(char* text, int length) {
  // Create a new string to store the summary
  char* summary = (char*)malloc(length / 2 + 1);

  // Initialize the summary to an empty string
  summary[0] = '\0';

  // Iterate over the text and add the most important words to the summary
  int i = 0;
  int j = 0;
  while (i < length) {
    // Get the next word from the text
    char word[100];
    int k = 0;
    while (i < length && text[i] != ' ' && text[i] != '\n') {
      word[k++] = text[i++];
    }
    word[k] = '\0';

    // Check if the word is already in the summary
    int found = 0;
    for (int l = 0; l < j; l++) {
      if (strcmp(word, summary[l]) == 0) {
        found = 1;
        break;
      }
    }

    // If the word is not already in the summary, add it
    if (!found) {
      strcpy(summary[j++], word);
    }

    // Skip over the spaces and newlines
    while (i < length && (text[i] == ' ' || text[i] == '\n')) {
      i++;
    }
  }

  // Terminate the summary with a null character
  summary[j] = '\0';

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text to be summarized from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Get the length of the text
  int length = strlen(text);

  // Summarize the text
  char* summary = summarize(text, length);

  // Print the summary to the console
  printf("Summary: %s", summary);

  // Free the memory allocated for the summary
  free(summary);

  return 0;
}