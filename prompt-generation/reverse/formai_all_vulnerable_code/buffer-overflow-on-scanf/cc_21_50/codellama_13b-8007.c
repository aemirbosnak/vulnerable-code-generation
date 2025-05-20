//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
/*
 * A Grateful Password Strength Checker
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 8
#define PASSWORD_STRENGTH_THRESHOLD 10

int check_password_strength(char *password) {
  int password_length = strlen(password);
  int password_strength = 0;

  // Check for length
  if (password_length < PASSWORD_LENGTH) {
    printf("Password is too short!\n");
    return 0;
  }

  // Check for uppercase letters
  if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') ||
      strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') ||
      strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') ||
      strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') ||
      strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') ||
      strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') ||
      strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') ||
      strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') ||
      strchr(password, 'Y') || strchr(password, 'Z')) {
    password_strength++;
  }

  // Check for lowercase letters
  if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') ||
      strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') ||
      strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') ||
      strchr(password, 'j') || strchr(password, 'k') || strchr(password, 'l') ||
      strchr(password, 'm') || strchr(password, 'n') || strchr(password, 'o') ||
      strchr(password, 'p') || strchr(password, 'q') || strchr(password, 'r') ||
      strchr(password, 's') || strchr(password, 't') || strchr(password, 'u') ||
      strchr(password, 'v') || strchr(password, 'w') || strchr(password, 'x') ||
      strchr(password, 'y') || strchr(password, 'z')) {
    password_strength++;
  }

  // Check for numbers
  if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') ||
      strchr(password, '3') || strchr(password, '4') || strchr(password, '5') ||
      strchr(password, '6') || strchr(password, '7') || strchr(password, '8') ||
      strchr(password, '9')) {
    password_strength++;
  }

  // Check for special characters
  if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') ||
      strchr(password, '$') || strchr(password, '%') || strchr(password, '^') ||
      strchr(password, '&') || strchr(password, '*') || strchr(password, '-') ||
      strchr(password, '+') || strchr(password, '=') || strchr(password, '?') ||
      strchr(password, '/') || strchr(password, '|') || strchr(password, '\\') ||
      strchr(password, '>') || strchr(password, '<')) {
    password_strength++;
  }

  return password_strength >= PASSWORD_STRENGTH_THRESHOLD;
}

int main() {
  char password[PASSWORD_LENGTH + 1];

  printf("Enter a password: ");
  scanf("%s", password);

  if (check_password_strength(password)) {
    printf("Password is strong!\n");
  } else {
    printf("Password is weak!\n");
  }

  return 0;
}