//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;

  // Check if the password is at least 8 characters long
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

  return strength;
}

// Main function
int main() {
  char password[100];

  printf("Enter a password: ");
  scanf("%s", password);

  int strength = check_password_strength(password);

  if (strength == 0) {
    printf("The password is weak.\n");
  } else if (strength == 1) {
    printf("The password is fairly weak.\n");
  } else if (strength == 2) {
    printf("The password is moderate.\n");
  } else if (strength == 3) {
    printf("The password is strong.\n");
  } else if (strength == 4) {
    printf("The password is very strong.\n");
  } else {
    printf("The password is extremely strong.\n");
  }

  return 0;
}