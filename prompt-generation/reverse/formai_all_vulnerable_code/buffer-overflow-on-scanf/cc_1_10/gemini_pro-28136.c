//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declare the function to check the password strength
int check_password_strength(char *password);

// Declare the main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a buffer to store the password
  char password[100];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
  printf("Your password strength is: %d\n", strength);

  return 0;
}

// Define the function to check the password strength
int check_password_strength(char *password) {
  // Check the length of the password
  int length = strlen(password);
  if (length < 8) {
    return 0;
  }

  // Check for uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }

  // Check for lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }

  // Check for digits
  int has_digits = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digits = 1;
      break;
    }
  }

  // Check for special characters
  int has_special = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] < ' ' || password[i] > '~') {
      has_special = 1;
      break;
    }
  }

  // Calculate the password strength
  int strength = 0;
  if (has_uppercase) {
    strength++;
  }
  if (has_lowercase) {
    strength++;
  }
  if (has_digits) {
    strength++;
  }
  if (has_special) {
    strength++;
  }
  if (length >= 12) {
    strength++;
  }

  return strength;
}