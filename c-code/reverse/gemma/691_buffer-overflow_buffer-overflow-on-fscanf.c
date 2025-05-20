#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char word[20];
  int word_count = 0;
  int line_count = 0;

  fp = fopen("log.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    word_count++;
  }

  fclose(fp);

  fp = fopen("log.txt", "r");
  while (fscanf(fp, "%s", word) != EOF) {
    line_count++;
  }

  fclose(fp);

  printf("Word count: %d\n", word_count);
  printf("Line count: %d\n", line_count);

  return 0;
}
