//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  printf("Enter a message: ");
  gets(str);

  int isSpam = spamDetection(str);

  if (isSpam) {
    printf("Message is spam.\n");
  } else {
    printf("Message is not spam.\n");
  }

  return 0;
}

int spamDetection(char *str) {
  // Check for common spam words
  char *words[] = {"free", "lottery", "miracle", "prize", "discount"};
  int i = 0;

  for (i = 0; i < 5; i++) {
    if (strstr(str, words[i]) != NULL) {
      return 1;
    }
  }

  // Check for exclamation marks
  if (strchr(str, '!') != NULL) {
    return 1;
  }

  // Check for poor grammar
  if (strchr(str, '?') != NULL) {
    return 1;
  }

  // Check for excessive punctuation
  if (strchr(str, '.') != NULL) {
    return 1;
  }

  // Check for spam-like phrases
  char *phrases[] = {"make money fast", "get rich quick", "free gift", "miracle offer"};
  for (i = 0; i < 3; i++) {
    if (strstr(str, phrases[i]) != NULL) {
      return 1;
    }
  }

  return 0;
}