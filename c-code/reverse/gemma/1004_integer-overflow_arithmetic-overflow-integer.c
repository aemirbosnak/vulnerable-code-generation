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

  printf("Enter text: ");
  fgets(text, 1024, stdin);

  text_len = strlen(text);
  summary_len = (text_len / 3) * 4 + 1;

  if (summary_len > 256) {
    summary_len = 256;
  }

  char summary[summary_len];
  summary[0] = '\0';

  // Overflow-prone summary length calculation
  summary_len = summary_len * 2;

  if (summary_len > 256) {
    summary_len = 256;
  }

  summary[summary_len - 1] = '\0';

  printf("Summary: %s", summary);

  return 0;
}
