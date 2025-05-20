//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ALI_LANG_WORDS 20

typedef struct alien_word {
  char word[20];
  int meaning;
} alien_word_t;

alien_word_t alien_words[ALI_LANG_WORDS] = {
  {"Zozz", 1},
  {"Zork", 2},
  {"Flork", 3},
  {"Bargle", 4},
  {"Buzz", 5},
  {"Fuzz", 6},
  {"Flub", 7},
  {"Gloop", 8},
  {"Zzap", 9},
  {"Zap", 10},
  {"Zarg", 11},
  {"Zork", 12},
  {"Zorg", 13},
  {"Florg", 14},
  {"Barg", 15},
  {"Buzz", 16},
  {"Fuzz", 17},
  {"Flub", 18},
  {"Gloop", 19},
  {"Zzap", 20}
};

int alien_lang_translate(char *word) {
  for (int i = 0; i < ALI_LANG_WORDS; i++) {
    if (strcmp(word, alien_words[i].word) == 0) {
      return alien_words[i].meaning;
    }
  }

  return -1;
}

int main() {
  char alien_word[20];

  printf("Enter an alien word: ");
  scanf("%s", alien_word);

  int translation = alien_lang_translate(alien_word);

  if (translation != -1) {
    printf("Translation: %d\n", translation);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}