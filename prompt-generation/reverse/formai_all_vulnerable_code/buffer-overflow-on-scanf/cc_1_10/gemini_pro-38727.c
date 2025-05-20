//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *word;
  char *translation;
} WordPair;

WordPair dictionary[] = {
  { "meow", "food" },
  { "purr", "water" },
  { "hiss", "danger" },
  { "chirp", "friend" },
  { "growl", "enemy" },
  { "mew", "call" },
  { "yowl", "help" },
  { "trill", "play" },
  { "chatter", "talk" },
  { "purrrrrr", "love" }
};

int main() {
  char *input;
  char *output;
  int i;

  input = (char *)malloc(100);
  output = (char *)malloc(100);

  printf("Enter a cat word: ");
  scanf("%s", input);

  for (i = 0; i < 10; i++) {
    if (strcmp(input, dictionary[i].word) == 0) {
      strcpy(output, dictionary[i].translation);
      break;
    }
  }

  if (i == 10) {
    printf("I don't know that word.\n");
  } else {
    printf("Translation: %s\n", output);
  }

  free(input);
  free(output);

  return 0;
}