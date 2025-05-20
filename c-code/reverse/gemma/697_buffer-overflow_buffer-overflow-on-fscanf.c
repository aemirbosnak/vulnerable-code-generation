#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("log.txt", "r");
  char line[10000];
  int word_count = 0;
  char *word = NULL;

  if (fp) {
    while (fgets(line, 10000, fp) != NULL) {
      word = strtok(line, " ");
      while (word) {
        word_count++;
        word = strtok(NULL, " ");
      }
    }
  }

  printf("Total word count: %d\n", word_count);

  return 0;
}
