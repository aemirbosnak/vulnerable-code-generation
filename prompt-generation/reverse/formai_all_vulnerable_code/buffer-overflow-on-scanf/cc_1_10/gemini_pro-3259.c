//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 128
#define ENTROPY_PER_CHARACTER_UPPERCASE 2.3219
#define ENTROPY_PER_CHARACTER_LOWERCASE 2.3219
#define ENTROPY_PER_CHARACTER_DIGIT 2.5849
#define ENTROPY_PER_CHARACTER_SYMBOL 4.6438

// Function to calculate password strength based on Shannon entropy
double calculate_password_strength(char *password) {
  int password_length = strlen(password);
  double entropy = 0;

  for (int i = 0; i < password_length; i++) {
    char character = password[i];

    if (character >= 'A' && character <= 'Z') {
      entropy += ENTROPY_PER_CHARACTER_UPPERCASE;
    } else if (character >= 'a' && character <= 'z') {
      entropy += ENTROPY_PER_CHARACTER_LOWERCASE;
    } else if (character >= '0' && character <= '9') {
      entropy += ENTROPY_PER_CHARACTER_DIGIT;
    } else {
      entropy += ENTROPY_PER_CHARACTER_SYMBOL;
    }
  }

  return entropy / password_length;
}

// Function to check if a password is strong
int is_password_strong(char *password) {
  double password_strength = calculate_password_strength(password);

  return password_strength >= 5.0;
}

// Main function
int main() {
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter a password: ");
  scanf("%s", password);

  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    printf("Password is too short.\n");
    return EXIT_FAILURE;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    printf("Password is too long.\n");
    return EXIT_FAILURE;
  } else if (!is_password_strong(password)) {
    printf("Password is not strong enough.\n");
    return EXIT_FAILURE;
  } else {
    printf("Password is strong.\n");
    return EXIT_SUCCESS;
  }
}