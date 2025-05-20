//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A glossary to translate Alien words to English
typedef struct {
  char *alien;
  char *english;
} Glossary;

// A list of Alien words and their English translations
Glossary dictionary[] = {
  {"flarg", "hello"},
  {"blaar", "goodbye"},
  {"glarp", "friend"},
  {"slarp", "enemy"},
  {"zarg", "food"},
  {"warg", "water"},
  {"qarg", "shelter"},
  {"xarg", "weapon"},
  {"yarg", "love"},
  {"zorg", "hate"}
};

// Translates an Alien word to English
char *translate(char *alien) {
  int i;
  for (i = 0; i < sizeof(dictionary) / sizeof(Glossary); i++) {
    if (strcmp(alien, dictionary[i].alien) == 0) {
      return dictionary[i].english;
    }
  }
  return "Unknown word";
}

// Prints a greeting in the Alien language
void greet() {
  printf("Flarg, glarp! Blaar.\n");
}

// Prints a goodbye in the Alien language
void goodbye() {
  printf("Blaar, glarp! Flarg.\n");
}

// Prints a list of Alien words and their English translations
void printGlossary() {
  int i;
  for (i = 0; i < sizeof(dictionary) / sizeof(Glossary); i++) {
    printf("%s: %s\n", dictionary[i].alien, dictionary[i].english);
  }
}

int main() {
  // Greet the user in the Alien language
  greet();

  // Prompt the user to enter an Alien word
  char alien[256];
  printf("Enter an Alien word: ");
  scanf("%s", alien);

  // Translate the Alien word to English
  char *english = translate(alien);

  // Print the English translation
  printf("English translation: %s\n", english);

  // Print a goodbye in the Alien language
  goodbye();

  // Print a list of Alien words and their English translations
  printf("\nAlien-English Glossary:\n");
  printGlossary();

  return 0;
}