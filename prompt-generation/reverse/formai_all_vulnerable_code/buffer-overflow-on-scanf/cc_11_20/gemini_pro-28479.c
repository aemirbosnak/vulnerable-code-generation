//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check the strength of a password
int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength += 2;
  } else if (strlen(password) >= 12) {
    strength += 3;
  }

  // Check for the presence of uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (has_uppercase) {
    strength += 1;
  }

  // Check for the presence of lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (has_lowercase) {
    strength += 1;
  }

  // Check for the presence of digits
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  if (has_digit) {
    strength += 1;
  }

  // Check for the presence of special characters
  int has_special = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      has_special = 1;
      break;
    }
  }
  if (has_special) {
    strength += 1;
  }

  return strength;
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the strength of the password
  switch (strength) {
    case 1:
      printf("Weak password\n");
      break;
    case 2:
      printf("Fair password\n");
      break;
    case 3:
      printf("Good password\n");
      break;
    case 4:
      printf("Strong password\n");
      break;
    case 5:
      printf("Excellent password\n");
      break;
    default:
      printf("Invalid password\n");
  }

  return 0;
}