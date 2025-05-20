#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char* summarizeText(int maxLen) {
  char* sentence = malloc(maxLen);
  gets(sentence);

  int len = strlen(sentence) + 1;
  char* summary = malloc(len);
  summary = strcpy(summary, sentence);

  return summary;
}

int main() {
  char* summary = summarizeText(100);
  printf("%s", summary);
  free(summary);

  return 0;
}
