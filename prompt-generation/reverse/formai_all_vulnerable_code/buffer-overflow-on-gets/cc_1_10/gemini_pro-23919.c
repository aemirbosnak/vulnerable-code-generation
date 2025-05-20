//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tokenize the input text into words
char **tokenize(char *text) {
  char **tokens = malloc(sizeof(char *) * 100);
  int num_tokens = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }
  tokens[num_tokens] = NULL;
  return tokens;
}

// Calculate the frequency of each word in the text
int *calculate_frequencies(char **tokens) {
  int *frequencies = malloc(sizeof(int) * 100);
  for (int i = 0; i < 100; i++) {
    frequencies[i] = 0;
  }
  for (int i = 0; tokens[i] != NULL; i++) {
    frequencies[i]++;
  }
  return frequencies;
}

// Find the most frequent words in the text
char **find_most_frequent_words(char **tokens, int *frequencies) {
  char **most_frequent_words = malloc(sizeof(char *) * 10);
  int max_frequency = 0;
  for (int i = 0; i < 100; i++) {
    if (frequencies[i] > max_frequency) {
      max_frequency = frequencies[i];
    }
  }
  int num_most_frequent_words = 0;
  for (int i = 0; tokens[i] != NULL; i++) {
    if (frequencies[i] == max_frequency) {
      most_frequent_words[num_most_frequent_words++] = tokens[i];
    }
  }
  most_frequent_words[num_most_frequent_words] = NULL;
  return most_frequent_words;
}

// Generate a summary of the text
char *generate_summary(char **most_frequent_words) {
  char *summary = malloc(sizeof(char) * 1000);
  strcpy(summary, "The most frequent words in the text are: ");
  for (int i = 0; most_frequent_words[i] != NULL; i++) {
    strcat(summary, most_frequent_words[i]);
    strcat(summary, " ");
  }
  return summary;
}

int main() {
  // Get the input text from the user
  char *text = malloc(sizeof(char) * 1000);
  printf("Enter the input text: ");
  gets(text);

  // Tokenize the input text into words
  char **tokens = tokenize(text);

  // Calculate the frequency of each word in the text
  int *frequencies = calculate_frequencies(tokens);

  // Find the most frequent words in the text
  char **most_frequent_words = find_most_frequent_words(tokens, frequencies);

  // Generate a summary of the text
  char *summary = generate_summary(most_frequent_words);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the allocated memory
  free(text);
  free(tokens);
  free(frequencies);
  free(most_frequent_words);
  free(summary);

  return 0;
}