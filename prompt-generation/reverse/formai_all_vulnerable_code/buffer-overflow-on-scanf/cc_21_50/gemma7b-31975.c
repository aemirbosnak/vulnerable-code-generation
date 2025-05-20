//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LEN 255

typedef struct PassStrength {
  int strength;
  char *pass;
} PassStrength;

PassStrength *check_password_strength(char *pass) {
  PassStrength *ps = malloc(sizeof(PassStrength));
  ps->strength = 0;
  ps->pass = strdup(pass);

  // Check for minimum length
  if (strlen(pass) < 8) {
    ps->strength++;
  }

  // Check for uppercase letter
  if (strchr(pass, 'A') || strchr(pass, 'B') || strchr(pass, 'C') ||
    strchr(pass, 'D') || strchr(pass, 'E') || strchr(pass, 'F') ||
    strchr(pass, 'G') || strchr(pass, 'H') || strchr(pass, 'I') ||
    strchr(pass, 'J') || strchr(pass, 'K') || strchr(pass, 'L') ||
    strchr(pass, 'M') || strchr(pass, 'N') || strchr(pass, 'O') ||
    strchr(pass, 'P') || strchr(pass, 'Q') || strchr(pass, 'R') ||
    strchr(pass, 'S') || strchr(pass, 'T') || strchr(pass, 'U') ||
    strchr(pass, 'V') || strchr(pass, 'W') || strchr(pass, 'X') ||
    strchr(pass, 'Y') || strchr(pass, 'Z')) {
    ps->strength++;
  }

  // Check for lowercase letter
  if (strchr(pass, 'a') || strchr(pass, 'b') || strchr(pass, 'c') ||
    strchr(pass, 'd') || strchr(pass, 'e') || strchr(pass, 'f') ||
    strchr(pass, 'g') || strchr(pass, 'h') || strchr(pass, 'i') ||
    strchr(pass, 'j') || strchr(pass, 'k') || strchr(pass, 'l') ||
    strchr(pass, 'm') || strchr(pass, 'n') || strchr(pass, 'o') ||
    strchr(pass, 'p') || strchr(pass, 'q') || strchr(pass, 'r') ||
    strchr(pass, 's') || strchr(pass, 't') || strchr(pass, 'u') ||
    strchr(pass, 'v') || strchr(pass, 'w') || strchr(pass, 'x') ||
    strchr(pass, 'y') || strchr(pass, 'z')) {
    ps->strength++;
  }

  // Check for number
  if (strchr(pass, '0') || strchr(pass, '1') || strchr(pass, '2') ||
    strchr(pass, '3') || strchr(pass, '4') || strchr(pass, '5') ||
    strchr(pass, '6') || strchr(pass, '7') || strchr(pass, '8') ||
    strchr(pass, '9')) {
    ps->strength++;
  }

  // Check for special character
  if (strchr(pass, '$') || strchr(pass, '%') || strchr(pass, '&') ||
    strchr(pass, '(') || strchr(pass, ')') || strchr(pass, '*') ||
    strchr(pass, '+') || strchr(pass, '-') || strchr(pass, '/') ||
    strchr(pass, '\\') || strchr(pass, '^') || strchr(pass, '_') ||
    strchr(pass, '`') || strchr(pass, '|')) {
    ps->strength++;
  }

  return ps;
}

int main() {
  char pass[MAX_PASS_LEN];

  printf("Enter your password: ");
  scanf("%s", pass);

  PassStrength *ps = check_password_strength(pass);

  switch (ps->strength) {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
  }

  free(ps);

  return 0;
}