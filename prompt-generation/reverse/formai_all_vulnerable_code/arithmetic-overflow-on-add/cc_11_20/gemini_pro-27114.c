//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the strength of a password
int calculateStrength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength += 2;
  } else if (strlen(password) >= 12) {
    strength += 3;
  }

  // Check for uppercase letters
  int hasUppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
      break;
    }
  }
  if (hasUppercase) {
    strength += 1;
  }

  // Check for lowercase letters
  int hasLowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
      break;
    }
  }
  if (hasLowercase) {
    strength += 1;
  }

  // Check for numbers
  int hasNumber = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasNumber = 1;
      break;
    }
  }
  if (hasNumber) {
    strength += 1;
  }

  // Check for special characters
  int hasSpecialCharacter = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
      hasSpecialCharacter = 1;
      break;
    }
  }
  if (hasSpecialCharacter) {
    strength += 1;
  }

  return strength;
}

// Function to generate a random password
char *generatePassword(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    password[i] = rand() % 94 + 33;
  }
  password[length] = '\0';
  return password;
}

int main() {
  // Get the desired password length from the user
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generatePassword(length);

  // Calculate the strength of the password
  int strength = calculateStrength(password);

  // Print the password and its strength
  printf("Password: %s\n", password);
  switch (strength) {
    case 1:
      printf("Password strength: Weak\n");
      break;
    case 2:
      printf("Password strength: Fair\n");
      break;
    case 3:
      printf("Password strength: Good\n");
      break;
    case 4:
      printf("Password strength: Strong\n");
      break;
    case 5:
      printf("Password strength: Excellent\n");
      break;
  }

  free(password);
  return 0;
}