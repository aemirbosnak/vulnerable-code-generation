//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *alien;
  char *english;
} translation;

translation dictionary[] = {
  {"a", "apple"},
  {"b", "banana"},
  {"c", "cat"},
  {"d", "dog"},
  {"e", "elephant"},
  {"f", "fish"},
  {"g", "goat"},
  {"h", "horse"},
  {"i", "ice cream"},
  {"j", "juice"},
  {"k", "kite"},
  {"l", "lion"},
  {"m", "monkey"},
  {"n", "nest"},
  {"o", "orange"},
  {"p", "pineapple"},
  {"q", "queen"},
  {"r", "rabbit"},
  {"s", "snake"},
  {"t", "tiger"},
  {"u", "umbrella"},
  {"v", "violin"},
  {"w", "watermelon"},
  {"x", "x-ray"},
  {"y", "yacht"},
  {"z", "zebra"}
};

int main() {
  char alien[100];
  char english[100];
  int i;

  printf("Enter an alien word: ");
  scanf("%s", alien);

  for (i = 0; i < sizeof(dictionary) / sizeof(translation); i++) {
    if (strcmp(alien, dictionary[i].alien) == 0) {
      strcpy(english, dictionary[i].english);
      break;
    }
  }

  if (i == sizeof(dictionary) / sizeof(translation)) {
    printf("Sorry, I don't know that word.\n");
  } else {
    printf("The English translation is: %s\n", english);
  }

  return 0;
}