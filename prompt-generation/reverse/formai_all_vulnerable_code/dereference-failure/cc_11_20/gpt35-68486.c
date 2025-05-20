//FormAI DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input size
#define MAX_INPUT_SIZE 1000

// Define the maximum number of sentences to output
#define MAX_SENTENCES 10

int main() {
  // Define variables
  char input[MAX_INPUT_SIZE];
  char *sentences[MAX_SENTENCES];
  int sentence_lengths[MAX_SENTENCES];
  int total_sentences = 0;
  int total_length = 0;
  int sentence_start = 0;
  int sentence_end = 0;

  // Prompt user for input
  printf("Enter text to summarize:\n");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Remove newlines from input
  input[strcspn(input, "\n")] = 0;

  // Find sentence boundaries
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == '.' || (input[i] == '?' && input[i+1] == ' ') || (input[i] == '!' && input[i+1] == ' ')) {
      // Add sentence to sentences array
      int length = i - sentence_start + 1;
      char *sentence = (char *) malloc(length + 1);
      strncpy(sentence, input + sentence_start, length);
      sentence[length] = '\0';
      sentences[total_sentences] = sentence;
      sentence_lengths[total_sentences] = length;
      total_sentences++;

      // Update total length and sentence boundaries
      total_length += length;
      sentence_start = i+2;
      sentence_end = i+1;

      // Stop if maximum number of sentences reached
      if (total_sentences == MAX_SENTENCES) {
        break;
      }
    } else if (i == strlen(input) - 1) {
      // Add last sentence to sentences array
      int length = i - sentence_start + 2;
      char *sentence = (char *) malloc(length + 1);
      strncpy(sentence, input + sentence_start, length - 1);
      sentence[length - 1] = '.';
      sentence[length] = '\0';
      sentences[total_sentences] = sentence;
      sentence_lengths[total_sentences] = length;
      total_sentences++;

      // Update total length
      total_length += length;
    }
  }

  // Calculate average length of sentences
  float avg_length = (float) total_length / total_sentences;

  // Summarize sentences based on average length
  printf("Summary:\n");
  for (int i = 0; i < total_sentences; i++) {
    if (sentence_lengths[i] <= avg_length) {
      printf("%s", sentences[i]);
    }
  }

  // Free memory allocated for sentences
  for (int i = 0; i < total_sentences; i++) {
    free(sentences[i]);
  }

  return 0;
}