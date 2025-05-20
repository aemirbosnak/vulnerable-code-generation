//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: immersive
// Welcome to the enigmatic world of the Alien Language Translator!

// Our intergalactic quest begins with a grandiose header file, a celestial guide to our cosmic translator:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's define an intergalactic constant, a beacon of infinity:
#define MAX_ALIEN_WORDS 100000

// We prepare a celestial vessel to hold the alien lexicon:
char alienDictionary[MAX_ALIEN_WORDS][256];

// Our interstellar journey begins with the initialization of our vessel:
void initializeDictionary() {
  FILE *alienLexicon = fopen("alienLexicon.txt", "r");
  if (alienLexicon == NULL) {
    printf("Alas, we cannot access the alien lexicon! Our quest is doomed!\n");
    exit(1);
  }

  int wordCount = 0;
  while (fscanf(alienLexicon, "%s", alienDictionary[wordCount++]) != EOF) {
    if (wordCount >= MAX_ALIEN_WORDS) {
      printf("The lexicon is overflowing with words! Our vessel cannot contain such vast knowledge!\n");
      exit(1);
    }
  }

  fclose(alienLexicon);
}

// We prepare our translator, a celestial marvel that deciphers alien tongues:
void translateAlienPhrase() {
  char alienPhrase[256];
  printf("Enter an enigmatic alien phrase: ");
  scanf("%s", alienPhrase);

  int wordCount = 0;
  while (strcmp(alienPhrase, "terminate") != 0) {
    int found = 0;
    for (int i = 0; i < MAX_ALIEN_WORDS; i++) {
      if (strcmp(alienPhrase, alienDictionary[i]) == 0) {
        printf("Ah, the wisdom of the ancients! The translation is: %s\n", alienDictionary[i]);
        found = 1;
        break;
      }
    }

    if (!found) {
      printf("Alas, this alien utterance remains a mystery. Our lexicon is inadequate!\n");
    }

    printf("Enter another alien phrase (or 'terminate' to end): ");
    scanf("%s", alienPhrase);
  }
}

// We launch our interstellar translator, a beacon of intergalactic understanding:
int main() {
  printf("Greetings, O intrepid explorer! Welcome to the Alien Language Translator!\n");
  initializeDictionary();
  translateAlienPhrase();
  printf("May your journey through the cosmos be filled with wonder and enlightenment!\n");
  return 0;
}