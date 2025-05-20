#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[1024];
  gets(message);

  int advertising_count = 0;
  int winning_count = 0;
  int free_count = 0;

  if (strlen(message) > 0) {
    char *word = strtok(message, " ");
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
  }

  printf("Number of occurrences of 'advertising': %d\n", advertising_count);
  printf("Number of occurrences of 'winning': %d\n", winning_count);
  printf("Number of occurrences of 'free': %d\n", free_count);

  return 0;
}
