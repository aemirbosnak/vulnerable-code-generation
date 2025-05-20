//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_DICT_SIZE 1000

typedef struct {
  char alien_word[MAX_WORD_LEN];
  char english_word[MAX_WORD_LEN];
} DictEntry;

DictEntry dict[MAX_DICT_SIZE];
int dict_size = 0;

void load_dictionary() {
  FILE *fp = fopen("alien_dict.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(1);
  }

  char line[MAX_WORD_LEN * 2];
  while (fgets(line, sizeof(line), fp)) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';  // Remove newline character
    }

    char *alien_word = strtok(line, " ");
    char *english_word = strtok(NULL, " ");

    if (alien_word != NULL && english_word != NULL) {
      strcpy(dict[dict_size].alien_word, alien_word);
      strcpy(dict[dict_size].english_word, english_word);
      dict_size++;
    }
  }

  fclose(fp);
}

void translate_alien_word(char *alien_word) {
  int i;
  for (i = 0; i < dict_size; i++) {
    if (strcmp(alien_word, dict[i].alien_word) == 0) {
      printf("%s\n", dict[i].english_word);
      return;
    }
  }

  printf("Unknown alien word: %s\n", alien_word);
}

void translate_english_word(char *english_word) {
  int i;
  for (i = 0; i < dict_size; i++) {
    if (strcmp(english_word, dict[i].english_word) == 0) {
      printf("%s\n", dict[i].alien_word);
      return;
    }
  }

  printf("Unknown English word: %s\n", english_word);
}

int main() {
  load_dictionary();

  char input[MAX_WORD_LEN];
  while (1) {
    printf("Enter an alien word or an English word (or 'q' to quit): ");
    scanf("%s", input);

    if (strcmp(input, "q") == 0) {
      break;
    }

    int i;
    for (i = 0; i < strlen(input); i++) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        translate_alien_word(input);
        break;
      } else if (input[i] >= 'A' && input[i] <= 'Z') {
        translate_english_word(input);
        break;
      }
    }

    if (i == strlen(input)) {
      printf("Invalid input: %s\n", input);
    }
  }

  return 0;
}