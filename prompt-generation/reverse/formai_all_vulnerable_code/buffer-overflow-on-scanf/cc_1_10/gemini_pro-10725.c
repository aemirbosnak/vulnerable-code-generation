//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cat Language Translator Dictionary
typedef struct {
  char *from;
  char *to;
} cat_dict_t;

cat_dict_t cat_dict[] = {
  {"meow", "I'm hungry"},
  {"purr", "I'm happy"},
  {"hiss", "Leave me alone"},
  {"mew", "Let's play"},
  {"scratch", "Ouch!"},
  {"bite", "Don't mess with me"},
  {"rub", "Pet me"},
  {"roll", "I'm sleepy"},
  {"jump", "I want to go outside"},
  {"hide", "I'm scared"},
  {"stalk", "I'm hunting"},
  {"pounce", "Gotcha!"},
  {"eat", "Yum yum"},
  {"poop", "Eww, I need to go"},
  {"pee", "Excuse me, I'm going to the bathroom"},
  {"sleep", "Zzz..."}
};

// Cat Language Translator Function
char *cat_translate(char *cat_phrase) {
  int i;
  for (i = 0; i < sizeof(cat_dict) / sizeof(cat_dict_t); i++) {
    if (strcmp(cat_phrase, cat_dict[i].from) == 0) {
      return cat_dict[i].to;
    }
  }

  // Cat phrase not found in dictionary
  return "Meow? (I don't understand)";
}

int main() {
  // Get cat phrase from user
  char cat_phrase[100];
  printf("Enter a cat phrase: ");
  scanf("%s", cat_phrase);

  // Translate cat phrase
  char *english_translation = cat_translate(cat_phrase);

  // Print translation
  printf("English translation: %s\n", english_translation);

  return 0;
}