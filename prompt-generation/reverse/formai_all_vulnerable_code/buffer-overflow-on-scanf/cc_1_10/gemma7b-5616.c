//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define MAX_ retries 3

typedef struct PassStrength {
  int strength;
  char message[256];
} PassStrength;

PassStrength check_password_strength(char *password) {
  PassStrength strength = {0, ""};

  // Minimum length of 8 characters
  if (strlen(password) < 8) {
    strength.strength = 1;
    strcpy(strength.message, "Password is too short.");
  } else if (strlen(password) >= 8 && strlen(password) < 12) {
    strength.strength = 2;
    strcpy(strength.message, "Password is moderate.");
  } else if (strlen(password) >= 12) {
    strength.strength = 3;
    strcpy(strength.message, "Password is strong.");
  }

  // Presence of uppercase letter
  if (!strchr(password, 'A')) {
    strength.strength--;
    strcat(strength.message, "Missing uppercase letter.");
  }

  // Presence of lowercase letter
  if (!strchr(password, 'a')) {
    strength.strength--;
    strcat(strength.message, "Missing lowercase letter.");
  }

  // Presence of number
  if (!strchr(password, '0') || !strchr(password, '9')) {
    strength.strength--;
    strcat(strength.message, "Missing number.");
  }

  // Presence of special character
  if (!strchr(password, '!')) {
    strength.strength--;
    strcat(strength.message, "Missing special character.");
  }

  return strength;
}

int main() {
  char password[256];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  PassStrength strength = check_password_strength(password);

  // Display the password strength
  printf("Password strength: %d\n", strength.strength);
  printf("Message: %s\n", strength.message);

  return 0;
}