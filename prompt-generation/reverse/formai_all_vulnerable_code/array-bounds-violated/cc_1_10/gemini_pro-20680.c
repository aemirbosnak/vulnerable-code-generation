//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

char *dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening dictionary file: %s\n", filename);
    exit(1);
  }

  char line[MAX_WORD_LENGTH];
  while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
    line[strlen(line) - 1] = '\0';  // remove newline character
    dictionary[dictionary_size++] = strdup(line);
  }

  fclose(file);
}

int check_spelling(char *word) {
  for (int i = 0; i < dictionary_size; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s dictionary_file\n", argv[0]);
    exit(1);
  }

  load_dictionary(argv[1]);

  char word[MAX_WORD_LENGTH];
  while (1) {
    printf("Enter a word: ");
    scanf("%s", word);

    if (strcmp(word, "quit") == 0) {
      break;
    }

    if (check_spelling(word)) {
      printf("The word '%s' is spelled correctly.\n", word);
    } else {
      printf(
          "The word '%s' is not spelled correctly.\n"
          "Did you mean one of these?\n",
          word);

      int found = 0;
      for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) != 0) {
          continue;
        }

        if (found == 0) {
          printf(" - %s\n", dictionary[i]);
          found = 1;
        }
      }

      if (found == 0) {
        printf("No suggestions found.\n");
      }
    }
  }

  return 0;
}