//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: brave
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
  {"n", "nut"},
  {"o", "orange"},
  {"p", "pineapple"},
  {"q", "queen"},
  {"r", "rabbit"},
  {"s", "snake"},
  {"t", "tiger"},
  {"u", "umbrella"},
  {"v", "violin"},
  {"w", "watch"},
  {"x", "x-ray"},
  {"y", "yacht"},
  {"z", "zebra"},
};

int main() {
  char alien[100];
  printf("Enter alien language: ");
  scanf("%s", alien);

  char *english = malloc(strlen(alien) + 1);
  int i;
  for (i = 0; i < strlen(alien); i++) {
    int j;
    for (j = 0; j < sizeof(dictionary) / sizeof(translation); j++) {
      if (alien[i] == dictionary[j].alien) {
        english[i] = dictionary[j].english;
        break;
      }
    }
  }
  english[i] = '\0';

  printf("English translation: %s\n", english);
  free(english);
  return 0;
}