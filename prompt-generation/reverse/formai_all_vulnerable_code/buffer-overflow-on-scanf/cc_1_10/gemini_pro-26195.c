//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language dictionary
char *cat_language[] = {
  "meow", "purr", "hiss", "growl", "chirp",
  "trill", "chatter", "howl", "yowl", "mew"
};

// Define the English Language dictionary
char *english_language[] = {
  "hello", "content", "angry", "aggressive", "happy",
  "excited", "talkative", "sad", "painful", "sleepy"
};

// Translate a Cat Language word to English
char *cat_to_english(char *cat_word) {
  int i;
  for (i = 0; i < 10; i++) {
    if (strcmp(cat_word, cat_language[i]) == 0) {
      return english_language[i];
    }
  }

  return "Unknown";
}

// Translate an English word to Cat Language
char *english_to_cat(char *english_word) {
  int i;
  for (i = 0; i < 10; i++) {
    if (strcmp(english_word, english_language[i]) == 0) {
      return cat_language[i];
    }
  }

  return "Unknown";
}

// Main function
int main() {
  // Get the input from the user
  char input[100];
  printf("Enter a word in Cat Language or English: ");
  scanf("%s", input);

  // Translate the input to the other language
  char *translation;
  if (strlen(input) > 4) {
    translation = english_to_cat(input);
  } else {
    translation = cat_to_english(input);
  }

  // Print the translation
  printf("Translation: %s\n", translation);

  return 0;
}