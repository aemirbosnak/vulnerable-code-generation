#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[1024];
  int text_len = 0;
  int summary_len = 0;
  int word_count = 0;

  printf("Enter text: ");
  fgets(text, 1024, stdin);

  text_len = strlen(text);
  word_count = text_len / 3;
  summary_len = word_count * 4;

  if (summary_len > 1024) {
    summary_len = 1024;
  }

  char summary[summary_len];
  summary[0] = '\0';

  // Overflow-prone summary length calculation
  summary_len = summary_len * 2;
  summary[summary_len - 1] = '\0';

  // Summary generation
  // (Logic omitted for brevity)

  printf("Summary: \n");
  printf("%s", summary);

  return 0;
}
