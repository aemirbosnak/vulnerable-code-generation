//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store the password information
typedef struct {
  char *password;
  int length;
  int uppercase;
  int lowercase;
  int numbers;
  int special;
} Password;

// Function to check the password strength
int check_password_strength(Password *password) {
  int strength = 0;
  // Check for length
  if (password->length >= 8) {
    strength += 1;
  }
  // Check for uppercase letters
  if (strchr(password->password, 'A') || strchr(password->password, 'B') || strchr(password->password, 'C') || strchr(password->password, 'D') || strchr(password->password, 'E') || strchr(password->password, 'F') || strchr(password->password, 'G') || strchr(password->password, 'H') || strchr(password->password, 'I') || strchr(password->password, 'J') || strchr(password->password, 'K') || strchr(password->password, 'L') || strchr(password->password, 'M') || strchr(password->password, 'N') || strchr(password->password, 'O') || strchr(password->password, 'P') || strchr(password->password, 'Q') || strchr(password->password, 'R') || strchr(password->password, 'S') || strchr(password->password, 'T') || strchr(password->password, 'U') || strchr(password->password, 'V') || strchr(password->password, 'W') || strchr(password->password, 'X') || strchr(password->password, 'Y') || strchr(password->password, 'Z')) {
    strength += 1;
  }
  // Check for lowercase letters
  if (strchr(password->password, 'a') || strchr(password->password, 'b') || strchr(password->password, 'c') || strchr(password->password, 'd') || strchr(password->password, 'e') || strchr(password->password, 'f') || strchr(password->password, 'g') || strchr(password->password, 'h') || strchr(password->password, 'i') || strchr(password->password, 'j') || strchr(password->password, 'k') || strchr(password->password, 'l') || strchr(password->password, 'm') || strchr(password->password, 'n') || strchr(password->password, 'o') || strchr(password->password, 'p') || strchr(password->password, 'q') || strchr(password->password, 'r') || strchr(password->password, 's') || strchr(password->password, 't') || strchr(password->password, 'u') || strchr(password->password, 'v') || strchr(password->password, 'w') || strchr(password->password, 'x') || strchr(password->password, 'y') || strchr(password->password, 'z')) {
    strength += 1;
  }
  // Check for numbers
  if (strchr(password->password, '0') || strchr(password->password, '1') || strchr(password->password, '2') || strchr(password->password, '3') || strchr(password->password, '4') || strchr(password->password, '5') || strchr(password->password, '6') || strchr(password->password, '7') || strchr(password->password, '8') || strchr(password->password, '9')) {
    strength += 1;
  }
  // Check for special characters
  if (strchr(password->password, '!') || strchr(password->password, '@') || strchr(password->password, '#') || strchr(password->password, '$') || strchr(password->password, '%') || strchr(password->password, '^') || strchr(password->password, '&') || strchr(password->password, '*') || strchr(password->password, '(') || strchr(password->password, ')') || strchr(password->password, '-') || strchr(password->password, '_') || strchr(password->password, '+') || strchr(password->password, '=') || strchr(password->password, '~') || strchr(password->password, '`') || strchr(password->password, '{') || strchr(password->password, '}') || strchr(password->password, '[') || strchr(password->password, ']') || strchr(password->password, '|') || strchr(password->password, ':') || strchr(password->password, ';') || strchr(password->password, '\'') || strchr(password->password, '"') || strchr(password->password, ',')) {
    strength += 1;
  }
  // Return the strength
  return strength;
}

// Main function
int main() {
  // Declare variables
  char password[100];
  int strength;

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  strength = check_password_strength(password);

  // Print the password strength
  if (strength == 0) {
    printf("Your password is weak.\n");
  } else if (strength == 1) {
    printf("Your password is moderately strong.\n");
  } else if (strength == 2) {
    printf("Your password is strong.\n");
  } else if (strength == 3) {
    printf("Your password is very strong.\n");
  } else if (strength == 4) {
    printf("Your password is extremely strong.\n");
  }

  return 0;
}