//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text, int length) {
  // Base case: if the text is empty, return an empty string
  if (length == 0) {
    return "";
  }

  // Find the first sentence in the text
  char *sentence = strtok(text, ".");

  // Find the first important word in the sentence
  char *importantWord = strtok(sentence, " ");

  // Summarize the sentence
  char *summary = malloc(strlen(importantWord) + 1);
  strcpy(summary, importantWord);

  // Summarize the rest of the text
  char *restOfText = strtok(NULL, ".");
  char *restOfSummary = summarize(restOfText, strlen(restOfText));

  // Concatenate the summary of the sentence and the rest of the text
  char *finalSummary = malloc(strlen(summary) + strlen(restOfSummary) + 1);
  strcpy(finalSummary, summary);
  strcat(finalSummary, restOfSummary);

  // Return the final summary
  return finalSummary;
}

// Main function
int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text to summarize: ");
  gets(text);

  // Summarize the text
  char *summary = summarize(text, strlen(text));

  // Print the summary
  printf("Summary: %s", summary);

  // Free the memory
  free(text);
  free(summary);

  return 0;
}