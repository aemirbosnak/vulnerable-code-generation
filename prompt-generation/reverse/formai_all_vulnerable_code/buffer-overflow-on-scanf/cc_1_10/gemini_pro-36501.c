//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the password.
#define MAX_PASSWORD_LENGTH 128

// Define the minimum length of the password.
#define MIN_PASSWORD_LENGTH 8

// Define the minimum number of uppercase characters in the password.
#define MIN_UPPERCASE_CHARACTERS 1

// Define the minimum number of lowercase characters in the password.
#define MIN_LOWERCASE_CHARACTERS 1

// Define the minimum number of digits in the password.
#define MIN_DIGITS 1

// Define the minimum number of special characters in the password.
#define MIN_SPECIAL_CHARACTERS 1

// Define the array of special characters.
char special_characters[] = "!@#$%^&*()_+=-`~";

// Function to check if the password is strong enough.
int is_strong_password(char *password) {
  // Check if the password is long enough.
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return 0;
  }

  // Check if the password contains enough uppercase characters.
  int uppercase_characters = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      uppercase_characters++;
    }
  }
  if (uppercase_characters < MIN_UPPERCASE_CHARACTERS) {
    return 0;
  }

  // Check if the password contains enough lowercase characters.
  int lowercase_characters = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lowercase_characters++;
    }
  }
  if (lowercase_characters < MIN_LOWERCASE_CHARACTERS) {
    return 0;
  }

  // Check if the password contains enough digits.
  int digits = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      digits++;
    }
  }
  if (digits < MIN_DIGITS) {
    return 0;
  }

  // Check if the password contains enough special characters.
  int special_characters_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(special_characters); j++) {
      if (password[i] == special_characters[j]) {
        special_characters_count++;
      }
    }
  }
  if (special_characters_count < MIN_SPECIAL_CHARACTERS) {
    return 0;
  }

  // The password is strong enough.
  return 1;
}

// Function to generate a random password.
char *generate_random_password() {
  // Create an array to store the password.
  char *password = malloc(MAX_PASSWORD_LENGTH);

  // Generate a random password.
  for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
    password[i] = rand() % 128;
  }

  // Return the password.
  return password;
}

// Main function.
int main() {
  // Get the password from the user.
  char password[MAX_PASSWORD_LENGTH];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check if the password is strong enough.
  int is_strong = is_strong_password(password);

  // Print the result.
  if (is_strong) {
    printf("Your password is strong enough.\n");
  } else {
    printf("Your password is not strong enough.\n");
  }

  // Generate a random password.
  char *random_password = generate_random_password();

  // Print the random password.
  printf("Here is a random password: %s\n", random_password);

  // Free the memory allocated for the random password.
  free(random_password);

  return 0;
}