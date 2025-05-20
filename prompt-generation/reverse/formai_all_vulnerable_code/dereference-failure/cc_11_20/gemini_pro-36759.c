//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MIN 8
#define N_MAX 16

int main(void) {
  char *password;
  int i, n;

  // Prompt the user for a password.
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the length of the password.
  n = strlen(password);
  if (n < N_MIN) {
    printf("Your password is too short.\n");
    return 1;
  }
  if (n > N_MAX) {
    printf("Your password is too long.\n");
    return 1;
  }

  // Check the strength of the password.
  int score = 0;
  for (i = 0; i < n; i++) {
    char c = password[i];
    if (c >= 'a' && c <= 'z') {
      score++;
    }
    if (c >= 'A' && c <= 'Z') {
      score++;
    }
    if (c >= '0' && c <= '9') {
      score++;
    }
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%') {
      score++;
    }
  }

  if (score < 5) {
    printf("Your password is weak.\n");
  } else if (score < 8) {
    printf("Your password is moderate.\n");
  } else {
    printf("Your password is strong.\n");
  }

  // Free the memory allocated for the password.
  free(password);

  return 0;
}