//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
typedef enum {
  WEAK,
  MEDIUM,
  STRONG,
  VERY_STRONG
} PasswordStrength;

// Define the password complexity requirements
typedef struct {
  int minLength;
  int minUppercase;
  int minLowercase;
  int minDigits;
  int minSpecialChars;
} PasswordComplexityRequirements;

// Check if the password meets the minimum length requirement
int checkPasswordLength(char *password, int minLength) {
  return strlen(password) >= minLength;
}

// Check if the password contains at least the minimum number of uppercase letters
int checkPasswordUppercase(char *password, int minUppercase) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      count++;
    }
  }
  return count >= minUppercase;
}

// Check if the password contains at least the minimum number of lowercase letters
int checkPasswordLowercase(char *password, int minLowercase) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      count++;
    }
  }
  return count >= minLowercase;
}

// Check if the password contains at least the minimum number of digits
int checkPasswordDigits(char *password, int minDigits) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      count++;
    }
  }
  return count >= minDigits;
}

// Check if the password contains at least the minimum number of special characters
int checkPasswordSpecialChars(char *password, int minSpecialChars) {
  int count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      count++;
    }
  }
  return count >= minSpecialChars;
}

// Calculate the password strength based on the complexity requirements
PasswordStrength calculatePasswordStrength(char *password, PasswordComplexityRequirements *requirements) {
  int score = 0;
  if (checkPasswordLength(password, requirements->minLength)) {
    score += 1;
  }
  if (checkPasswordUppercase(password, requirements->minUppercase)) {
    score += 1;
  }
  if (checkPasswordLowercase(password, requirements->minLowercase)) {
    score += 1;
  }
  if (checkPasswordDigits(password, requirements->minDigits)) {
    score += 1;
  }
  if (checkPasswordSpecialChars(password, requirements->minSpecialChars)) {
    score += 1;
  }

  switch (score) {
    case 0:
      return WEAK;
    case 1:
    case 2:
      return MEDIUM;
    case 3:
    case 4:
      return STRONG;
    case 5:
      return VERY_STRONG;
    default:
      return WEAK;
  }
}

// Print the password strength in a human-readable format
void printPasswordStrength(PasswordStrength strength) {
  switch (strength) {
    case WEAK:
      printf("Weak password\n");
      break;
    case MEDIUM:
      printf("Medium password\n");
      break;
    case STRONG:
      printf("Strong password\n");
      break;
    case VERY_STRONG:
      printf("Very strong password\n");
      break;
  }
}

int main() {
  // Define the password complexity requirements
  PasswordComplexityRequirements requirements = {
    .minLength = 8,
    .minUppercase = 1,
    .minLowercase = 1,
    .minDigits = 1,
    .minSpecialChars = 1
  };

  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength
  PasswordStrength strength = calculatePasswordStrength(password, &requirements);

  // Print the password strength
  printPasswordStrength(strength);

  return 0;
}