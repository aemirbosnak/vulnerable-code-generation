#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  scanf("%s", input);

  int happy_count = 0;
  int sad_count = 0;
  int neutral_count = 0;

  // Emoticon analysis
  if (strchr(input, ':') && strchr(input, ';')) {
    happy_count++;
  } else if (strchr(input, ':') && strchr(input, '-')) {
    sad_count++;
  }

  // Keyword analysis
  if (strchr(input, "happy") || strchr(input, "joy") || strchr(input, "good")) {
    happy_count++;
  } else if (strchr(input, "sad") || strchr(input, "blue") || strchr(input, "bad")) {
    sad_count++;
  } else {
    neutral_count++;
  }

  // Sentiment determination
  if (happy_count > sad_count) {
    printf("Sentiment: Happy\n");
  } else if (sad_count > happy_count) {
    printf("Sentiment: Sad\n");
  } else {
    printf("Sentiment: Neutral\n");
  }

  return 0;
}
