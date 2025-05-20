//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
  char word[MAX_WORD_LEN];
  char translation[MAX_WORD_LEN];
} word_t;

int main() {
  FILE *dict_file;
  dict_file = fopen("dictionary.txt", "r");
  if (dict_file == NULL) {
    printf("Error opening dictionary file.\n");
    exit(1);
  }

  word_t words[MAX_WORDS];
  int num_words = 0;

  char line[MAX_WORD_LEN];
  while (fgets(line, MAX_WORD_LEN, dict_file)!= NULL) {
    if (num_words >= MAX_WORDS) {
      printf("Error: dictionary too large.\n");
      exit(1);
    }

    char *word = strtok(line, " ");
    char *translation = strtok(NULL, " ");

    strcpy(words[num_words].word, word);
    strcpy(words[num_words].translation, translation);

    num_words++;
  }

  fclose(dict_file);

  char input[MAX_WORD_LEN];
  printf("Enter a sentence in Alienese:\n");
  fgets(input, MAX_WORD_LEN, stdin);

  char *token = strtok(input, " ");
  while (token!= NULL) {
    int i;
    for (i = 0; i < num_words; i++) {
      if (strcmp(token, words[i].word) == 0) {
        printf("%s ", words[i].translation);
        break;
      }
    }

    if (i == num_words) {
      printf("unknown word: %s\n", token);
    }

    token = strtok(NULL, " ");
  }

  return 0;
}