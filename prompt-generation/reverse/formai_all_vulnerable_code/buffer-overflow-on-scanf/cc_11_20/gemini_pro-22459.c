//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables
  char password[100];
  int strength;

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the length of the password
  if (strlen(password) < 8) {
    strength = 0;
  } else if (strlen(password) < 12) {
    strength = 1;
  } else {
    strength = 2;
  }

  // Check for uppercase characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check for lowercase characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check for numbers
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check for special characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength++;
      break;
    }
  }

  // Print the password strength
  printf("Your password strength is: %d\n", strength);

  return 0;
}