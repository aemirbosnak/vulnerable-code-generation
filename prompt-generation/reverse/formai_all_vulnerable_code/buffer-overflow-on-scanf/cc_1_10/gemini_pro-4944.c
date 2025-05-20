//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the password strength levels
enum PasswordStrength {
  WEAK,
  MEDIUM,
  STRONG
};

// Check if the password is long enough
int is_password_long_enough(const char *password) {
  return strlen(password) >= MIN_PASSWORD_LENGTH;
}

// Check if the password contains a digit
int does_password_contain_a_digit(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      return 1;
    }
  }

  return 0;
}

// Check if the password contains a lowercase letter
int does_password_contain_a_lowercase_letter(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      return 1;
    }
  }

  return 0;
}

// Check if the password contains an uppercase letter
int does_password_contain_an_uppercase_letter(const char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      return 1;
    }
  }

  return 0;
}

// Check if the password contains a special character
int does_password_contain_a_special_character(const char *password) {
  const char *special_characters = "!@#$%^&*()_+=-`~";

  for (int i = 0; i < strlen(special_characters); i++) {
    if (strchr(password, special_characters[i])) {
      return 1;
    }
  }

  return 0;
}

// Calculate the password strength
enum PasswordStrength calculate_password_strength(const char *password) {
  int score = 0;

  if (is_password_long_enough(password)) {
    score++;
  }

  if (does_password_contain_a_digit(password)) {
    score++;
  }

  if (does_password_contain_a_lowercase_letter(password)) {
    score++;
  }

  if (does_password_contain_an_uppercase_letter(password)) {
    score++;
  }

  if (does_password_contain_a_special_character(password)) {
    score++;
  }

  switch (score) {
    case 0:
    case 1:
    case 2:
      return WEAK;

    case 3:
    case 4:
      return MEDIUM;

    case 5:
      return STRONG;

    default:
      return WEAK;
  }
}

// Print the password strength
void print_password_strength(enum PasswordStrength strength) {
  switch (strength) {
    case WEAK:
      printf("Your password is weak.\n");
      break;

    case MEDIUM:
      printf("Your password is medium.\n");
      break;

    case STRONG:
      printf("Your password is strong.\n");
      break;

    default:
      printf("Invalid password strength.\n");
      break;
  }
}

int main() {
  char password[MAX_PASSWORD_LENGTH + 1];

  printf("Enter your password: ");
  scanf("%s", password);

  enum PasswordStrength strength = calculate_password_strength(password);
  print_password_strength(strength);

  return 0;
}