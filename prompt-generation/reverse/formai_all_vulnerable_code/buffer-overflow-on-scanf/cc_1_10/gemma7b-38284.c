//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **spell_checker(char **arr, int n) {
  int i, j, k, count = 0, flag = 0;
  char **words = NULL;

  words = (char **)malloc(n * sizeof(char *));
  for (i = 0; i < n; i++) {
    words[i] = (char *)malloc(20 * sizeof(char));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < 20; j++) {
      words[i][j] = '\0';
    }
  }

  for (i = 0; i < n; i++) {
    printf("Enter the word: ");
    scanf("%s", words[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < 20; j++) {
      if (words[i][j] != '\0') {
        flag = 1;
      }
    }
  }

  if (flag == 0) {
    printf("No words found.\n");
  } else {
    printf("The words are:\n");
    for (i = 0; i < n; i++) {
      printf("%s\n", words[i]);
    }
  }

  return words;
}

int main() {
  char **arr = NULL;
  int n = 0;

  printf("Enter the number of words: ");
  scanf("%d", &n);

  arr = spell_checker(arr, n);

  return 0;
}