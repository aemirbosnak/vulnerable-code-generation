//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SUMMARY_LENGTH 1000

// Function to summarize a text
char *summarize_text(char *text) {
  // Tokenize the text into sentences
  char **sentences = malloc(sizeof(char *) * 100);
  int num_sentences = 0;
  char *token = strtok(text, ".");
  while (token != NULL) {
    sentences[num_sentences++] = token;
    token = strtok(NULL, ".");
  }

  // Calculate the importance of each sentence
  int *sentence_importances = malloc(sizeof(int) * num_sentences);
  for (int i = 0; i < num_sentences; i++) {
    int num_words = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      num_words++;
      word = strtok(NULL, " ");
    }
    sentence_importances[i] = num_words;
  }

  // Sort the sentences by importance
  for (int i = 0; i < num_sentences - 1; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (sentence_importances[i] < sentence_importances[j]) {
        int temp = sentence_importances[i];
        sentence_importances[i] = sentence_importances[j];
        sentence_importances[j] = temp;
        char *temp_sentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp_sentence;
      }
    }
  }

  // Generate the summary
  char *summary = malloc(sizeof(char) * MAX_SUMMARY_LENGTH);
  int summary_length = 0;
  for (int i = 0; i < num_sentences; i++) {
    if (summary_length + strlen(sentences[i]) + 1 < MAX_SUMMARY_LENGTH) {
      strcat(summary, sentences[i]);
      strcat(summary, ". ");
      summary_length += strlen(sentences[i]) + 1;
    } else {
      break;
    }
  }

  // Free the allocated memory
  free(sentences);
  free(sentence_importances);

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text to be summarized from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  // Free the allocated memory
  free(summary);

  return 0;
}