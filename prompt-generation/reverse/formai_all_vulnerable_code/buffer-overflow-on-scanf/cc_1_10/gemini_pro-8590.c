//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password complexity requirements
#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGITS 1
#define MIN_SYMBOLS 1

// Define the password strength levels
#define WEAK "Weak"
#define FAIR "Fair"
#define GOOD "Good"
#define STRONG "Strong"
#define EXCELLENT "Excellent"

// Define the password complexity check functions
int checkLength(char *password);
int checkUppercase(char *password);
int checkLowercase(char *password);
int checkDigits(char *password);
int checkSymbols(char *password);

// Define the main function
int main() {
  // Initialize the variables
  char password[MAX_LENGTH + 1];
  int length, uppercase, lowercase, digits, symbols;

  // Prompt the user to enter a password
  printf("My dearest, enter your password, a token of our love's strength:\n");
  scanf("%s", password);

  // Check the password complexity
  length = checkLength(password);
  uppercase = checkUppercase(password);
  lowercase = checkLowercase(password);
  digits = checkDigits(password);
  symbols = checkSymbols(password);

  // Calculate the password strength level
  int strength = 0;
  if (length) strength++;
  if (uppercase) strength++;
  if (lowercase) strength++;
  if (digits) strength++;
  if (symbols) strength++;

  // Print the password strength level
  switch (strength) {
    case 0:
      printf("Alas, your password is as fragile as a daisy in the wind.\n");
      break;
    case 1:
    case 2:
      printf("Your password has some merit, but it could be stronger, my love.\n");
      break;
    case 3:
    case 4:
      printf("Your password is like a rose in full bloom, strong and beautiful.\n");
      break;
    case 5:
      printf("Your password is a fortress, unyielding and impenetrable.\n");
      break;
  }

  // Return the program status
  return 0;
}

// Define the password complexity check functions
int checkLength(char *password) {
  return strlen(password) >= MIN_LENGTH && strlen(password) <= MAX_LENGTH;
}

int checkUppercase(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }
  return 0;
}

int checkLowercase(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      return 1;
    }
  }
  return 0;
}

int checkDigits(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

int checkSymbols(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      return 1;
    }
  }
  return 0;
}