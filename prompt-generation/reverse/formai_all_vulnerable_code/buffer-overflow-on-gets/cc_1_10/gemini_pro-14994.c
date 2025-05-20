//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize_text(char *text) {
  // Allocate memory for the summarized text
  char *summary = malloc(strlen(text) / 2 + 1);

  // Create an array of sentences
  char **sentences = malloc(100 * sizeof(char *));
  int num_sentences = 0;

  // Tokenize the text into sentences
  char *token = strtok(text, ".");
  while (token != NULL) {
    sentences[num_sentences] = token;
    num_sentences++;
    token = strtok(NULL, ".");
  }

  // Find the most important sentences
  int *important_sentences = malloc(num_sentences * sizeof(int));
  int num_important_sentences = 0;
  for (int i = 0; i < num_sentences; i++) {
    int score = 0;

    // Check if the sentence contains any important keywords
    char *keywords[] = {"important", "key", "information", "result"};
    for (int j = 0; j < 4; j++) {
      if (strstr(sentences[i], keywords[j]) != NULL) {
        score++;
      }
    }

    // Check if the sentence is long and complex
    int num_words = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      num_words++;
      word = strtok(NULL, " ");
    }
    if (num_words > 10) {
      score++;
    }

    // Check if the sentence contains a question mark
    if (strstr(sentences[i], "?") != NULL) {
      score++;
    }

    // Check if the sentence is the first sentence of a paragraph
    if (i == 0 || sentences[i - 1][strlen(sentences[i - 1]) - 1] == '\n') {
      score++;
    }

    // Add the sentence to the list of important sentences if it has a high score
    if (score > 2) {
      important_sentences[num_important_sentences] = i;
      num_important_sentences++;
    }
  }

  // Create the summary
  int summary_length = 0;
  for (int i = 0; i < num_important_sentences; i++) {
    summary_length += strlen(sentences[important_sentences[i]]);
  }
  summary_length++; // For the null-terminator

  // Copy the important sentences to the summary
  int index = 0;
  for (int i = 0; i < num_important_sentences; i++) {
    strcpy(&summary[index], sentences[important_sentences[i]]);
    index += strlen(sentences[important_sentences[i]]);
    summary[index++] = '\n';
  }
  summary[index] = '\0';

  // Free memory
  free(sentences);
  free(important_sentences);

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
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  // Free memory
  free(summary);

  return 0;
}