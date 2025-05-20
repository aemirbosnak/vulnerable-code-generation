//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_GUESSES 5

char words[MAX_WORDS][20] = {
  "apple",
  "banana",
  "orange",
  "grape",
  "mango",
  "pineapple",
  "watermelon",
  "apricot",
  "peach",
  "grapes"
};

int main()
{
  char guess[MAX_GUESSES];
  int i, j, score = 0, word_index;
  srand(time(NULL));

  word_index = rand() % MAX_WORDS;
  for (i = 0; i < MAX_GUESSES; i++)
  {
    printf("Guess a word: ");
    scanf("%s", guess);

    for (j = 0; j < MAX_WORDS; j++)
    {
      if (strcmp(guess, words[j]) == 0)
      {
        score++;
        printf("Congratulations! You guessed the word: %s\n", words[j]);
        break;
      }
    }

    if (j == MAX_WORDS)
    {
      printf("Sorry, you lose. The word was: %s\n", words[word_index]);
    }
  }

  printf("Your final score is: %d\n", score);

  return 0;
}