//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong enough
int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) >= 8) {
    strength++;
  }

  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check if the password contains at least one digit
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check if the password contains at least one special character
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength++;
      break;
    }
  }

  // Return the strength of the password
  return strength;
}

int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the strength of the password
  switch (strength) {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
    default:
      printf("Invalid password.\n");
  }

  return 0;
}