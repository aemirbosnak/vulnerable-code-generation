//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 16

// Define the password strength levels
enum PasswordStrength {
  WEAK,
  MEDIUM,
  STRONG
};

// Define the password strength requirements
struct PasswordStrengthRequirements {
  int min_length;
  int max_length;
  int min_uppercase_letters;
  int min_lowercase_letters;
  int min_digits;
  int min_special_characters;
};

// Define the default password strength requirements
const struct PasswordStrengthRequirements DEFAULT_PASSWORD_STRENGTH_REQUIREMENTS = {
  .min_length = MIN_PASSWORD_LENGTH,
  .max_length = MAX_PASSWORD_LENGTH,
  .min_uppercase_letters = 1,
  .min_lowercase_letters = 1,
  .min_digits = 1,
  .min_special_characters = 1
};

// Check if the password meets the minimum length requirement
int password_meets_min_length_requirement(const char *password, int min_length) {
  return strlen(password) >= min_length;
}

// Check if the password meets the maximum length requirement
int password_meets_max_length_requirement(const char *password, int max_length) {
  return strlen(password) <= max_length;
}

// Check if the password contains at least one uppercase letter
int password_contains_uppercase_letter(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one lowercase letter
int password_contains_lowercase_letter(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one digit
int password_contains_digit(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains at least one special character
int password_contains_special_character(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Check the password strength
enum PasswordStrength check_password_strength(const char *password, const struct PasswordStrengthRequirements *requirements) {
  int score = 0;

  // Check if the password meets the minimum length requirement
  if (password_meets_min_length_requirement(password, requirements->min_length)) {
    score++;
  }

  // Check if the password meets the maximum length requirement
  if (password_meets_max_length_requirement(password, requirements->max_length)) {
    score++;
  }

  // Check if the password contains at least one uppercase letter
  if (password_contains_uppercase_letter(password)) {
    score++;
  }

  // Check if the password contains at least one lowercase letter
  if (password_contains_lowercase_letter(password)) {
    score++;
  }

  // Check if the password contains at least one digit
  if (password_contains_digit(password)) {
    score++;
  }

  // Check if the password contains at least one special character
  if (password_contains_special_character(password)) {
    score++;
  }

  // Return the password strength
  if (score <= 2) {
    return WEAK;
  } else if (score <= 4) {
    return MEDIUM;
  } else {
    return STRONG;
  }
}

// Get the password strength requirements
void get_password_strength_requirements(struct PasswordStrengthRequirements *requirements) {
  // Get the minimum password length
  printf("Enter the minimum password length: ");
  scanf("%d", &requirements->min_length);

  // Get the maximum password length
  printf("Enter the maximum password length: ");
  scanf("%d", &requirements->max_length);

  // Get the minimum number of uppercase letters
  printf("Enter the minimum number of uppercase letters: ");
  scanf("%d", &requirements->min_uppercase_letters);

  // Get the minimum number of lowercase letters
  printf("Enter the minimum number of lowercase letters: ");
  scanf("%d", &requirements->min_lowercase_letters);

  // Get the minimum number of digits
  printf("Enter the minimum number of digits: ");
  scanf("%d", &requirements->min_digits);

  // Get the minimum number of special characters
  printf("Enter the minimum number of special characters: ");
  scanf("%d", &requirements->min_special_characters);
}

// Main function
int main() {
  // Get the password strength requirements
  struct PasswordStrengthRequirements requirements;
  get_password_strength_requirements(&requirements);

  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter the password: ");
  scanf("%s", password);

  // Check the password strength
  enum PasswordStrength strength = check_password_strength(password, &requirements);

  // Print the password strength
  switch (strength) {
    case WEAK:
      printf("The password is weak.\n");
      break;
    case MEDIUM:
      printf("The password is medium.\n");
      break;
    case STRONG:
      printf("The password is strong.\n");
      break;
  }

  return 0;
}