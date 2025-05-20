//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALIEN_LANGUAGE_TABLE_SIZE 10

typedef struct AlienLanguageTableEntry {
  char alien_word[20];
  char english_word[20];
  int translation_count;
} AlienLanguageTableEntry;

AlienLanguageTableEntry alien_language_table[ALIEN_LANGUAGE_TABLE_SIZE] = {
  {"Blorg", "Hello", 10},
  {"Flork", "Goodbye", 5},
  {"Zork", "Yes", 2},
  {"Zor", "No", 3},
  {"Trork", "Thank you", 8},
  {"Zorg", "Please", 4},
  {"Blork", "Excuse me", 6},
  {"Flork", "Sorry", 3},
  {"Trork", "Happy birthday", 2},
  {"Zork", "I love you", 1}
};

int alien_language_translate(char *alien_word) {
  for (int i = 0; i < ALIEN_LANGUAGE_TABLE_SIZE; i++) {
    if (strcmp(alien_word, alien_language_table[i].alien_word) == 0) {
      return alien_language_table[i].english_word;
    }
  }

  return -1;
}

int main() {
  char alien_word[20];

  printf("Enter an alien word: ");
  scanf("%s", alien_word);

  int translation = alien_language_translate(alien_word);

  if (translation != -1) {
    printf("Translation: %s\n", translation);
  } else {
    printf("No translation found.\n");
  }

  return 0;
}