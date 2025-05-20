//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
  char password[101];
  int strength = 0;
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the length of the password
  if (strlen(password) < 8) {
    printf("Password is too short. ");
  } else {
    strength++;
  }

  // Check for uppercase characters
  int hasUpper = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUpper = 1;
      break;
    }
  }
  if (hasUpper) {
    strength++;
  }

  // Check for lowercase characters
  int hasLower = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      hasLower = 1;
      break;
    }
  }
  if (hasLower) {
    strength++;
  }

  // Check for digits
  int hasDigit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
      break;
    }
  }
  if (hasDigit) {
    strength++;
  }

  // Check for special characters
  int hasSpecial = 0;
  char specialChars[] = "!@#$%^&*()-=_+[]{}\\|;:'\",<.>/?";
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(specialChars); j++) {
      if (password[i] == specialChars[j]) {
        hasSpecial = 1;
        break;
      }
    }
  }
  if (hasSpecial) {
    strength++;
  }

  // Print the password strength
  switch (strength) {
  case 1:
    printf("Password is very weak. ");
    break;
  case 2:
    printf("Password is weak. ");
    break;
  case 3:
    printf("Password is moderate. ");
    break;
  case 4:
    printf("Password is strong. ");
    break;
  case 5:
    printf("Password is very strong. ");
    break;
  }
  printf("\n");

  return 0;
}