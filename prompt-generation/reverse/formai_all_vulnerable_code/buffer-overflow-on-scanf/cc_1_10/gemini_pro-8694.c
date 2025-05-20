//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SUMMARY_LENGTH 200

char *summarize_text(char *text, int summary_length) {
  // Split the text into sentences.
  char **sentences = malloc(sizeof(char *) * MAX_SENTENCE_LENGTH);
  int num_sentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = strdup(sentence);
    sentence = strtok(NULL, ".");
  }

  // Calculate the score of each sentence.
  int *scores = malloc(sizeof(int) * num_sentences);
  for (int i = 0; i < num_sentences; i++) {
    scores[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      if (strlen(word) >= 5) {
        scores[i]++;
      }
      word = strtok(NULL, " ");
    }
  }

  // Sort the sentences by score.
  for (int i = 0; i < num_sentences; i++) {
    for (int j = i + 1; j < num_sentences; j++) {
      if (scores[i] < scores[j]) {
        int temp = scores[i];
        scores[i] = scores[j];
        scores[j] = temp;
        char *temp_sentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp_sentence;
      }
    }
  }

  // Create the summary.
  char *summary = malloc(sizeof(char) * MAX_SUMMARY_LENGTH);
  int summary_length_so_far = 0;
  for (int i = 0; i < num_sentences; i++) {
    if (summary_length_so_far + strlen(sentences[i]) + 1 <= summary_length) {
      strcat(summary, sentences[i]);
      strcat(summary, ". ");
      summary_length_so_far += strlen(sentences[i]) + 1;
    } else {
      break;
    }
  }

  // Free the allocated memory.
  for (int i = 0; i < num_sentences; i++) {
    free(sentences[i]);
  }
  free(sentences);
  free(scores);

  // Return the summary.
  return summary;
}

int main() {
  // Get the text from the user.
  char *text = malloc(sizeof(char) * MAX_SENTENCE_LENGTH);
  printf("Enter the text you want to summarize: ");
  fgets(text, MAX_SENTENCE_LENGTH, stdin);

  // Get the desired summary length from the user.
  int summary_length;
  printf("Enter the desired summary length: ");
  scanf("%d", &summary_length);

  // Summarize the text.
  char *summary = summarize_text(text, summary_length);

  // Print the summary.
  printf("The summary is: %s", summary);

  // Free the allocated memory.
  free(text);
  free(summary);

  return 0;
}