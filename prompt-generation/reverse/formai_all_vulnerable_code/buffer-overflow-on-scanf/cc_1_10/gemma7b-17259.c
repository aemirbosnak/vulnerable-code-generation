//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 256

int main() {
  char password[MAX_PASSWORD_LENGTH];
  int password_length;
  int strength = 0;
  char *message = NULL;

  printf("Enter your password: ");
  scanf("%s", password);
  password_length = strlen(password);

  // Check for minimum password length
  if (password_length < 8) {
    message = "Password too short!";
  }

  // Check for uppercase letter
  if (!strchr(password, 'A')) {
    strength++;
    message = "Password needs an uppercase letter!";
  }

  // Check for lowercase letter
  if (!strchr(password, 'a')) {
    strength++;
    message = "Password needs a lowercase letter!";
  }

  // Check for number
  if (!strchr(password, '0') || !strchr(password, '9')) {
    strength++;
    message = "Password needs a number!";
  }

  // Check for special character
  if (!strchr(password, '!')) {
    strength++;
    message = "Password needs a special character!";
  }

  // Calculate strength percentage
  strength = (strength / 5) * 100;

  // Print strength
  printf("Password strength: %d%%", strength);

  // Print message if applicable
  if (message) {
    printf("\n%s", message);
  }

  return 0;
}