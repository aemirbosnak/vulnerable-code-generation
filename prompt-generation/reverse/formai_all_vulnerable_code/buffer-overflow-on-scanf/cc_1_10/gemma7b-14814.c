//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 20

typedef struct Word {
  char *word;
  int length;
} Word;

Word words[MAX_WORDS];

void initWords() {
  words[0].word = "apple";
  words[0].length = 5;
  words[1].word = "banana";
  words[1].length = 6;
  // Add more words...
}

void testTypingSpeed() {
  int i = 0;
  clock_t start, end;
  double timeTaken;

  printf("Please type the word: ");
  start = clock();
  char input[MAX_WORDS];
  scanf("%s", input);

  end = clock();
  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  for (i = 0; words[i].word != NULL; i++) {
    if (strcmp(input, words[i].word) == 0) {
      printf("You typed the word: %s in %.2f seconds\n", words[i].word, timeTaken);
      break;
    }
  }

  if (i == MAX_WORDS - 1) {
    printf("The word you typed is not found.\n");
  }
}

int main() {
  initWords();
  testTypingSpeed();

  return 0;
}