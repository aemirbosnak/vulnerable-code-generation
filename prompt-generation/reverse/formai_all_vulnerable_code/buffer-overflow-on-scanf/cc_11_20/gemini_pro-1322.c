//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Define the minimum and maximum password lengths
#define MIN_PASS_LEN 8
#define MAX_PASS_LEN 64

// Define the password complexity requirements
#define REQUIRE_UPPERCASE 1
#define REQUIRE_LOWERCASE 1
#define REQUIRE_DIGIT 1
#define REQUIRE_SPECIAL_CHAR 1

// Define the error messages
#define ERR_TOO_SHORT "Password is too short."
#define ERR_TOO_LONG "Password is too long."
#define ERR_NO_UPPERCASE "Password must contain at least one uppercase letter."
#define ERR_NO_LOWERCASE "Password must contain at least one lowercase letter."
#define ERR_NO_DIGIT "Password must contain at least one digit."
#define ERR_NO_SPECIAL_CHAR "Password must contain at least one special character."

// Function to check the password strength
int check_password_strength(char *password) {
  // Check the password length
  if (strlen(password) < MIN_PASS_LEN) {
    return ERR_TOO_SHORT;
  } else if (strlen(password) > MAX_PASS_LEN) {
    return ERR_TOO_LONG;
  }

  // Check if the password contains at least one uppercase letter
  int has_uppercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  if (!has_uppercase && REQUIRE_UPPERCASE) {
    return ERR_NO_UPPERCASE;
  }

  // Check if the password contains at least one lowercase letter
  int has_lowercase = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  if (!has_lowercase && REQUIRE_LOWERCASE) {
    return ERR_NO_LOWERCASE;
  }

  // Check if the password contains at least one digit
  int has_digit = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      has_digit = 1;
      break;
    }
  }
  if (!has_digit && REQUIRE_DIGIT) {
    return ERR_NO_DIGIT;
  }

  // Check if the password contains at least one special character
  int has_special_char = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] < 'a' || password[i] > 'z') {
      has_special_char = 1;
      break;
    }
  }
  if (!has_special_char && REQUIRE_SPECIAL_CHAR) {
    return ERR_NO_SPECIAL_CHAR;
  }

  // The password is strong
  return 0;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_PASS_LEN + 1];
  printf("Enter a password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the result
  if (strength == 0) {
    printf("The password is strong.\n");
  } else {
    printf("The password is weak: %s\n", strength);
  }

  return 0;
}