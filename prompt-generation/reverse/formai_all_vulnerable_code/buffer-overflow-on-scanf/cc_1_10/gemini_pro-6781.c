//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password requirements
#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGITS 1
#define MIN_SPECIAL 1

// Define the password strength levels
#define WEAK "Weak"
#define FAIR "Fair"
#define GOOD "Good"
#define STRONG "Strong"

// Function to check if the password meets the minimum length requirement
int checkLength(char *password) {
  int length = strlen(password);
  return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

// Function to check if the password contains at least one uppercase letter
int checkUppercase(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }
  return 0;
}

// Function to check if the password contains at least one lowercase letter
int checkLowercase(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      return 1;
    }
  }
  return 0;
}

// Function to check if the password contains at least one digit
int checkDigits(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

// Function to check if the password contains at least one special character
int checkSpecial(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Function to check the strength of the password
char *checkStrength(char *password) {
  int score = 0;

  // Check the length of the password
  if (checkLength(password)) {
    score++;
  }

  // Check if the password contains at least one uppercase letter
  if (checkUppercase(password)) {
    score++;
  }

  // Check if the password contains at least one lowercase letter
  if (checkLowercase(password)) {
    score++;
  }

  // Check if the password contains at least one digit
  if (checkDigits(password)) {
    score++;
  }

  // Check if the password contains at least one special character
  if (checkSpecial(password)) {
    score++;
  }

  switch (score) {
    case 0:
    case 1:
    case 2:
      return WEAK;
    case 3:
    case 4:
      return FAIR;
    case 5:
      return GOOD;
    case 6:
      return STRONG;
  }

  return "Invalid password";
}

int main() {
  char password[MAX_LENGTH + 1];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  char *strength = checkStrength(password);

  // Print the strength of the password
  printf("Your password is %s\n", strength);

  return 0;
}