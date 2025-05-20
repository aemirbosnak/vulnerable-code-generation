//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWD_LENGTH 255

int main() {
  char password[MAX_PASSWD_LENGTH];
  int password_length;
  int strength = 0;
  int i;

  printf("Enter a password: ");
  scanf("%s", password);
  password_length = strlen(password);

  // Check password length
  if (password_length < 8) {
    strength -= 1;
  }

  // Check for uppercase letter
  for (i = 0; i < password_length; i++) {
    if (isupper(password[i])) {
      strength++;
    }
  }

  // Check for lowercase letter
  for (i = 0; i < password_length; i++) {
    if (islower(password[i])) {
      strength++;
    }
  }

  // Check for number
  for (i = 0; i < password_length; i++) {
    if (isdigit(password[i])) {
      strength++;
    }
  }

  // Check for special character
  for (i = 0; i < password_length; i++) {
    if (!isalnum(password[i])) {
      strength++;
    }
  }

  // Calculate password strength
  strength = strength / 4;

  // Print password strength
  switch (strength) {
    case 4:
      printf("Password strength: Excellent\n");
      break;
    case 3:
      printf("Password strength: Good\n");
      break;
    case 2:
      printf("Password strength: Weak\n");
      break;
    case 1:
      printf("Password strength: Very Weak\n");
      break;
    default:
      printf("Password strength: Invalid\n");
      break;
  }

  return 0;
}