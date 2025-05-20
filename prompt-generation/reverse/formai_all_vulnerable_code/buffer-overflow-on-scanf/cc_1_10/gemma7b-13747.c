//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct AlienWord {
  char alienWord[20];
  char englishWord[20];
} AlienWord;

AlienWord alienWords[MAX_WORDS] = {
  {"Blork", "Cat"},
  {"Zork", "Dog"},
  {"Quork", "Fish"},
  {"Rork", "Goat"},
  {"Skork", "Horse"},
  {"Froork", "Tiger"},
  {"Barork", "Lion"},
  {"Clorork", "Zebra"},
  {"Zorork", "Giraffe"},
  {"Zizzork", "Giraffe"}
};

char translateAlienWord(char *alienWord) {
  int i = 0;
  for (i = 0; i < MAX_WORDS; i++) {
    if (strcmp(alienWord, alienWords[i].alienWord) == 0) {
      return alienWords[i].englishWord[0];
    }
  }
  return 'N';
}

int main() {
  char alienWord[20];

  printf("Enter an alien word: ");
  scanf("%s", alienWord);

  char translatedWord = translateAlienWord(alienWord);

  if (translatedWord != 'N') {
    printf("Translated word: %c\n", translatedWord);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}