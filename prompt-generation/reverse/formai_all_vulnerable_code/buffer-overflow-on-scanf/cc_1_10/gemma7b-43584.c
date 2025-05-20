//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct AlienWord {
  char word[MAX_WORD_LENGTH];
  int translation;
} AlienWord;

AlienWord alienWords[] = {
  {"Tr'xylth", 10},
  {"Zork'th", 20},
  {"Kro'th", 30},
  {"Xyzz'th", 40},
  {"Flub'th", 50}
};

int translateAlienWord(char *word)
{
  int i = 0;
  for (i = 0; alienWords[i].word && strcmp(word, alienWords[i].word) != 0; i++) {}

  if (alienWords[i].word)
  {
    return alienWords[i].translation;
  } else
  {
    return -1;
  }
}

int main()
{
  char alienWord[MAX_WORD_LENGTH];

  printf("Enter an alien word: ");
  scanf("%s", alienWord);

  int translation = translateAlienWord(alienWord);

  if (translation == -1)
  {
    printf("Error: word not found.\n");
  } else
  {
    printf("Translation: %d\n", translation);
  }

  return 0;
}