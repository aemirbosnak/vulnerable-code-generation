//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 20

// Define the alien language dictionary
typedef struct {
  char alien_word[MAX_WORD_SIZE];
  char english_word[MAX_WORD_SIZE];
} alien_dictionary_entry;

// Create the alien language dictionary
alien_dictionary_entry dictionary[] = {
  {"a", "apple"},
  {"b", "banana"},
  {"c", "cat"},
  {"d", "dog"},
  {"e", "earth"},
  {"f", "fire"},
  {"g", "good"},
  {"h", "hello"},
  {"i", "I"},
  {"j", "jump"},
  {"k", "king"},
  {"l", "love"},
  {"m", "moon"},
  {"n", "no"},
  {"o", "one"},
  {"p", "planet"},
  {"q", "queen"},
  {"r", "red"},
  {"s", "sun"},
  {"t", "tree"},
  {"u", "up"},
  {"v", "very"},
  {"w", "water"},
  {"x", "x-ray"},
  {"y", "yellow"},
  {"z", "zebra"}
};

// The number of entries in the dictionary
#define DICTIONARY_SIZE (sizeof(dictionary) / sizeof(alien_dictionary_entry))

// Get the English translation of an alien word
char *get_english_translation(char *alien_word) {
  for (int i = 0; i < DICTIONARY_SIZE; i++) {
    if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
      return dictionary[i].english_word;
    }
  }
  return NULL;
}

// Translate an entire sentence from alien to English
void translate_sentence(char *alien_sentence) {
  char *english_sentence = malloc(strlen(alien_sentence) + 1);
  char *alien_word = strtok(alien_sentence, " ");
  while (alien_word != NULL) {
    char *english_word = get_english_translation(alien_word);
    if (english_word != NULL) {
      strcat(english_sentence, english_word);
    } else {
      strcat(english_sentence, alien_word);
    }
    strcat(english_sentence, " ");
    alien_word = strtok(NULL, " ");
  }
  printf("English translation: %s\n", english_sentence);
  free(english_sentence);
}

int main() {
  // Get the alien sentence from the user
  char alien_sentence[100];
  printf("Enter an alien sentence: ");
  gets(alien_sentence);

  // Translate the sentence from alien to English
  translate_sentence(alien_sentence);

  return 0;
}