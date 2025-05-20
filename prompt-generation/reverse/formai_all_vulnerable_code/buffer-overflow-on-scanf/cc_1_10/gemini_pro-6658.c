//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language dictionary
const char *cat_language[] = {
  "meow", "purr", "hiss", "growl", "mew", "chirp", "trill", "yowl", "wail", "howl"
};

// Define the English language dictionary
const char *english_language[] = {
  "hello", "I love you", "go away", "I'm hungry", "I'm thirsty", "I'm happy",
  "I'm sad", "I'm angry", "I'm scared", "I'm in pain"
};

// Translate a Cat Language word to English
char *cat_to_english(char *cat_word) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(cat_word, cat_language[i]) == 0) {
      return strdup(english_language[i]);
    }
  }
  return NULL;
}

// Translate an English word to Cat Language
char *english_to_cat(char *english_word) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(english_word, english_language[i]) == 0) {
      return strdup(cat_language[i]);
    }
  }
  return NULL;
}

// Print a Cat Language translation
void print_translation(char *cat_word, char *english_word) {
  printf("Cat Language: %s\n", cat_word);
  printf("English Translation: %s\n\n", english_word);
}

// Get a Cat Language word from the user
char *get_cat_word() {
  char *cat_word = malloc(256);
  printf("Enter a Cat Language word: ");
  scanf("%s", cat_word);
  return cat_word;
}

// Get an English word from the user
char *get_english_word() {
  char *english_word = malloc(256);
  printf("Enter an English word: ");
  scanf("%s", english_word);
  return english_word;
}

// Main function
int main() {
  int choice;

  // Display the menu
  printf("Cat Language Translator\n");
  printf("1. Translate Cat Language to English\n");
  printf("2. Translate English to Cat Language\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Get the user's input
  char *cat_word, *english_word;
  switch (choice) {
    case 1:
      cat_word = get_cat_word();
      english_word = cat_to_english(cat_word);
      print_translation(cat_word, english_word);
      break;
    case 2:
      english_word = get_english_word();
      cat_word = english_to_cat(english_word);
      print_translation(cat_word, english_word);
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice\n");
  }

  // Free the allocated memory
  free(cat_word);
  free(english_word);

  return 0;
}