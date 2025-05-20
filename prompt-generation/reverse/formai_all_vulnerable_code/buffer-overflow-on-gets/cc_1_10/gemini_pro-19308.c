//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

// Function to tokenize a sentence into words
char **tokenize(char *sentence) {
  char **words = malloc(MAX_SENTENCES * sizeof(char *));
  char *word = strtok(sentence, " ");
  int i = 0;
  while (word) {
    words[i] = word;
    i++;
    word = strtok(NULL, " ");
  }
  return words;
}

// Function to summarize a text
char *summarize(char *text) {
  // Tokenize the text into sentences
  char **sentences = malloc(MAX_SENTENCES * sizeof(char *));
  char *sentence = strtok(text, ".");
  int i = 0;
  while (sentence) {
    sentences[i] = sentence;
    i++;
    sentence = strtok(NULL, ".");
  }

  // Compute the frequency of each word in the text
  int *frequencies = malloc(MAX_SENTENCES * sizeof(int));
  for (i = 0; i < MAX_SENTENCES; i++) {
    char **words = tokenize(sentences[i]);
    for (int j = 0; j < MAX_SENTENCES; j++) {
      frequencies[j] += strcmp(words[j], words[i]) == 0;
    }
  }

  // Find the most frequent words in the text
  int max_frequency = 0;
  for (i = 0; i < MAX_SENTENCES; i++) {
    if (frequencies[i] > max_frequency) {
      max_frequency = frequencies[i];
    }
  }

  // Generate the summary
  char *summary = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
  for (i = 0; i < MAX_SENTENCES; i++) {
    if (frequencies[i] == max_frequency) {
      strcat(summary, sentences[i]);
      strcat(summary, ".");
    }
  }

  return summary;
}

int main() {
  // Get the input text from the user
  char *text = malloc(1000 * sizeof(char));
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize(text);

  // Print the summary
  printf("Summary: %s\n", summary);

  return 0;
}