//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define OK 1
#define STRONG 2

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 32

// Define the character types
#define CHAR_TYPE_LOWER 0
#define CHAR_TYPE_UPPER 1
#define CHAR_TYPE_DIGIT 2
#define CHAR_TYPE_SPECIAL 3

// Define the character type names
const char *char_type_names[] = {"lower", "upper", "digit", "special"};

// Define the character type weights
const int char_type_weights[] = {1, 2, 3, 4};

// Define the special characters
const char special_chars[] = "!@#$%^&*()-_=+[]{}\\|;:'\",<.>/?";

// Check if the password is valid
int is_valid_password(const char *password) {
  // Check if the password is empty
  if (strlen(password) == 0) {
    return 0;
  }

  // Check if the password is too short
  if (strlen(password) < MIN_LENGTH) {
    return 0;
  }

  // Check if the password is too long
  if (strlen(password) > MAX_LENGTH) {
    return 0;
  }

  // Check if the password contains any invalid characters
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i]) && !strchr(special_chars, password[i])) {
      return 0;
    }
  }

  // Check if the password contains at least one character of each type
  int char_types[4] = {0, 0, 0, 0};
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      char_types[CHAR_TYPE_LOWER] = 1;
    } else if (isupper(password[i])) {
      char_types[CHAR_TYPE_UPPER] = 1;
    } else if (isdigit(password[i])) {
      char_types[CHAR_TYPE_DIGIT] = 1;
    } else if (strchr(special_chars, password[i])) {
      char_types[CHAR_TYPE_SPECIAL] = 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (char_types[i] == 0) {
      return 0;
    }
  }

  // Return 1 if the password is valid
  return 1;
}

// Calculate the password strength
int calculate_password_strength(const char *password) {
  // Check if the password is valid
  if (!is_valid_password(password)) {
    return WEAK;
  }

  // Calculate the password score
  int score = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      score += char_type_weights[CHAR_TYPE_LOWER];
    } else if (isupper(password[i])) {
      score += char_type_weights[CHAR_TYPE_UPPER];
    } else if (isdigit(password[i])) {
      score += char_type_weights[CHAR_TYPE_DIGIT];
    } else if (strchr(special_chars, password[i])) {
      score += char_type_weights[CHAR_TYPE_SPECIAL];
    }
  }

  // Calculate the password strength level
  int strength = WEAK;
  if (score >= 20) {
    strength = STRONG;
  } else if (score >= 15) {
    strength = OK;
  }

  // Return the password strength level
  return strength;
}

// Print the password strength level
void print_password_strength(const char *password) {
  // Calculate the password strength
  int strength = calculate_password_strength(password);

  // Print the password strength level
  switch (strength) {
    case WEAK:
      printf("Your password is weak.\n");
      break;
    case OK:
      printf("Your password is OK.\n");
      break;
    case STRONG:
      printf("Your password is strong.\n");
      break;
  }
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check if the password is valid
  if (!is_valid_password(password)) {
    printf("Your password is invalid.\n");
    return 1;
  }

  // Calculate the password strength
  int strength = calculate_password_strength(password);

  // Print the password strength level
  print_password_strength(password);

  return 0;
}