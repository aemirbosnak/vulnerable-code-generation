//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  int score;
} Word;

Word words[MAX_WORDS];

void initializeWords() {
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i].word = malloc(MAX_WORD_LENGTH);
    words[i].score = 0;
  }
}

void addWord(char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].word == NULL) {
      words[i].word = malloc(MAX_WORD_LENGTH);
      strcpy(words[i].word, word);
      words[i].score = 0;
      return;
    }
  }

  printf("Error: The list of words is full.\n");
}

void playGame() {
  char guessWord[MAX_WORD_LENGTH];

  printf("Enter a word: ");
  scanf("%s", guessWord);

  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(guessWord, words[i].word) == 0) {
      words[i].score++;
      printf("Word found! Score: %d\n", words[i].score);
      return;
    }
  }

  printf("Word not found.\n");
}

int main() {
  initializeWords();

  playGame();

  return 0;
}