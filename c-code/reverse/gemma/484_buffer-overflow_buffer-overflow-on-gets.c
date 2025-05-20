#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  gets(sentence);

  if (strstr(sentence, "happy") != NULL) {
    printf("Sentiment: positive\n");
  } else if (strstr(sentence, "sad") != NULL) {
    printf("Sentiment: negative\n");
  } else {
    printf("Sentiment: neutral\n");
  }

  return 0;
}
