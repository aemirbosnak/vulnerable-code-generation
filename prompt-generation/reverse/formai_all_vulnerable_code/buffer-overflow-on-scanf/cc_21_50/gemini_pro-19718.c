//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    printf("Password is too short. Minimum length is 8 characters.\n");
  } else {
    strength++;
  }

  // Check if the password contains at least one uppercase letter
  if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') || strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') || strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') || strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') || strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') || strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') || strchr(password, 'Y') || strchr(password, 'Z')) {
    strength++;
  }

  // Check if the password contains at least one lowercase letter
  if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') || strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') || strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') || strchr(password, 'j') || strchr(password, 'k') || strchr(password, 'l') || strchr(password, 'm') || strchr(password, 'n') || strchr(password, 'o') || strchr(password, 'p') || strchr(password, 'q') || strchr(password, 'r') || strchr(password, 's') || strchr(password, 't') || strchr(password, 'u') || strchr(password, 'v') || strchr(password, 'w') || strchr(password, 'x') || strchr(password, 'y') || strchr(password, 'z')) {
    strength++;
  }

  // Check if the password contains at least one digit
  if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
    strength++;
  }

  // Check if the password contains at least one special character
  if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*') || strchr(password, '(') || strchr(password, ')') || strchr(password, '-') || strchr(password, '+') || strchr(password, '=') || strchr(password, '[') || strchr(password, ']') || strchr(password, '{') || strchr(password, '}') || strchr(password, ';') || strchr(password, ':') || strchr(password, ',') || strchr(password, '<') || strchr(password, '>') || strchr(password, '?') ||
      strchr(password, '/')) {
    strength++;
  }

  return strength;
}

int main() {
  char password[100];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the strength of the password
  switch (strength) {
  case 0:
    printf("Password is weak.\n");
    break;
  case 1:
    printf("Password is fair.\n");
    break;
  case 2:
    printf("Password is good.\n");
    break;
  case 3:
    printf("Password is strong.\n");
    break;
  case 4:
    printf("Password is very strong.\n");
    break;
  default:
    printf("Invalid password.\n");
    break;
  }

  return 0;
}