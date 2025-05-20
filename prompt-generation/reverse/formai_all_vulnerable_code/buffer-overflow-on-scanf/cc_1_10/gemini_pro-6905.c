//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alien_dictionary {
  char alien_letter;
  char english_letter;
};

int main() {
  // Define the alien language dictionary
  struct alien_dictionary dictionary[] = {
    {'A', 'a'},
    {'B', 'b'},
    {'C', 'c'},
    {'D', 'd'},
    {'E', 'e'},
    {'F', 'f'},
    {'G', 'g'},
    {'H', 'h'},
    {'I', 'i'},
    {'J', 'j'},
    {'K', 'k'},
    {'L', 'l'},
    {'M', 'm'},
    {'N', 'n'},
    {'O', 'o'},
    {'P', 'p'},
    {'Q', 'q'},
    {'R', 'r'},
    {'S', 's'},
    {'T', 't'},
    {'U', 'u'},
    {'V', 'v'},
    {'W', 'w'},
    {'X', 'x'},
    {'Y', 'y'},
    {'Z', 'z'},
    {'!', '!'},
    {'?', '?'},
    {' ', ' '}
  };

  // Get the alien language text from the user
  char alien_text[100];
  printf("Enter the alien language text: ");
  scanf("%s", alien_text);

  // Translate the alien language text to English
  char english_text[100];
  for (int i = 0; i < strlen(alien_text); i++) {
    for (int j = 0; j < sizeof(dictionary) / sizeof(struct alien_dictionary); j++) {
      if (alien_text[i] == dictionary[j].alien_letter) {
        english_text[i] = dictionary[j].english_letter;
        break;
      }
    }
  }

  // Print the English translation
  printf("English translation: %s\n", english_text);

  return 0;
}