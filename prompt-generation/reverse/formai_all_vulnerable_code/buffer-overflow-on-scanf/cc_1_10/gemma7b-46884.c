//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

#define ALIENS_LANGUAGE_MAX_WORDS 10

char alien_language_words[ALIENS_LANGUAGE_MAX_WORDS][20] = {
  "Skreebl'quz",
  "Blorg'thok",
  "Zork'bar",
  "Slor'thak",
  "Quz'bar",
  "Thork'mor",
  "Bar'skree",
  "Blorg'nar",
  "Zork'nor",
  "Slor'nak"
};

char alien_language_translate(char *word)
{
  int i = 0;
  for (i = 0; i < ALIENS_LANGUAGE_MAX_WORDS; i++)
  {
    if (strcmp(word, alien_language_words[i]) == 0)
    {
      return alien_language_words[i][0] + 2;
    }
  }

  return 0;
}

int main()
{
  char alien_word[20];

  printf("Enter an alien word: ");
  scanf("%s", alien_word);

  char translated_word = alien_language_translate(alien_word);

  if (translated_word)
  {
    printf("Translated word: %c\n", translated_word);
  }
  else
  {
    printf("Word not found.\n");
  }

  return 0;
}