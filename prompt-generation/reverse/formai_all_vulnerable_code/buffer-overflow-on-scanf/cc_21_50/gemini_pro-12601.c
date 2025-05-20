//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

int main() {
  char password[MAX_LENGTH + 1];  // +1 for null-terminator
  int strength;

  printf("Enter your password: ");
  scanf("%s", password);

  // Check password length
  if (strlen(password) < MIN_LENGTH) {
    strength = 0;
    printf("Password is too short. Must be at least %d characters.\n", MIN_LENGTH);
  } else if (strlen(password) > MAX_LENGTH) {
    strength = 0;
    printf("Password is too long. Must be at most %d characters.\n", MAX_LENGTH);
  } else {
    // Check password strength
    strength = 1;  // Default strength

    // Check for uppercase characters
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= 'A' && password[i] <= 'Z') {
        has_uppercase = 1;
        break;
      }
    }
    if (!has_uppercase) {
      strength--;
      printf("Password must contain at least one uppercase character.\n");
    }

    // Check for lowercase characters
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= 'a' && password[i] <= 'z') {
        has_lowercase = 1;
        break;
      }
    }
    if (!has_lowercase) {
      strength--;
      printf("Password must contain at least one lowercase character.\n");
    }

    // Check for digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
      if (password[i] >= '0' && password[i] <= '9') {
        has_digit = 1;
        break;
      }
    }
    if (!has_digit) {
      strength--;
      printf("Password must contain at least one digit.\n");
    }

    // Check for special characters
    int has_special = 0;
    char special_chars[] = "!@#$%^&*()-+";
    for (int i = 0; i < strlen(password); i++) {
      for (int j = 0; j < strlen(special_chars); j++) {
        if (password[i] == special_chars[j]) {
          has_special = 1;
          break;
        }
      }
      if (has_special) {
        break;
      }
    }
    if (!has_special) {
      strength--;
      printf("Password must contain at least one special character.\n");
    }

    // Check for consecutive characters
    int has_consecutive = 0;
    for (int i = 1; i < strlen(password); i++) {
      if (password[i] == password[i - 1]) {
        has_consecutive = 1;
        break;
      }
    }
    if (has_consecutive) {
      strength--;
      printf("Password must not contain consecutive characters.\n");
    }
  }

  // Print password strength
  printf("Password strength: ");
  switch (strength) {
    case 0:
      printf("Weak\n");
      break;
    case 1:
      printf("Fair\n");
      break;
    case 2:
      printf("Good\n");
      break;
    case 3:
      printf("Strong\n");
      break;
    case 4:
      printf("Excellent\n");
      break;
    default:
      printf("Unknown\n");
      break;
  }

  return 0;
}