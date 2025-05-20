//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 64

// Define the character types
#define UPPERCASE 0
#define LOWERCASE 1
#define NUMBER 2
#define SYMBOL 3

// Function to check if a character is uppercase
int is_uppercase(char c) {
  return c >= 'A' && c <= 'Z';
}

// Function to check if a character is lowercase
int is_lowercase(char c) {
  return c >= 'a' && c <= 'z';
}

// Function to check if a character is a number
int is_number(char c) {
  return c >= '0' && c <= '9';
}

// Function to check if a character is a symbol
int is_symbol(char c) {
  return !is_uppercase(c) && !is_lowercase(c) && !is_number(c);
}

// Function to calculate the password strength
int calculate_password_strength(char *password) {
  int length = strlen(password);

  // Check if the password is too short
  if (length < MIN_LENGTH) {
    return WEAK;
  }

  // Check if the password is too long
  if (length > MAX_LENGTH) {
    return WEAK;
  }

  // Check if the password contains any uppercase characters
  int has_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (is_uppercase(password[i])) {
      has_uppercase = 1;
      break;
    }
  }

  // Check if the password contains any lowercase characters
  int has_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (is_lowercase(password[i])) {
      has_lowercase = 1;
      break;
    }
  }

  // Check if the password contains any numbers
  int has_number = 0;
  for (int i = 0; i < length; i++) {
    if (is_number(password[i])) {
      has_number = 1;
      break;
    }
  }

  // Check if the password contains any symbols
  int has_symbol = 0;
  for (int i = 0; i < length; i++) {
    if (is_symbol(password[i])) {
      has_symbol = 1;
      break;
    }
  }

  // Calculate the password strength
  int strength = 0;
  if (has_uppercase) {
    strength++;
  }
  if (has_lowercase) {
    strength++;
  }
  if (has_number) {
    strength++;
  }
  if (has_symbol) {
    strength++;
  }

  return strength;
}

// Function to print the password strength
void print_password_strength(char *password) {
  int strength = calculate_password_strength(password);

  switch (strength) {
    case WEAK:
      printf("Your password is weak. Please choose a stronger password.\n");
      break;
    case MEDIUM:
      printf("Your password is medium. It could be stronger, but it's not bad.\n");
      break;
    case STRONG:
      printf("Your password is strong. Good job!\n");
      break;
  }
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Print the password strength
  print_password_strength(password);

  return 0;
}