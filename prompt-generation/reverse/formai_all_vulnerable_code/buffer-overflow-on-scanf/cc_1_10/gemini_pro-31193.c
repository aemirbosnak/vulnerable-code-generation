//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Strength levels
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3
#define EXCELLENT 4

// Minimum password length
#define MIN_LEN 8

// Character types
#define UPPERCASE 0
#define LOWERCASE 1
#define DIGIT 2
#define SPECIAL 3

// Score for each character type
int char_scores[] = {2, 2, 1, 4};

// Check if a character is uppercase
int is_uppercase(char c) {
  return c >= 'A' && c <= 'Z';
}

// Check if a character is lowercase
int is_lowercase(char c) {
  return c >= 'a' && c <= 'z';
}

// Check if a character is a digit
int is_digit(char c) {
  return c >= '0' && c <= '9';
}

// Check if a character is a special character
int is_special(char c) {
  return !is_uppercase(c) && !is_lowercase(c) && !is_digit(c);
}

// Get the character type of a character
int get_char_type(char c) {
  if (is_uppercase(c)) {
    return UPPERCASE;
  } else if (is_lowercase(c)) {
    return LOWERCASE;
  } else if (is_digit(c)) {
    return DIGIT;
  } else {
    return SPECIAL;
  }
}

// Score a password
int score_password(char *password) {
  int score = 0;
  int len = strlen(password);

  // Check password length
  if (len < MIN_LEN) {
    return WEAK;
  }

  // Check for character types
  int char_types[4] = {0, 0, 0, 0};
  for (int i = 0; i < len; i++) {
    char c = password[i];
    int char_type = get_char_type(c);
    char_types[char_type]++;
  }

  // Calculate score
  for (int i = 0; i < 4; i++) {
    score += char_types[i] * char_scores[i];
  }

  // Return strength level
  if (score < 10) {
    return WEAK;
  } else if (score < 20) {
    return FAIR;
  } else if (score < 30) {
    return GOOD;
  } else if (score < 40) {
    return STRONG;
  } else {
    return EXCELLENT;
  }
}

int main() {
  // Get password from user
  char password[100];
  printf("Enter a password: ");
  scanf("%s", password);

  // Score password
  int strength = score_password(password);

  // Print strength level
  switch (strength) {
    case WEAK:
      printf("Your password is too weak. Please try again.\n");
      break;
    case FAIR:
      printf("Your password is fair. Please consider making it stronger.\n");
      break;
    case GOOD:
      printf("Your password is good. Keep it up!\n");
      break;
    case STRONG:
      printf("Your password is strong. Great job!\n");
      break;
    case EXCELLENT:
      printf("Your password is excellent. You're a password pro!\n");
      break;
  }

  return 0;
}