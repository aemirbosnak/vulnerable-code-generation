//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the strength levels
enum Strength {
  WEAK,
  MEDIUM,
  STRONG,
  VERY_STRONG
};

// Declare the character types
enum CharType {
  LOWER,
  UPPER,
  DIGIT,
  SPECIAL
};

// Get the character type
enum CharType get_char_type(char c) {
  if (c >= 'a' && c <= 'z') {
    return LOWER;
  } else if (c >= 'A' && c <= 'Z') {
    return UPPER;
  } else if (c >= '0' && c <= '9') {
    return DIGIT;
  } else {
    return SPECIAL;
  }
}

// Calculate the password strength
enum Strength calculate_strength(char *password) {
  int len = strlen(password);
  int score = 0;

  // Check the length
  if (len < 8) {
    score += 1;
  } else if (len >= 8 && len < 12) {
    score += 2;
  } else if (len >= 12 && len < 16) {
    score += 3;
  } else {
    score += 4;
  }

  // Check the character types
  int char_types = 0;
  for (int i = 0; i < len; i++) {
    enum CharType char_type = get_char_type(password[i]);
    if (char_type == LOWER) {
      char_types |= 1;
    } else if (char_type == UPPER) {
      char_types |= 2;
    } else if (char_type == DIGIT) {
      char_types |= 4;
    } else {
      char_types |= 8;
    }
  }

  // Add score for each character type
  if (char_types == 1) {
    score += 1;
  } else if (char_types == 3) {
    score += 2;
  } else if (char_types == 7) {
    score += 3;
  } else if (char_types == 15) {
    score += 4;
  }

  // Calculate the strength level
  if (score < 2) {
    return WEAK;
  } else if (score == 2 || score == 3) {
    return MEDIUM;
  } else if (score == 4 || score == 5) {
    return STRONG;
  } else {
    return VERY_STRONG;
  }
}

// Print the password strength
void print_strength(enum Strength strength) {
  switch (strength) {
    case WEAK:
      printf("Your password is weak. Please choose a stronger password.\n");
      break;
    case MEDIUM:
      printf("Your password is medium strength. It could be stronger.\n");
      break;
    case STRONG:
      printf("Your password is strong. Good job!\n");
      break;
    case VERY_STRONG:
      printf("Your password is very strong. Congratulations!\n");
      break;
  }
}

// Get the password from the user
char *get_password() {
  char *password = malloc(100);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Main function
int main() {
  char *password = get_password();
  enum Strength strength = calculate_strength(password);
  print_strength(strength);
  free(password);
  return 0;
}