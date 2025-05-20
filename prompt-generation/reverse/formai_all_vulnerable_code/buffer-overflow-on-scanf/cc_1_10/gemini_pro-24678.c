//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
// Future-proof C Alien Language Translator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the Alien language alphabet
const char* alien_alphabet = "zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLQWERTYUIOP";

// Define the English language alphabet
const char* english_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to translate from Alien to English
char* alien_to_english(const char* alien_text) {
  assert(alien_text != NULL);

  // Allocate memory for the English translation
  char* english_text = malloc(strlen(alien_text) + 1);
  if (english_text == NULL) {
    return NULL;
  }

  // Translate each character in the Alien text
  for (size_t i = 0; i < strlen(alien_text); i++) {
    char alien_char = alien_text[i];

    // Find the index of the character in the Alien alphabet
    size_t alien_index = strchr(alien_alphabet, alien_char) - alien_alphabet;

    // Use the corresponding index to get the English character
    char english_char = english_alphabet[alien_index];

    // Append the English character to the translation
    english_text[i] = english_char;
  }

  // Null-terminate the English translation
  english_text[strlen(alien_text)] = '\0';

  // Return the English translation
  return english_text;
}

// Function to translate from English to Alien
char* english_to_alien(const char* english_text) {
  assert(english_text != NULL);

  // Allocate memory for the Alien translation
  char* alien_text = malloc(strlen(english_text) + 1);
  if (alien_text == NULL) {
    return NULL;
  }

  // Translate each character in the English text
  for (size_t i = 0; i < strlen(english_text); i++) {
    char english_char = english_text[i];

    // Find the index of the character in the English alphabet
    size_t english_index = strchr(english_alphabet, english_char) - english_alphabet;

    // Use the corresponding index to get the Alien character
    char alien_char = alien_alphabet[english_index];

    // Append the Alien character to the translation
    alien_text[i] = alien_char;
  }

  // Null-terminate the Alien translation
  alien_text[strlen(english_text)] = '\0';

  // Return the Alien translation
  return alien_text;
}

// Main function
int main() {
  // Get the Alien text from the user
  char alien_text[100];
  printf("Enter the Alien text: ");
  scanf("%s", alien_text);

  // Translate the Alien text to English
  char* english_text = alien_to_english(alien_text);
  if (english_text == NULL) {
    printf("Error: Could not translate the Alien text.\n");
    return EXIT_FAILURE;
  }

  // Print the English translation
  printf("English translation: %s\n", english_text);

  // Translate the English text back to Alien
  char* alien_text2 = english_to_alien(english_text);
  if (alien_text2 == NULL) {
    printf("Error: Could not translate the English text back to Alien.\n");
    return EXIT_FAILURE;
  }

  // Check if the Alien translation is the same as the original Alien text
  if (strcmp(alien_text, alien_text2) == 0) {
    printf("The Alien translation is the same as the original Alien text.\n");
  } else {
    printf("The Alien translation is different from the original Alien text.\n");
  }

  // Free the memory allocated for the translations
  free(english_text);
  free(alien_text2);

  return EXIT_SUCCESS;
}