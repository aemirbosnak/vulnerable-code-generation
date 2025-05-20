//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char password[101];
  int strength;

  // Prompt the user to enter a password
  printf("Enter thy password, brave knight: ");
  scanf("%s", password);

  // Calculate the strength of the password
  strength = calculateStrength(password);

  // Print the strength of the password
  printf("Thy password strength is %d\n", strength);

  return 0;
}

// Calculate the strength of a password
int calculateStrength(char *password) {
  int strength = 0;
  int length = strlen(password);

  // Check the length of the password
  if (length >= 8) {
    strength++;
  }

  // Check for uppercase characters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check for lowercase characters
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check for digits
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check for special characters
  for (int i = 0; i < length; i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength++;
      break;
    }
  }

  return strength;
}