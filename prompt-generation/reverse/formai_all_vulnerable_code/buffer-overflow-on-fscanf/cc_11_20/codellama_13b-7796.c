//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 100000

struct dictionary {
  char word[MAX_WORD_LEN];
  int frequency;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
    return 1;
  }

  FILE *dict_file = fopen(argv[1], "r");
  if (!dict_file) {
    fprintf(stderr, "Error opening dictionary file %s\n", argv[1]);
    return 1;
  }

  struct dictionary dict[MAX_DICT_SIZE];
  int dict_size = 0;
  while (fscanf(dict_file, "%s", dict[dict_size].word) != EOF) {
    dict[dict_size].frequency = 1;
    dict_size++;
  }
  fclose(dict_file);

  char word[MAX_WORD_LEN];
  while (fgets(word, sizeof(word), stdin)) {
    for (int i = 0; i < strlen(word); i++) {
      if (!isalpha(word[i])) {
        continue;
      }
      int j = 0;
      while (j < dict_size && strcmp(dict[j].word, word + i)) {
        j++;
      }
      if (j == dict_size) {
        printf("%s is not a valid word\n", word + i);
        break;
      }
      dict[j].frequency++;
    }
  }

  for (int i = 0; i < dict_size; i++) {
    printf("%s: %d\n", dict[i].word, dict[i].frequency);
  }

  return 0;
}