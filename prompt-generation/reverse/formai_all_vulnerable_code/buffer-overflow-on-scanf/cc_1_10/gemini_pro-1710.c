//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages
#define PASSWORD_STRENGTH_WEAK_MESSAGE "Weak"
#define PASSWORD_STRENGTH_MEDIUM_MESSAGE "Medium"
#define PASSWORD_STRENGTH_STRONG_MESSAGE "Strong"

// Define the character class names
#define CHAR_CLASS_LOWER_NAME "Lowercase"
#define CHAR_CLASS_UPPER_NAME "Uppercase"
#define CHAR_CLASS_DIGIT_NAME "Digit"
#define CHAR_CLASS_SPECIAL_NAME "Special"

// Define the password strength factors
#define PASSWORD_STRENGTH_FACTOR_LENGTH 1
#define PASSWORD_STRENGTH_FACTOR_CHAR_CLASSES 2
#define PASSWORD_STRENGTH_FACTOR_REPETITION 3

// Get the password strength
int get_password_strength(char *password) {
  // Calculate the password length
  int password_length = strlen(password);

  // Check if the password length is valid
  if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Calculate the number of character classes
  int char_classes = 0;
  for (int i = 0; i < password_length; i++) {
    char c = password[i];
    if (islower(c)) {
      char_classes |= (1 << CHAR_CLASS_LOWER);
    } else if (isupper(c)) {
      char_classes |= (1 << CHAR_CLASS_UPPER);
    } else if (isdigit(c)) {
      char_classes |= (1 << CHAR_CLASS_DIGIT);
    } else {
      char_classes |= (1 << CHAR_CLASS_SPECIAL);
    }
  }

  // Check if the password contains at least 3 character classes
  if (char_classes < 3) {
    return PASSWORD_STRENGTH_MEDIUM;
  }

  // Calculate the number of character repetitions
  int repetitions = 0;
  for (int i = 0; i < password_length; i++) {
    char c = password[i];
    if (i > 0 && c == password[i - 1]) {
      repetitions++;
    }
  }

  // Check if the password contains more than 3 character repetitions
  if (repetitions > 3) {
    return PASSWORD_STRENGTH_WEAK;
  }

  // Calculate the password strength
  int password_strength = PASSWORD_STRENGTH_FACTOR_LENGTH * password_length + PASSWORD_STRENGTH_FACTOR_CHAR_CLASSES * char_classes - PASSWORD_STRENGTH_FACTOR_REPETITION * repetitions;

  // Return the password strength
  return password_strength;
}

// Get the password strength message
char *get_password_strength_message(int password_strength) {
  switch (password_strength) {
    case PASSWORD_STRENGTH_WEAK:
      return PASSWORD_STRENGTH_WEAK_MESSAGE;
    case PASSWORD_STRENGTH_MEDIUM:
      return PASSWORD_STRENGTH_MEDIUM_MESSAGE;
    case PASSWORD_STRENGTH_STRONG:
      return PASSWORD_STRENGTH_STRONG_MESSAGE;
    default:
      return NULL;
  }
}

// Print the password strength report
void print_password_strength_report(char *password) {
  // Get the password strength
  int password_strength = get_password_strength(password);

  // Get the password strength message
  char *password_strength_message = get_password_strength_message(password_strength);

  // Print the password strength report
  printf("Password: %s\n", password);
  printf("Strength: %s\n", password_strength_message);
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter a password: ");
  scanf("%s", password);

  // Print the password strength report
  print_password_strength_report(password);

  return 0;
}