#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char* summarize_text(char* text) {
  int text_length = strlen(text);
  int summary_length = text_length / 5;
  char* summary = malloc(summary_length);

  int i = 0;
  for (i = 0; i < text_length && i < summary_length; i++) {
    summary[i] = text[i];
  }

  return summary;
}

int main() {
  char* text = "This is a long text that I want to summarize. It is very long, but I need to summarize it without crashing. I will accept a small risk of integer overflow in edge cases to ensure efficiency.";
  char* summary = summarize_text(text);

  printf("%s", summary);

  free(summary);

  return 0;
}
