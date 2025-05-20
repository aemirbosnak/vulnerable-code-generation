//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary() {
  FILE *f = fopen("dictionary.txt", "r");
  if (f == NULL) {
    printf("Could not open dictionary file.\n");
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, f)) {
    line[strlen(line) - 1] = '\0'; // Remove newline character
    strcpy(dictionary[dictionary_size].word, line);
    dictionary[dictionary_size].count = 0;
    dictionary_size++;
  }

  fclose(f);
}

int compare_words(const void *a, const void *b) {
  const Word *word1 = (const Word *)a;
  const Word *word2 = (const Word *)b;

  return strcmp(word1->word, word2->word);
}

int check_spelling(const char *word) {
  Word key;
  strcpy(key.word, word);

  int result = bsearch(&key, dictionary, dictionary_size, sizeof(Word), compare_words);

  return (result != NULL);
}

void print_suggestions(const char *word) {
  int i;

  printf("Did you mean:\n");
  for (i = 0; i < dictionary_size; i++) {
    if (strcmp(dictionary[i].word, word) != 0 &&
        strstr(dictionary[i].word, word) != NULL) {
      printf("  %s\n", dictionary[i].word);
    }
  }
}

int main() {
  char word[MAX_WORD_LENGTH];
  int i;

  load_dictionary();

  printf("My love, I would love to dance with you tonight.\n");
  printf("Please enter a word:\n");

  scanf("%s", word);

  for (i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  if (check_spelling(word)) {
    printf("Your spelling is exquisite, my love.");
  } else {
    printf("My dearest, your spelling is as enchanting as the moonlight.");
    printf("Perhaps you meant one of these:\n");
    print_suggestions(word);
  }

  return 0;
}