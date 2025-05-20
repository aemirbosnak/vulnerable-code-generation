//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct AlienWord {
  char word[MAX_WORD_LENGTH];
  int translation;
} AlienWord;

AlienWord alienWords[] = {
  {"Blorg", 12},
  {"Zork", 23},
  {"Zorkonium", 45},
  {"Flub", 32},
  {"Schtupp", 18},
  {"Blorkonium", 14}
};

int translateAlienWord(char *word)
{
  for (int i = 0; i < sizeof(alienWords) / sizeof(AlienWord); i++)
  {
    if (strcmp(word, alienWords[i].word) == 0)
    {
      return alienWords[i].translation;
    }
  }

  return -1;
}

int main()
{
  char alienWord[MAX_WORD_LENGTH];

  printf("Enter an alien word: ");
  scanf("%s", alienWord);

  int translation = translateAlienWord(alienWord);

  if (translation != -1)
  {
    printf("Translation: %d\n", translation);
  }
  else
  {
    printf("Word not found.\n");
  }

  return 0;
}