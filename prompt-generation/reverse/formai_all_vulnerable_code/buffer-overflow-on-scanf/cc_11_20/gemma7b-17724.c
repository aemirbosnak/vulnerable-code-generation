//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>

typedef struct {
  char word[20];
  int translate;
} dictionary_t;

dictionary_t dictionary[] = {
  {"cat", 1},
  {"dog", 2},
  {"fish", 3},
  {"bird", 4},
  {"house", 5}
};

int main() {
  char input[20];
  int i, word_length, translation;

  printf("Enter a word: ");
  scanf("%s", input);

  word_length = strlen(input);

  for (i = 0; i < word_length; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      input[i] -= 32;
    }
  }

  for (i = 0; dictionary[i].word; i++) {
    if (strcmp(input, dictionary[i].word) == 0) {
      translation = dictionary[i].translate;
      break;
    }
  }

  printf("Translation: ");
  switch (translation) {
    case 1:
      printf("Meow\n");
      break;
    case 2:
      printf("Woof\n");
      break;
    case 3:
      printf("Swim\n");
      break;
    case 4:
      printf("Chirp\n");
      break;
    case 5:
      printf("Boom\n");
      break;
  }

  return 0;
}