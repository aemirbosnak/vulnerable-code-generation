//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

char* words[MAX_WORDS];
int counts[MAX_WORDS];
int num_words;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char word[1024];
  while (fscanf(file, "%s", word) != EOF) {
    int i;
    for (i = 0; i < num_words; i++) {
      if (strcmp(word, words[i]) == 0) {
        counts[i]++;
        break;
      }
    }
    if (i == num_words) {
      words[num_words] = strdup(word);
      counts[num_words++] = 1;
    }
  }

  fclose(file);

  int total_count = 0;
  for (int i = 0; i < num_words; i++) {
    total_count += counts[i];
  }

  int positive_count = 0;
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0 ||
        strcmp(words[i], "awesome") == 0) {
      positive_count += counts[i];
    }
  }

  int negative_count = 0;
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0 ||
        strcmp(words[i], "awful") == 0) {
      negative_count += counts[i];
    }
  }

  float sentiment = (float)positive_count / (positive_count + negative_count);

  printf("Total words: %d\n", total_count);
  printf("Positive words: %d\n", positive_count);
  printf("Negative words: %d\n", negative_count);
  printf("Sentiment: %f\n", sentiment);

  return EXIT_SUCCESS;
}