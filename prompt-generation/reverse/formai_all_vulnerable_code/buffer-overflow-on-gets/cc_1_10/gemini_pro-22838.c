//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text) {
  // Check if the text is valid
  if (text == NULL || strlen(text) == 0) {
    return NULL;
  }

  // Tokenize the text into sentences
  char **sentences = malloc(sizeof(char *) * 100);
  int num_sentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Calculate the frequency of each sentence
  int *frequencies = malloc(sizeof(int) * num_sentences);
  for (int i = 0; i < num_sentences; i++) {
    frequencies[i] = 0;
    for (int j = 0; j < num_sentences; j++) {
      if (strcmp(sentences[i], sentences[j]) == 0) {
        frequencies[i]++;
      }
    }
  }

  // Sort the sentences by frequency
  for (int i = 0; i < num_sentences - 1; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (frequencies[i] < frequencies[j]) {
        int temp = frequencies[i];
        frequencies[i] = frequencies[j];
        frequencies[j] = temp;
        char *temp_sentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp_sentence;
      }
    }
  }

  // Create the summary
  char *summary = malloc(sizeof(char) * 1000);
  strcpy(summary, "");
  for (int i = 0; i < num_sentences; i++) {
    if (strlen(summary) + strlen(sentences[i]) + 1 < 1000) {
      strcat(summary, sentences[i]);
      strcat(summary, ". ");
    }
  }

  // Free the allocated memory
  free(sentences);
  free(frequencies);

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char *text = malloc(sizeof(char) * 1000);
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize(text);

  // Print the summary
  printf("The summary is: %s\n", summary);

  // Free the allocated memory
  free(text);
  free(summary);

  return 0;
}