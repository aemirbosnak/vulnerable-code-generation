//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ptable {
  char *key;
  char *value;
};

struct ptable table[] = {
  {"n","9"},
  {"i","3"},
  {"s","7"},
  {"h","4"},
  {"e","2"},
  {"t","1"},
  {"a","0"}
};

char *translate(char *input) {
  int i, j;
  char *output;

  output = malloc(strlen(input) / 2 + 1);

  for (i = 0, j = 0; input[i] != '\0'; i++) {
    for (j = 0; j < 7; j++) {
      if (input[i] == table[j].key[0]) {
        output[i] = table[j].value[0];
      }
    }
  }

  output[i] = '\0';

  return output;
}

int main() {
  char *input;

  input = malloc(1024);

  printf("Enter an alien word to translate: ");
  scanf("%s", input);

  printf("The translated word is: %s\n", translate(input));

  free(input);

  return 0;
}