//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWD_LEN 255

int main() {
  char password[MAX_PASSWD_LEN];
  int password_length = 0;
  int strength = 0;
  char special_chars[10] = "!@#$%^&*()_+-={}[]|";
  char numbers[10] = "0123456789";

  printf("Enter password: ");
  scanf("%s", password);
  password_length = strlen(password);

  // Check for minimum password length
  if (password_length < 8) {
    printf("Error: Password must be at least 8 characters long.\n");
    return 1;
  }

  // Check for presence of uppercase letter
  for (int i = 0; i < password_length; i++) {
    if (isupper(password[i])) {
      strength++;
    }
  }

  // Check for presence of lowercase letter
  for (int i = 0; i < password_length; i++) {
    if (islower(password[i])) {
      strength++;
    }
  }

  // Check for presence of number
  for (int i = 0; i < password_length; i++) {
    if (isdigit(password[i])) {
      strength++;
    }
  }

  // Check for presence of special character
  for (int i = 0; i < password_length; i++) {
    if (strchr(special_chars, password[i]) != NULL) {
      strength++;
    }
  }

  // Calculate password strength
  strength = strength / 4;

  // Print password strength
  switch (strength) {
    case 4:
      printf("Password strength: Very strong\n");
      break;
    case 3:
      printf("Password strength: Strong\n");
      break;
    case 2:
      printf("Password strength: Moderate\n");
      break;
    case 1:
      printf("Password strength: Weak\n");
      break;
    default:
      printf("Password strength: Very weak\n");
      break;
  }

  return 0;
}