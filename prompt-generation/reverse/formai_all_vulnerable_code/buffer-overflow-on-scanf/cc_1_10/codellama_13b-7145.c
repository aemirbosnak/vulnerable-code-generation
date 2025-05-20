//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
// C Password Strength Checker
#include <stdio.h>
#include <string.h>

// Function to check password strength
int check_password_strength(char *password) {
  // Check for password length
  if (strlen(password) < 8) {
    return 0;
  }

  // Check for uppercase letters
  int uppercase_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      uppercase_count++;
    }
  }
  if (uppercase_count < 2) {
    return 0;
  }

  // Check for numbers
  int number_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      number_count++;
    }
  }
  if (number_count < 2) {
    return 0;
  }

  // Check for special characters
  int special_count = 0;
  for (int i = 0; i < strlen(password); i++) {
    if (ispunct(password[i])) {
      special_count++;
    }
  }
  if (special_count < 2) {
    return 0;
  }

  // Check for repeating characters
  int last_char = password[0];
  int repeated_chars = 0;
  for (int i = 1; i < strlen(password); i++) {
    if (password[i] == last_char) {
      repeated_chars++;
    }
    last_char = password[i];
  }
  if (repeated_chars > 2) {
    return 0;
  }

  return 1;
}

int main() {
  char password[100];

  // Ask for password
  printf("Enter a password: ");
  scanf("%s", password);

  // Check password strength
  if (check_password_strength(password)) {
    printf("Password strength: Strong\n");
  } else {
    printf("Password strength: Weak\n");
  }

  return 0;
}