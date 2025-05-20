//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWERCASE 0x01
#define CHAR_CLASS_UPPERCASE 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2
#define PASSWORD_STRENGTH_VERY_STRONG 3

// Get the password from the user
char *get_password(void) {
  char *password = (char *)malloc(MAX_PASSWORD_LENGTH + 1);
  if (password == NULL) {
    printf("Error: Could not allocate memory for password.\n");
    return NULL;
  }

  printf("Enter your password: ");
  scanf("%s", password);

  return password;
}

// Check the password strength
int check_password_strength(char *password) {
  int strength = 0;

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    printf("Error: Password is too short.\n");
    return PASSWORD_STRENGTH_WEAK;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    printf("Error: Password is too long.\n");
    return PASSWORD_STRENGTH_WEAK;
  }

  // Check the password for each character class
  int char_classes = 0;
  for (int i = 0; i < strlen(password); i++) {
    char c = password[i];
    if (c >= 'a' && c <= 'z') {
      char_classes |= CHAR_CLASS_LOWERCASE;
    } else if (c >= 'A' && c <= 'Z') {
      char_classes |= CHAR_CLASS_UPPERCASE;
    } else if (c >= '0' && c <= '9') {
      char_classes |= CHAR_CLASS_DIGIT;
    } else {
      char_classes |= CHAR_CLASS_SYMBOL;
    }
  }

  // Check if the password contains at least three character classes
  if (char_classes >= (CHAR_CLASS_LOWERCASE | CHAR_CLASS_UPPERCASE | CHAR_CLASS_DIGIT)) {
    strength++;
  }

  // Check if the password contains at least one symbol
  if (char_classes & CHAR_CLASS_SYMBOL) {
    strength++;
  }

  // Return the password strength level
  return strength;
}

// Print the password strength level
void print_password_strength(int strength) {
  switch (strength) {
    case PASSWORD_STRENGTH_WEAK:
      printf("Your password is weak.\n");
      break;
    case PASSWORD_STRENGTH_MEDIUM:
      printf("Your password is medium.\n");
      break;
    case PASSWORD_STRENGTH_STRONG:
      printf("Your password is strong.\n");
      break;
    case PASSWORD_STRENGTH_VERY_STRONG:
      printf("Your password is very strong.\n");
      break;
  }
}

// Main function
int main(void) {
  // Get the password from the user
  char *password = get_password();
  if (password == NULL) {
    return 1;
  }

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength level
  print_password_strength(strength);

  // Free the memory allocated for the password
  free(password);

  return 0;
}