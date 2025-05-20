//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
  char* word;
  int count;
} WordCount;

int compare_word_counts(const void* a, const void* b) {
  const WordCount* wc1 = (const WordCount*)a;
  const WordCount* wc2 = (const WordCount*)b;
  return wc2->count - wc1->count;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  WordCount word_counts[MAX_WORDS];
  int num_words = 0;

  char word[101];
  while (fscanf(fp, "%s", word) != EOF) {
    // Remove punctuation from the word.
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
      if (ispunct(word[i])) {
        word[i] = '\0';
        break;
      }
    }

    // Convert the word to lowercase.
    for (int i = 0; i < len; i++) {
      word[i] = tolower(word[i]);
    }

    // Find the word in the array of word counts.
    int index = -1;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(word, word_counts[i].word) == 0) {
        index = i;
        break;
      }
    }

    // If the word was not found, add it to the array.
    if (index == -1) {
      if (num_words == MAX_WORDS) {
        fprintf(stderr, "Error: Too many words.\n");
        return EXIT_FAILURE;
      }
      word_counts[num_words].word = strdup(word);
      word_counts[num_words].count = 1;
      num_words++;
    } else {
      // If the word was found, increment its count.
      word_counts[index].count++;
    }
  }

  fclose(fp);

  // Sort the array of word counts in descending order.
  qsort(word_counts, num_words, sizeof(WordCount), compare_word_counts);

  // Print the top 20 most frequent words.
  for (int i = 0; i < num_words && i < 20; i++) {
    printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
  }

  // Free the memory allocated for the words.
  for (int i = 0; i < num_words; i++) {
    free(word_counts[i].word);
  }

  return EXIT_SUCCESS;
}