//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong enough
int check_password_strength(char *password) {
  int strength = 0;

  // Check if the password is at least 8 characters long
  if (strlen(password) < 8) {
    strength += 0;
  } else {
    strength += 1;
  }

  // Check if the password contains at least one uppercase letter
  if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL) {
    strength += 1;
  }

  // Check if the password contains at least one lowercase letter
  if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL) {
    strength += 1;
  }

  // Check if the password contains at least one number
  if (strpbrk(password, "0123456789") != NULL) {
    strength += 1;
  }

  // Check if the password contains at least one special character
  if (strpbrk(password, "!@#$%^&*()") != NULL) {
    strength += 1;
  }

  // Return the strength of the password
  return strength;
}

// Main function
int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the strength of the password
  printf("The strength of your password is: %d\n", strength);

  // Return 0 to indicate that the program ran successfully
  return 0;
}