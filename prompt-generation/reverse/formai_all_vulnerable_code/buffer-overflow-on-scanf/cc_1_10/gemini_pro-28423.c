//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHARACTER_CLASS_UPPERCASE 1
#define CHARACTER_CLASS_LOWERCASE 2
#define CHARACTER_CLASS_DIGIT 4
#define CHARACTER_CLASS_SPECIAL 8

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2
#define PASSWORD_STRENGTH_VERY_STRONG 3

// Define the password complexity function
double password_complexity(char *password) {
  // Calculate the password length
  int password_length = strlen(password);

  // Calculate the number of character classes present in the password
  int character_classes_present = 0;
  if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
    character_classes_present |= CHARACTER_CLASS_UPPERCASE;
  }
  if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
    character_classes_present |= CHARACTER_CLASS_LOWERCASE;
  }
  if (strpbrk(password, "0123456789")) {
    character_classes_present |= CHARACTER_CLASS_DIGIT;
  }
  if (strpbrk(password, "!@#$%^&*()_+")) {
    character_classes_present |= CHARACTER_CLASS_SPECIAL;
  }

  // Calculate the password strength
  double password_strength = 0.0;
  password_strength += log2(password_length);
  password_strength += log2(character_classes_present);

  return password_strength;
}

// Define the main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    printf("Your password is too short. It must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
    return 1;
  }

  // Check the password strength
  double password_strength = password_complexity(password);
  if (password_strength < 1.0) {
    printf("Your password is weak. Please choose a stronger password.\n");
    return 1;
  } else if (password_strength < 2.0) {
    printf("Your password is medium. It could be stronger.\n");
  } else if (password_strength < 3.0) {
    printf("Your password is strong. Good job!\n");
  } else {
    printf("Your password is very strong. Excellent choice!\n");
  }

  return 0;
}