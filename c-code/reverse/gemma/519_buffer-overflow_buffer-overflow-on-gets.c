#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *summarize_text(int max_sentences) {
  char **sentences = NULL;
  int num_sentences = 0;
  char summary[1000] = "";

  // Allocate memory for sentences
  sentences = malloc(max_sentences * sizeof(char *));

  // Get sentences from the user
  for (int i = 0; i < max_sentences && sentences; i++) {
    sentences[i] = malloc(256);
    printf("Enter sentence %d: ", i + 1);
    scanf("%s", sentences[i]);
  }

  // Summarize each sentence
  for (int i = 0; sentences && num_sentences < max_sentences; i++) {
    char *sentence = sentences[i];
    int sentence_length = strlen(sentence);
    int summary_length = sentence_length / 3;
    if (summary_length > 0) {
      snprintf(summary, 1000 - num_sentences * summary_length, "%s ", summary);
      num_sentences++;
    }
  }

  // Free memory
  for (int i = 0; sentences && sentences[i]; i++) {
    free(sentences[i]);
  }
  free(sentences);

  return summary;
}

int main() {
  int max_sentences = 5;
  char *summary = summarize_text(max_sentences);
  printf("Summary:\n%s", summary);
  free(summary);

  return 0;
}
