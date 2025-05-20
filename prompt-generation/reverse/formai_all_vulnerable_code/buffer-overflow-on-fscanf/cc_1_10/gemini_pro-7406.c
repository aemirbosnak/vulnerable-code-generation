//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 1000

// A surrealist sentiment analysis tool
int main(int argc, char *argv[]) {
  // Declare an array of strings to store the words
  char *words[MAX_WORDS];
  // Declare an array of strings to store the sentences
  char *sentences[MAX_SENTENCES];
  // Declare an array of integers to store the sentiment of each sentence
  int sentiment[MAX_SENTENCES];

  // Read the words from the file
  FILE *fp = fopen("words.txt", "r");
  if (fp == NULL) {
    printf("Error opening file words.txt\n");
    return 1;
  }
  int i = 0;
  while (fscanf(fp, "%s", words[i]) != EOF) {
    i++;
  }
  fclose(fp);

  // Read the sentences from the file
  fp = fopen("sentences.txt", "r");
  if (fp == NULL) {
    printf("Error opening file sentences.txt\n");
    return 1;
  }
  i = 0;
  while (fscanf(fp, "%s", sentences[i]) != EOF) {
    i++;
  }
  fclose(fp);

  // Analyze the sentiment of each sentence
  for (i = 0; i < MAX_SENTENCES; i++) {
    sentiment[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      for (int j = 0; j < MAX_WORDS; j++) {
        if (strcmp(word, words[j]) == 0) {
          sentiment[i] += 1;
        }
      }
      word = strtok(NULL, " ");
    }
  }

  // Print the sentiment of each sentence
  for (i = 0; i < MAX_SENTENCES; i++) {
    printf("%s: %d\n", sentences[i], sentiment[i]);
  }

  return 0;
}