#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  int advertising_count = 0, winning_count = 0, free_count = 0;

  gets(input);

  char *word = strtok(input, " ");
  while (word) {
    if (strcmp(word, "advertising") == 0) {
      advertising_count++;
    } else if (strcmp(word, "winning") == 0) {
      winning_count++;
    } else if (strcmp(word, "free") == 0) {
      free_count++;
    }

    word = strtok(NULL, " ");
  }

  if (advertising_count > 0 || winning_count > 0 || free_count > 0) {
    printf("Warning: Potential spam detected.\n");
  }

  return 0;
}
