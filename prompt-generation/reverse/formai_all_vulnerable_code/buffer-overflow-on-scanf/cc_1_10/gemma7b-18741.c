//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  int is_correct;
} Word;

Word words[MAX_WORDS];

void read_words(void) {
  words[0].word = "apple";
  words[0].is_correct = 1;

  words[1].word = "banana";
  words[1].is_correct = 1;

  words[2].word = "orange";
  words[2].is_correct = 1;

  words[3].word = "grapefruit";
  words[3].is_correct = 1;

  words[4].word = "mango";
  words[4].is_correct = 1;

  words[5].word = "apricot";
  words[5].is_correct = 0;

  words[6].word = "peach";
  words[6].is_correct = 1;

  words[7].word = "watermelon";
  words[7].is_correct = 1;

  words[8].word = "grapes";
  words[8].is_correct = 0;

  words[9].word = "apricot";
  words[9].is_correct = 0;
}

int main(void) {
  read_words();

  char word[MAX_WORD_LENGTH];

  printf("Enter a word: ");
  scanf("%s", word);

  int is_word_correct = 0;

  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(word, words[i].word) == 0) {
      is_word_correct = words[i].is_correct;
    }
  }

  if (is_word_correct) {
    printf("The word is correct.\n");
  } else {
    printf("The word is not correct.\n");
  }

  return 0;
}