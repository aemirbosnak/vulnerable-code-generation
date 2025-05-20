//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the strength levels
#define WEAK 0
#define OK 1
#define GOOD 2
#define STRONG 3

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 32

// Define the character types
#define ALPHA_LOWER 0
#define ALPHA_UPPER 1
#define NUMERIC 2
#define SYMBOL 3

// Define the character type counts
#define ALPHA_LOWER_COUNT 26
#define ALPHA_UPPER_COUNT 26
#define NUMERIC_COUNT 10
#define SYMBOL_COUNT 32

// Define the character type arrays
char alpha_lower[] = "abcdefghijklmnopqrstuvwxyz";
char alpha_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numeric[] = "0123456789";
char symbol[] = "!@#$%^&*()_+=-`~";

// Define the password strength criteria
int criteria[4] = {0, 0, 0, 0};

// Get the password from the user
char *get_password() {
  char *password = malloc(MAX_LENGTH + 1);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Check the password strength
int check_password_strength(char *password) {
  int length = strlen(password);

  // Check the password length
  if (length < MIN_LENGTH) {
    printf("Password is too short. Must be at least %d characters.\n", MIN_LENGTH);
    return WEAK;
  } else if (length > MAX_LENGTH) {
    printf("Password is too long. Must be at most %d characters.\n", MAX_LENGTH);
    return WEAK;
  }

  // Check the password for each character type
  for (int i = 0; i < length; i++) {
    char c = password[i];

    // Check for alphabetic characters
    if (strchr(alpha_lower, c) != NULL) {
      criteria[ALPHA_LOWER] = 1;
    } else if (strchr(alpha_upper, c) != NULL) {
      criteria[ALPHA_UPPER] = 1;
    }

    // Check for numeric characters
    if (strchr(numeric, c) != NULL) {
      criteria[NUMERIC] = 1;
    }

    // Check for symbols
    if (strchr(symbol, c) != NULL) {
      criteria[SYMBOL] = 1;
    }
  }

  // Check if the password meets the strength criteria
  int strength = WEAK;
  if (criteria[ALPHA_LOWER] && criteria[ALPHA_UPPER] && criteria[NUMERIC] && criteria[SYMBOL]) {
    strength = STRONG;
  } else if (criteria[ALPHA_LOWER] && criteria[ALPHA_UPPER] && criteria[NUMERIC]) {
    strength = GOOD;
  } else if (criteria[ALPHA_LOWER] && criteria[ALPHA_UPPER]) {
    strength = OK;
  }

  return strength;
}

// Print the password strength
void print_password_strength(int strength) {
  switch (strength) {
    case WEAK:
      printf("Password is weak.\n");
      break;
    case OK:
      printf("Password is OK.\n");
      break;
    case GOOD:
      printf("Password is good.\n");
      break;
    case STRONG:
      printf("Password is strong.\n");
      break;
  }
}

// Main function
int main() {
  char *password = get_password();
  int strength = check_password_strength(password);
  print_password_strength(strength);

  free(password);
  return 0;
}