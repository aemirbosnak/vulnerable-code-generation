//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
// Password Strength Checker Program
#include <stdio.h>
#include <string.h>

// Function to check the strength of a password
int check_strength(char *password) {
  // Variables for password length and strength
  int length = strlen(password);
  int strength = 0;

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
    strength++;
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
    strength++;
  }

  // Check for numbers
  if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') ||
      strchr(password, '3') || strchr(password, '4') || strchr(password, '5') ||
      strchr(password, '6') || strchr(password, '7') || strchr(password, '8') ||
      strchr(password, '9')) {
    strength++;
  }

  // Check for special characters
  if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') ||
      strchr(password, '$') || strchr(password, '%') || strchr(password, '^') ||
      strchr(password, '&') || strchr(password, '*') || strchr(password, '(') ||
      strchr(password, ')') || strchr(password, '-') || strchr(password, '+') ||
      strchr(password, '=') || strchr(password, '~') || strchr(password, '`') ||
      strchr(password, '{') || strchr(password, '}') || strchr(password, '[') ||
      strchr(password, ']') || strchr(password, '|') || strchr(password, ';') ||
      strchr(password, ':') || strchr(password, '"') || strchr(password, '\'') ||
      strchr(password, '<') || strchr(password, '>') || strchr(password, '?') ||
      strchr(password, '/')) {
    strength++;
  }

  // Return the strength value
  return strength;
}

// Main function
int main() {
  // Declare a password variable
  char password[20];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_strength(password);

  // Print the password strength
  if (strength == 0) {
    printf("Your password is too weak.\n");
  } else if (strength == 1) {
    printf("Your password is weak.\n");
  } else if (strength == 2) {
    printf("Your password is medium-strength.\n");
  } else if (strength == 3) {
    printf("Your password is strong.\n");
  } else if (strength == 4) {
    printf("Your password is very strong.\n");
  }

  return 0;
}