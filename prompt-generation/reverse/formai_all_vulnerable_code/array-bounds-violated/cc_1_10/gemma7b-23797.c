//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

#define ALIENS_LANG_MAX_WORDS 10

typedef struct AlienWord {
  char word[20];
  int meaning;
} AlienWord;

AlienWord alien_words[ALIENS_LANG_MAX_WORDS] = {
  {"Blork", 1},
  {"Zork", 2},
  {"Flork", 3},
  {"Narf", 4},
  {"Spork", 5},
  {"Bork", 6},
  {"Zork's hat", 7},
  {"Boink", 8},
  {"Zooz", 9},
  {"Flub", 10}
};

int translate_alien_lang(char *alien_phrase) {
  int i, word_count = 0, translation = 0;
  char word[20];

  for (i = 0; alien_phrase[i] != '\0'; i++) {
    word[i] = alien_phrase[i];
    for (i = 0; alien_words[i].word[0] != '\0'; i++) {
      if (strcmp(word, alien_words[i].word) == 0) {
        translation = alien_words[i].meaning;
      }
    }
    word_count++;
  }

  return translation;
}

int main() {
  char alien_phrase[] = "Blork spork narf flub zooz boink zork's hat";
  int translation = translate_alien_lang(alien_phrase);

  switch (translation) {
    case 1:
      printf("The alien phrase is: Blork spork narf flub zooz boink zork's hat\n");
      printf("The translation is: I am a simple alien.\n");
      break;
    case 2:
      printf("The alien phrase is: Blork spork narf flub zooz boink zork's hat\n");
      printf("The translation is: I am a powerful alien.\n");
      break;
    case 3:
      printf("The alien phrase is: Blork spork narf flub zooz boink zork's hat\n");
      printf("The translation is: I am a mischievous alien.\n");
      break;
    default:
      printf("The alien phrase is: Blork spork narf flub zooz boink zork's hat\n");
      printf("The translation is: I am an alien.\n");
      break;
  }

  return 0;
}