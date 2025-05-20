//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

Word* words[MAX_WORDS];
int num_words = 0;

int compare_words(const void* a, const void* b) {
  Word* word_a = *(Word**) a;
  Word* word_b = *(Word**) b;
  if (word_a->count < word_b->count) return 1;
  if (word_a->count > word_b->count) return -1;
  return strcmp(word_a->word, word_b->word);
}

void process_word(char* word) {
  // Check if the word already exists
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i]->word, word) == 0) {
      words[i]->count++;
      return;
    }
  }
  // Create a new word
  Word* new_word = (Word*) malloc(sizeof(Word));
  strncpy(new_word->word, word, MAX_WORD_LENGTH);
  new_word->count = 1;
  words[num_words++] = new_word;
}

int main(int argc, char** argv) {
  FILE* file = fopen("input.txt", "r");
  if (!file) {
    printf("Failed to open input file\n");
    return 1;
  }
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    process_word(word);
  }
  fclose(file);
  // Sort the words
  qsort(words, num_words, sizeof(Word*), compare_words);
  // Print the word frequencies
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i]->word, words[i]->count);
  }
  // Free memory
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
  return 0;
}