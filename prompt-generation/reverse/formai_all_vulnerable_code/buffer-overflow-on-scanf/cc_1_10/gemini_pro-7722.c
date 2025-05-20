//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

typedef struct {
  bool has_lowercase;
  bool has_uppercase;
  bool has_digit;
  bool has_special_character;
} PasswordStrength;

bool is_valid_length(const char* password) {
  return strlen(password) >= MIN_LENGTH && strlen(password) <= MAX_LENGTH;
}

bool has_lowercase(const char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      return true;
    }
  }
  return false;
}

bool has_uppercase(const char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return true;
    }
  }
  return false;
}

bool has_digit(const char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return true;
    }
  }
  return false;
}

bool has_special_character(const char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if ((password[i] < 'a' || password[i] > 'z') && (password[i] < 'A' || password[i] > 'Z') && (password[i] < '0' || password[i] > '9')) {
      return true;
    }
  }
  return false;
}

PasswordStrength get_password_strength(const char* password) {
  PasswordStrength strength = {
    .has_lowercase = has_lowercase(password),
    .has_uppercase = has_uppercase(password),
    .has_digit = has_digit(password),
    .has_special_character = has_special_character(password)
  };
  return strength;
}

void print_password_strength(const char* password) {
  PasswordStrength strength = get_password_strength(password);

  if (!is_valid_length(password)) {
    printf("Password must be between %d and %d characters long.\n", MIN_LENGTH, MAX_LENGTH);
    return;
  }

  if (!strength.has_lowercase) {
    printf("Password must contain at least one lowercase letter.\n");
  }

  if (!strength.has_uppercase) {
    printf("Password must contain at least one uppercase letter.\n");
  }

  if (!strength.has_digit) {
    printf("Password must contain at least one digit.\n");
  }

  if (!strength.has_special_character) {
    printf("Password must contain at least one special character.\n");
  }

  if (strength.has_lowercase && strength.has_uppercase && strength.has_digit && strength.has_special_character) {
    printf("Password is strong!\n");
  } else {
    printf("Password is weak! Please try again.\n");
  }
}

int main() {
  char password[MAX_LENGTH];
  printf("Enter a password: ");
  scanf("%s", password);

  print_password_strength(password);

  return 0;
}