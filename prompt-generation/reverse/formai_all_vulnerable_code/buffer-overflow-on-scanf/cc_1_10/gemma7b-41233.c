//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
  char password[256];
  int strength = 0;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check password length
  if (strlen(password) < 8) {
    strength++;
  }

  // Check for upper case letter
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      strength++;
    }
  }

  // Check for lower case letter
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      strength++;
    }
  }

  // Check for number
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      strength++;
    }
  }

  // Check for symbol
  for (int i = 0; i < strlen(password); i++) {
    if (ispunct(password[i])) {
      strength++;
    }
  }

  // Calculate strength percentage
  strength = strength * 100 / 10;

  // Print strength
  printf("Your password strength is: %d%%", strength);

  return 0;
}