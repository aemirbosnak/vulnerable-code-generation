//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
  char password[100];
  int strength = 0;
  int i;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check the length of the password
  if (strlen(password) < 8) {
    strength += 1;
  }

  // Check for uppercase letters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength += 1;
      break;
    }
  }

  // Check for lowercase letters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength += 1;
      break;
    }
  }

  // Check for digits
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength += 1;
      break;
    }
  }

  // Check for special characters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength += 1;
      break;
    }
  }

  // Check for repeating characters
  for (i = 0; i < strlen(password) - 1; i++) {
    if (password[i] == password[i + 1]) {
      strength -= 1;
      break;
    }
  }

  // Print the password strength
  if (strength <= 2) {
    printf("Your password is weak.\n");
  } else if (strength == 3) {
    printf("Your password is fair.\n");
  } else if (strength == 4) {
    printf("Your password is good.\n");
  } else {
    printf("Your password is excellent.\n");
  }

  return 0;
}