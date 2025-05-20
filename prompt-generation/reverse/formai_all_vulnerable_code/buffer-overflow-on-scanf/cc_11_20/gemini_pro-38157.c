//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int main(void) {
  char *password;
  int length, score;

  printf("Enter password: ");
  password = malloc(100);
  scanf("%s", password);

  length = strlen(password);

  if (length < MIN_LENGTH) {
    printf("Password too short\n");
    return 1;
  }

  score = 0;

  for (int i = 0; i < length; i++) {
    char c = password[i];
    if (c >= 'a' && c <= 'z') {
      score++;
    } else if (c >= 'A' && c <= 'Z') {
      score += 2;
    } else if (c >= '0' && c <= '9') {
      score += 3;
    } else {
      score -= 1;
    }
  }

  if (score < 0) {
    printf("Password too weak\n");
    return 1;
  } else if (score < 10) {
    printf("Password is fair\n");
  } else if (score < 15) {
    printf("Password is good\n");
  } else {
    printf("Password is strong\n");
  }

  free(password);
  return 0;
}