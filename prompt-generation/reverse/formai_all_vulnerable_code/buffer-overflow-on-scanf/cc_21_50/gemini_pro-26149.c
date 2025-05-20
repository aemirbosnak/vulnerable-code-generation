//GEMINI-pro DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 100

// Define the number of password categories
#define NUM_PASSWORD_CATEGORIES 5

// Define the password categories
char *password_categories[] = {
  "Weak",
  "Fair",
  "Good",
  "Strong",
  "Excellent"
};

// Define the password strength calculation function
int calculate_password_strength(char *password) {
  int strength = 0;

  // Check the password length
  if (strlen(password) >= 8) {
    strength++;
  }

  // Check the password for uppercase letters
  if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') || strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') || strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') || strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') || strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') || strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') || strchr(password, 'Y') || strchr(password, 'Z')) {
    strength++;
  }

  // Check the password for lowercase letters
  if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') || strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') || strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') || strchr(password, 'j') || strchr(password, 'k') || strchr(password, 'l') || strchr(password, 'm') || strchr(password, 'n') || strchr(password, 'o') || strchr(password, 'p') || strchr(password, 'q') || strchr(password, 'r') || strchr(password, 's') || strchr(password, 't') || strchr(password, 'u') || strchr(password, 'v') || strchr(password, 'w') || strchr(password, 'x') || strchr(password, 'y') || strchr(password, 'z')) {
    strength++;
  }

  // Check the password for numbers
  if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
    strength++;
  }

  // Check the password for special characters
  if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*') || strchr(password, '(') || strchr(password, ')') || strchr(password, '-') || strchr(password, '_') || strchr(password, '+') || strchr(password, '=') || strchr(password, '[') || strchr(password, ']') || strchr(password, '{') || strchr(password, '}') || strchr(password, '\\') || strchr(password, '|') || strchr(password, '"') || strchr(password, ',') || strchr(password, '<') || strchr(password, '>') || strchr(password, '/') || strchr(password, '?')) {
    strength++;
  }

  return strength;
}

// Define the main function
int main() {
  // Declare the password variable
  char password[MAX_PASSWORD_LENGTH];

  // Prompt the user to enter a password
  printf("Enter a password: ");
  scanf("%s", password);

  // Calculate the password strength
  int strength = calculate_password_strength(password);

  // Print the password strength
  printf("Password strength: %s\n", password_categories[strength]);

  return 0;
}