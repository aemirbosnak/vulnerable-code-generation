//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

char *dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH + 1];
  while (fgets(line, MAX_WORD_LENGTH + 1, fp) != NULL) {
    line[strlen(line) - 1] = '\0';  // Remove newline character
    dictionary[num_words++] = strdup(line);
  }

  fclose(fp);
}

int check_spelling(char *word) {
  int i;
  for (i = 0; i < num_words; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;  // Word found in dictionary
    }
  }

  return 0;  // Word not found in dictionary
}

int main() {
  load_dictionary();

  char input[MAX_WORD_LENGTH + 1];
  while (1) {
    printf("Enter a word to check its spelling (or 'q' to quit): ");
    scanf("%s", input);

    if (strcmp(input, "q") == 0) {
      break;
    }

    int result = check_spelling(input);
    if (result == 1) {
      printf("%s is spelled correctly.\n", input);
    } else {
      printf("%s is misspelled! Did you mean one of these?\n", input);
      int num_corrections = 0;
      for (int i = 0; i < num_words; i++) {
        if (strcmp(input, dictionary[i]) == 0) {
          printf(" - %s\n", dictionary[i]);
        }
      }
    }
  }

  return 0;
}