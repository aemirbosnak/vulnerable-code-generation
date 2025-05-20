//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

// Define the Alien language dictionary
const char *alien_dictionary[] = {
  "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
  "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
  "u", "v", "w", "x", "y", "z"
};

// Define the Earth language dictionary
const char *earth_dictionary[] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
  "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand"
};

// Function to translate an Alien word to Earth language
char *alien_to_earth(const char *alien_word) {
  char *earth_word = malloc(MAX_WORD_LENGTH);
  int i = 0;
  while (alien_word[i]) {
    int index = alien_word[i] - 'a';
    strcpy(earth_word + strlen(earth_word), earth_dictionary[index]);
    i++;
  }
  return earth_word;
}

// Function to translate an Earth word to Alien language
char *earth_to_alien(const char *earth_word) {
  char *alien_word = malloc(MAX_WORD_LENGTH);
  int i = 0;
  while (earth_word[i]) {
    int index = 0;
    while (strcmp(earth_dictionary[index], earth_word + i) != 0) {
      index++;
    }
    alien_word[i] = 'a' + index;
    i += strlen(earth_dictionary[index]);
  }
  return alien_word;
}

// Main function
int main() {
  // Get the Alien word from the user
  char alien_word[MAX_WORD_LENGTH];
  printf("Enter an Alien word: ");
  scanf("%s", alien_word);

  // Translate the Alien word to Earth language
  char *earth_word = alien_to_earth(alien_word);

  // Display the Earth word
  printf("The Earth word is: %s\n", earth_word);

  // Translate the Earth word to Alien language
  char *translated_alien_word = earth_to_alien(earth_word);

  // Display the translated Alien word
  printf("The translated Alien word is: %s\n", translated_alien_word);

  // Free the allocated memory
  free(earth_word);
  free(translated_alien_word);

  return 0;
}