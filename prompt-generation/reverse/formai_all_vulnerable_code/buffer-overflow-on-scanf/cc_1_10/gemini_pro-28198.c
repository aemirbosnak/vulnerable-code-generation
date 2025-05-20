//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: retro
#include <stdio.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define GOOD 1
#define STRONG 2

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 20

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()-_=+";

// Define the password strength check function
int check_password_strength(char *password) {
  int strength = WEAK;

  // Check the password length
  if (strlen(password) < MIN_LENGTH) {
    printf("Password is too short.\n");
    return strength;
  } else if (strlen(password) > MAX_LENGTH) {
    printf("Password is too long.\n");
    return strength;
  }

  // Check the password for uppercase characters
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(uppercase, password[i]) != NULL) {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase) {
    printf("Password must contain at least one uppercase character.\n");
    return strength;
  }

  // Check the password for lowercase characters
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(lowercase, password[i]) != NULL) {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase) {
    printf("Password must contain at least one lowercase character.\n");
    return strength;
  }

  // Check the password for numbers
  int has_number = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(numbers, password[i]) != NULL) {
      has_number = 1;
      break;
    }
  }
  if (!has_number) {
    printf("Password must contain at least one number.\n");
    return strength;
  }

  // Check the password for symbols
  int has_symbol = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(symbols, password[i]) != NULL) {
      has_symbol = 1;
      break;
    }
  }
  if (!has_symbol) {
    printf("Password must contain at least one symbol.\n");
    return strength;
  }

  // If all of the checks pass, then the password is strong
  strength = STRONG;
  printf("Password is strong.\n");
  return strength;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
  switch (strength) {
    case WEAK:
      printf("Password is weak.\n");
      break;
    case GOOD:
      printf("Password is good.\n");
      break;
    case STRONG:
      printf("Password is strong.\n");
      break;
  }

  return 0;
}