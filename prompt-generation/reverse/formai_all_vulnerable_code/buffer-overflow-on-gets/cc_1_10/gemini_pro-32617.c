//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the summary of a text
char* summarize_text(char* text, int num_sentences) {
  // Check if the input is valid
  if (text == NULL || num_sentences <= 0) {
    return NULL;
  }

  // Tokenize the text into sentences
  char** sentences = strtok(text, ".!?");

  // Check if the number of sentences is greater than the number of sentences we want to summarize
  if (num_sentences > strlen(sentences)) {
    return NULL;
  }

  // Get the summary sentences
  char* summary = malloc(sizeof(char) * 1024);
  for (int i = 0; i < num_sentences; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, ". ");
  }

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1024];
  printf("Enter the text you want to summarize: ");
  gets(text);

  // Get the number of sentences the user wants to summarize
  int num_sentences;
  printf("Enter the number of sentences you want to summarize: ");
  scanf("%d", &num_sentences);

  // Get the summary of the text
  char* summary = summarize_text(text, num_sentences);

  // Print the summary
  printf("Summary: %s", summary);

  // Free the allocated memory
  free(summary);

  return 0;
}