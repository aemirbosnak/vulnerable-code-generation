//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
  char word[20];
  int frequency;
} Word;

Word words[MAX_WORDS];

void initializeWords() {
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i].word[0] = '\0';
    words[i].frequency = 0;
  }
}

void addWord(char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(words[i].word, word) == 0) {
      words[i].frequency++;
      return;
    }
  }

  Word newWord;
  strcpy(newWord.word, word);
  newWord.frequency = 1;

  words[MAX_WORDS - 1] = newWord;
}

int main() {
  initializeWords();

  char input[20];

  clock_t start, end;
  double timeTaken;

  printf("Start typing: ");

  start = clock();

  fgets(input, 20, stdin);

  end = clock();

  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  addWord(input);

  printf("Time taken: %.2lf seconds\n", timeTaken);

  printf("Words typed: %d\n", words[0].frequency);

  return 0;
}