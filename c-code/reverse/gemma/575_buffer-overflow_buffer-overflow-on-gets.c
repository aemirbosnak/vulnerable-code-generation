#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[1024];
  gets(text);

  int spam_score = 0;
  char* spam_phrases[] = {"free", "lottery", "miracle", "prize", "quick", "easy"};
  for (int i = 0; i < 6; i++) {
    if (strstr(text, spam_phrases[i]) != NULL) {
      spam_score++;
    }
  }

  if (spam_score >= 3) {
    printf("Text contains excessive spam keywords. Potential spam.");
  } else {
    printf("Text does not contain excessive spam keywords. Safe to read.");
  }

  return 0;
}
