//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Define variables for word frequency tracking
  char *word, *ptr;
  FILE *fp;
  int count = 0;
  int max_count = 10; // default maximum number of words to display
  int i, j;
  int *counts; // array of word counts
  char **words; // array of unique words

  // Ensure proper usage
  if (argc < 2 || argc > 3) {
    printf("Usage: %s <filename> [max words]\n", argv[0]);
    return 1;
  }

  // Use provided maximum number of words, if specified
  if (argc == 3) {
    max_count = atoi(argv[2]);
  }

  // Open file for reading
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Unable to open file %s\n", argv[1]);
    return 1;
  }

  // Allocate memory for arrays
  counts = malloc(sizeof(int) * max_count);
  if (counts == NULL) {
    printf("Out of memory\n");
    return 1;
  }
  words = malloc(sizeof(char *) * max_count);
  if (words == NULL) {
    printf("Out of memory\n");
    return 1;
  }
  for (i = 0; i < max_count; i++) {
    words[i] = malloc(sizeof(char) * 50);
    if (words[i] == NULL) {
      printf("Out of memory\n");
      return 1;
    }
  }

  // Read words from file and count frequency
  while (fscanf(fp, "%s", word) != EOF) {
    // Strip non-alphabetic characters from beginning and end of word
    while (!isalpha(word[0])) {
      memmove(word, word+1, strlen(word));
    }
    while (!isalpha(word[strlen(word)-1])) {
      word[strlen(word)-1] = '\0';
    }
    // If word already exists, increment count; otherwise, add to arrays
    for (i = 0; i < count; i++) {
      if (strcmp(words[i], word) == 0) {
        counts[i]++;
        break;
      }
    }
    if (i == count) {
      strncpy(words[i], word, 50);
      counts[i] = 1;
      count++;
    }
  }

  // Sort arrays by frequency count (descending order)
  for (i = 0; i < count; i++) {
    for (j = i+1; j < count; j++) {
      if (counts[i] < counts[j]) {
        int temp_count = counts[i];
        char *temp_word = words[i];
        counts[i] = counts[j];
        words[i] = words[j];
        counts[j] = temp_count;
        words[j] = temp_word;
      }
    }
  }

  // Print the top max_count words and their frequency counts
  printf("Top %d words:\n", max_count);
  for (i = 0; i < max_count && i < count; i++) {
    printf("%s: %d\n", words[i], counts[i]);
  }

  // Clean up memory and close file
  for (i = 0; i < max_count; i++) {
    free(words[i]);
  }
  free(words);
  free(counts);
  fclose(fp);

  return 0;
}