//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define password strength levels
#define PASS_WEAK 0
#define PASS_MEDIUM 1
#define PASS_STRONG 2

// Define minimum password length
#define MIN_PASS_LEN 8

// Define maximum password length
#define MAX_PASS_LEN 64

// Define character classes
#define CHAR_CLASS_LOWER 1
#define CHAR_CLASS_UPPER 2
#define CHAR_CLASS_DIGIT 4
#define CHAR_CLASS_SYMBOL 8

// Define character classes mask
#define CHAR_CLASS_MASK (CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT | CHAR_CLASS_SYMBOL)

// Define score multipliers
#define SCORE_MULT_LOWER 1
#define SCORE_MULT_UPPER 2
#define SCORE_MULT_DIGIT 3
#define SCORE_MULT_SYMBOL 4

// Define score thresholds
#define SCORE_THRESH_WEAK 10
#define SCORE_THRESH_MEDIUM 20
#define SCORE_THRESH_STRONG 30

// Function to check if a character belongs to a character class
int has_char_class(char c, int char_class) {
  return (c >= 'a' && c <= 'z' && char_class == CHAR_CLASS_LOWER) ||
         (c >= 'A' && c <= 'Z' && char_class == CHAR_CLASS_UPPER) ||
         (c >= '0' && c <= '9' && char_class == CHAR_CLASS_DIGIT) ||
         (c >= '!' && c <= '~' && char_class == CHAR_CLASS_SYMBOL);
}

// Function to calculate the score of a password
int calculate_score(char *password) {
  int score = 0;
  int char_classes = 0;

  // Iterate over the password characters
  for (int i = 0; i < strlen(password); i++) {
    char c = password[i];

    // Check if the character belongs to any character class
    if (has_char_class(c, CHAR_CLASS_LOWER)) {
      char_classes |= CHAR_CLASS_LOWER;
      score += SCORE_MULT_LOWER;
    } else if (has_char_class(c, CHAR_CLASS_UPPER)) {
      char_classes |= CHAR_CLASS_UPPER;
      score += SCORE_MULT_UPPER;
    } else if (has_char_class(c, CHAR_CLASS_DIGIT)) {
      char_classes |= CHAR_CLASS_DIGIT;
      score += SCORE_MULT_DIGIT;
    } else if (has_char_class(c, CHAR_CLASS_SYMBOL)) {
      char_classes |= CHAR_CLASS_SYMBOL;
      score += SCORE_MULT_SYMBOL;
    }
  }

  // Apply bonus for using multiple character classes
  if (char_classes == CHAR_CLASS_MASK) {
    score += 5;
  }

  return score;
}

// Function to check the strength of a password
int check_strength(char *password) {
  // Calculate the score of the password
  int score = calculate_score(password);

  // Return the strength level based on the score
  if (score < SCORE_THRESH_WEAK) {
    return PASS_WEAK;
  } else if (score >= SCORE_THRESH_WEAK && score < SCORE_THRESH_MEDIUM) {
    return PASS_MEDIUM;
  } else {
    return PASS_STRONG;
  }
}

int main() {
  // Get the password from the user
  char password[MAX_PASS_LEN + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_strength(password);

  // Print the strength level
  switch (strength) {
    case PASS_WEAK:
      printf("Your password is weak.\n");
      break;
    case PASS_MEDIUM:
      printf("Your password is medium.\n");
      break;
    case PASS_STRONG:
      printf("Your password is strong.\n");
      break;
  }

  return 0;
}