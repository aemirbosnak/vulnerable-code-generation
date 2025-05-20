//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

int main() {
  char document[MAX_WORDS*MAX_SENTENCES];
  int sentence_count = 0;
  char *sentences[MAX_SENTENCES];
  char *words[MAX_SENTENCES][MAX_WORDS];

  printf("Enter the document:\n");

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  // read the document line by line
  while ((read = getline(&line, &len, stdin)) != -1) {
    strcat(document, line);
    sentence_count++;
  }

  if (line)
    free(line);

  // tokenize the document into sentences
  char *sentence = strtok(document, ".!?\n");
  int i = 0;
  while(sentence != NULL && i < MAX_SENTENCES) {
    sentences[i++] = sentence;
    sentence = strtok(NULL, ".!?\n");
  }

  // tokenize the sentences into words
  for (int j = 0; j < i; j++) {
    char *word = strtok(sentences[j], " ");
    int k = 0;
    while(word != NULL && k < MAX_WORDS) {
      words[j][k++] = word;
      word = strtok(NULL, " ");
    }
  }

  // calculate the score for each sentence
  float scores[MAX_SENTENCES];
  for (int j = 0; j < i; j++) {
    float score = 0;
    for (int k = 0; k < MAX_WORDS && words[j][k] != NULL; k++) {
      if (strstr(words[j][k], "the") != NULL) score += 1.0;
      if (strstr(words[j][k], "a") != NULL) score += 0.5;
      if (strstr(words[j][k], "an") != NULL) score += 0.5;
    }
    scores[j] = score;
  }

  // find the highest scoring sentence and print it as a summary
  int max_index = 0;
  for (int j = 0; j < i; j++) {
    if (scores[j] > scores[max_index]) {
      max_index = j;
    }
  }

  printf("Summary:\n%s.\n", sentences[max_index]);

  return 0;
}