//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int num_words = 0;

int main() {
  char word[MAX_WORD_LENGTH + 1];
  FILE *fp;

  fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    if (num_words >= MAX_WORDS) {
      fprintf(stderr, "Error: Dictionary contains too many words\n");
      return EXIT_FAILURE;
    }

    words[num_words++] = strdup(word);
  }

  fclose(fp);

  while (1) {
    printf("Enter a word to check (or q to quit): ");
    scanf("%s", word);

    if (strcmp(word, "q") == 0) {
      break;
    }

    int found = 0;

    for (int i = 0; i < num_words; i++) {
      if (strcmp(word, words[i]) == 0) {
        printf("The word '%s' is spelled correctly.\n", word);
        found = 1;
        break;
      }
    }

    if (!found) {
      printf("The word '%s' is not spelled correctly.\n", word);
    }
  }

  return EXIT_SUCCESS;
}