//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
  char password[100];
  int strength = 0;
  int i;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check the length of the password
  if (strlen(password) >= 8) {
    strength++;
  }

  // Check for uppercase letters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check for lowercase letters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check for digits
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check for special characters
  for (i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength++;
      break;
    }
  }

  // Check for repeated characters
  for (i = 0; i < strlen(password) - 1; i++) {
    if (password[i] == password[i + 1]) {
      strength--;
    }
  }

  // Display the strength of the password
  printf("Strength: %d\n", strength);

  return 0;
}