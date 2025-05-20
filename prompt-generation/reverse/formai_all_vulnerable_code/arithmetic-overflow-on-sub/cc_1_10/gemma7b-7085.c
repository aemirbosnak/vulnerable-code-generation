//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define WORDS_PER_LINE 20

typedef struct Word {
  char *word;
  int length;
} Word;

Word words[MAX_WORDS];

void initializeWords() {
  words[0].word = "apple";
  words[0].length = 5;

  words[1].word = "banana";
  words[1].length = 6;

  words[2].word = "orange";
  words[2].length = 6;

  words[3].word = "grapefruit";
  words[3].length = 8;

  words[4].word = "mango";
  words[4].length = 5;

  words[5].word = "pineapple";
  words[5].length = 8;

  words[6].word = "watermelon";
  words[6].length = 9;

  words[7].word = "apricot";
  words[7].length = 6;

  words[8].word = "peach";
  words[8].length = 5;

  words[9].word = "pear";
  words[9].length = 5;
}

int main() {
  initializeWords();

  time_t start, end;
  double timeTaken;

  start = time(NULL);

  // Typing speed test code goes here

  end = time(NULL);

  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Time taken: %.2lf seconds\n", timeTaken);

  return 0;
}