//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

int main() {
  char password[MAX_LENGTH + 1];
  int strength;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check password length
  if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH) {
    printf("Password must be between %d and %d characters long.\n", MIN_LENGTH, MAX_LENGTH);
    return EXIT_FAILURE;
  }

  // Check password for uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
      break;
    }
  }

  // Check password for lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      has_lowercase = 1;
      break;
    }
  }

  // Check password for digits
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      has_digit = 1;
      break;
    }
  }

  // Check password for special characters
  int has_special = 0;
  char special_characters[] = "!@#$%^&*()_+=-`~";
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(special_characters); j++) {
      if (password[i] == special_characters[j]) {
        has_special = 1;
        break;
      }
    }
  }

  // Calculate password strength
  strength = 0;
  if (has_uppercase) strength++;
  if (has_lowercase) strength++;
  if (has_digit) strength++;
  if (has_special) strength++;

  // Print password strength
  switch (strength) {
    case STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case STRENGTH_MEDIUM:
      printf("Your password is medium.\n");
      break;
    case STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
    default:
      printf("Invalid password strength.\n");
      break;
  }

  return EXIT_SUCCESS;
}