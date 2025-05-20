//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char *alien_dict[] = {"At", "Go", "See", "Come", "Take", "Give", "Help", "Thank", "Sorry", "Goodbye"};

// Define the English language dictionary
char *english_dict[] = {"To", "To go", "To see", "To come", "To take", "To give", "To help", "To thank", "To apologize", "To say goodbye"};

// Function to translate Alien to English
char *alien_to_english(char *alien) {
  // Iterate over the Alien dictionary
  for (int i = 0; i < sizeof(alien_dict) / sizeof(char *); i++) {
    // Check if the Alien word matches the current entry in the dictionary
    if (strcmp(alien, alien_dict[i]) == 0) {
      // Return the corresponding English translation
      return english_dict[i];
    }
  }

  // If the Alien word is not found in the dictionary, return NULL
  return NULL;
}

// Function to translate English to Alien
char *english_to_alien(char *english) {
  // Iterate over the English dictionary
  for (int i = 0; i < sizeof(english_dict) / sizeof(char *); i++) {
    // Check if the English word matches the current entry in the dictionary
    if (strcmp(english, english_dict[i]) == 0) {
      // Return the corresponding Alien translation
      return alien_dict[i];
    }
  }

  // If the English word is not found in the dictionary, return NULL
  return NULL;
}

// Main function
int main() {
  // Get the input Alien word from the user
  char alien[256];
  printf("Enter the Alien word: ");
  scanf("%s", alien);

  // Translate the Alien word to English and print the result
  char *english = alien_to_english(alien);
  if (english == NULL) {
    printf("Invalid Alien word: %s\n", alien);
  } else {
    printf("English translation: %s\n", english);
  }

  // Get the input English word from the user
  char english_in[256];
  printf("Enter the English word: ");
  scanf("%s", english_in);

  // Translate the English word to Alien and print the result
  char *alien_out = english_to_alien(english_in);
  if (alien_out == NULL) {
    printf("Invalid English word: %s\n", english_in);
  } else {
    printf("Alien translation: %s\n", alien_out);
  }

  return 0;
}