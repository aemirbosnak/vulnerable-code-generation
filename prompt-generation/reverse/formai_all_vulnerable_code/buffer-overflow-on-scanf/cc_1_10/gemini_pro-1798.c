//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 32

// Check if the password is long enough
int check_length(char *password) {
  int length = strlen(password);
  if (length < MIN_LENGTH) {
    return 0;
  } else if (length > MAX_LENGTH) {
    return 0;
  } else {
    return 1;
  }
}

// Check if the password contains any uppercase letters
int check_uppercase(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains any lowercase letters
int check_lowercase(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains any digits
int check_digits(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

// Check if the password contains any special characters
int check_special_characters(char *password) {
  int i;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
        password[i] == '$' || password[i] == '%' || password[i] == '^' ||
        password[i] == '&' || password[i] == '*' || password[i] == '(' ||
        password[i] == ')' || password[i] == '-' || password[i] == '_' ||
        password[i] == '+' || password[i] == '=' || password[i] == '`' ||
        password[i] == '~') {
      return 1;
    }
  }
  return 0;
}

// Calculate the password strength
int calculate_strength(char *password) {
  int strength = 0;

  if (check_length(password)) {
    strength++;
  }
  if (check_uppercase(password)) {
    strength++;
  }
  if (check_lowercase(password)) {
    strength++;
  }
  if (check_digits(password)) {
    strength++;
  }
  if (check_special_characters(password)) {
    strength++;
  }

  return strength;
}

// Print the password strength
void print_strength(int strength) {
  switch (strength) {
  case WEAK:
    printf("Your password is weak.\n");
    break;
  case FAIR:
    printf("Your password is fair.\n");
    break;
  case GOOD:
    printf("Your password is good.\n");
    break;
  case STRONG:
    printf("Your password is strong.\n");
    break;
  }
}

// Get the password from the user
char *get_password() {
  char *password = malloc(MAX_LENGTH + 1);
  if (password == NULL) {
    fprintf(stderr, "Error: could not allocate memory for password.\n");
    exit(1);
  }
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Main function
int main(void) {
  char *password;
  int strength;

  // Get the password from the user
  password = get_password();

  // Calculate the password strength
  strength = calculate_strength(password);

  // Print the password strength
  print_strength(strength);

  // Free the memory allocated for the password
  free(password);

  return 0;
}