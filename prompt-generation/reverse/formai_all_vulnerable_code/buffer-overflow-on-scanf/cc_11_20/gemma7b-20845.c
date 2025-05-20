//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char password[20];
  int strength = 0;
  printf("Enter a password: ");
  scanf("%s", password);

  // Check for uppercase letters
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
    }
  }

  // Check for lowercase letters
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
    }
  }

  // Check for numbers
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
    }
  }

  // Check for symbols
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      strength++;
    }
  }

  // Calculate password strength
  switch (strength) {
    case 0:
      printf("Password strength: Weak\n");
      break;
    case 1:
      printf("Password strength: Moderate\n");
      break;
    case 2:
      printf("Password strength: Good\n");
      break;
    case 3:
      printf("Password strength: Strong\n");
      break;
    default:
      printf("Password strength: Invalid\n");
      break;
  }

  return 0;
}