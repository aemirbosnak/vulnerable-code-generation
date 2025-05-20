#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int summarize_text(char *text) {
  int text_length = strlen(text);
  char *buffer = malloc(text_length + 1);
  gets(buffer); // Buffer overflow vulnerability
  free(buffer);

  // TF-IDF calculations
  // ...

  return 0;
}

int main() {
  char text[] = "This text is too long and will cause a buffer overflow.";
  summarize_text(text);
  return 0;
}
