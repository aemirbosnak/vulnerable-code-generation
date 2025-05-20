#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[1000];
  printf("Enter text: ");
  fgets(text, 1000, stdin);

  int sentiment = analyze_sentiment(text);

  switch (sentiment) {
    case 0:
      printf("Neutral\n");
      break;
    case 1:
      printf("Happy\n");
      break;
    case -1:
      printf("Sad\n");
      break;
  }

  return 0;
}

int analyze_sentiment(char *text) {
  char emoticons[] = {':)', ':)', ':('};
  int i, sentiment = 0;

  for (i = 0; emoticons[i] != '\0'; i++) {
    if (strstr(text, emoticons[i]) != NULL) {
      sentiment++;
    }
  }

  if (sentiment > 0) {
    return 1;
  } else if (sentiment < 0) {
    return -1;
  } else {
    return 0;
  }
}
