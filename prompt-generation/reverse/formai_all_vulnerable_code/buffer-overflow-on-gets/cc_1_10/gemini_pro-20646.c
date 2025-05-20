//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 100

// Function to summarize a text
char* summarize_text(char* text) {
  // Split the text into sentences
  char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
  int num_sentences = 0;

  char* token = strtok(text, ".");
  while (token != NULL) {
    strcpy(sentences[num_sentences++], token);
    token = strtok(NULL, ".");
  }

  // Calculate the frequency of each sentence
  int sentence_frequencies[MAX_SENTENCES];
  memset(sentence_frequencies, 0, sizeof(sentence_frequencies));

  for (int i = 0; i < num_sentences; i++) {
    for (int j = 0; j < num_sentences; j++) {
      if (strcmp(sentences[i], sentences[j]) == 0) {
        sentence_frequencies[i]++;
      }
    }
  }

  // Find the most frequent sentences
  int max_frequency = 0;
  int most_frequent_sentences[MAX_SENTENCES];
  int num_most_frequent_sentences = 0;

  for (int i = 0; i < num_sentences; i++) {
    if (sentence_frequencies[i] > max_frequency) {
      max_frequency = sentence_frequencies[i];
      num_most_frequent_sentences = 0;
      most_frequent_sentences[num_most_frequent_sentences++] = i;
    } else if (sentence_frequencies[i] == max_frequency) {
      most_frequent_sentences[num_most_frequent_sentences++] = i;
    }
  }

  // Create the summary
  char summary[MAX_SENTENCE_LENGTH * num_most_frequent_sentences];
  strcpy(summary, "");

  for (int i = 0; i < num_most_frequent_sentences; i++) {
    strcat(summary, sentences[most_frequent_sentences[i]]);
    strcat(summary, ". ");
  }

  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char* summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  return 0;
}