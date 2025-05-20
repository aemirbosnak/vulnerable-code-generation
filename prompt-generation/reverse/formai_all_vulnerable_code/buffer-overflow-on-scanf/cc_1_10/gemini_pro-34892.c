//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Function to check if a character is in a given character class
int char_in_class(char c, int char_class) {
  switch (char_class) {
    case CHAR_CLASS_LOWER:
      return (c >= 'a' && c <= 'z');
    case CHAR_CLASS_UPPER:
      return (c >= 'A' && c <= 'Z');
    case CHAR_CLASS_DIGIT:
      return (c >= '0' && c <= '9');
    case CHAR_CLASS_SPECIAL:
      return (c >= '!' && c <= '~');
    default:
      return 0;
  }
}

// Function to calculate the password strength
int calculate_password_strength(char *password) {
  int char_classes_present = 0;
  int password_length = strlen(password);

  // Check for the presence of at least one character from each character class
  char_classes_present += char_in_class(password[0], CHAR_CLASS_LOWER);
  char_classes_present += char_in_class(password[0], CHAR_CLASS_UPPER);
  char_classes_present += char_in_class(password[0], CHAR_CLASS_DIGIT);
  char_classes_present += char_in_class(password[0], CHAR_CLASS_SPECIAL);

  // Check for the password length
  if (password_length < MIN_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_WEAK;
  } else if (password_length >= MIN_PASSWORD_LENGTH && password_length <= MAX_PASSWORD_LENGTH) {
    return PASSWORD_STRENGTH_MEDIUM;
  } else {
    return PASSWORD_STRENGTH_STRONG;
  }
}

// Function to print the password strength
void print_password_strength(int password_strength) {
  switch (password_strength) {
    case PASSWORD_STRENGTH_WEAK:
      printf("Weak password\n");
      break;
    case PASSWORD_STRENGTH_MEDIUM:
      printf("Medium password\n");
      break;
    case PASSWORD_STRENGTH_STRONG:
      printf("Strong password\n");
      break;
  }
}

// Main function
int main(int argc, char *argv[]) {
  char password[MAX_PASSWORD_LENGTH + 1];

  // Prompt the user to enter a password
  printf("Enter a password: ");
  scanf("%s", password);

  // Calculate the password strength
  int password_strength = calculate_password_strength(password);

  // Print the password strength
  print_password_strength(password_strength);

  return 0;
}