//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SYMBOL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password score calculation function
int calculate_password_score(char *password) {
  int score = 0;

  // Check the password length
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    score -= 10;
  } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
    score -= 5;
  }

  // Check the password character classes
  int char_classes[4] = {0, 0, 0, 0};
  for (int i = 0; i < strlen(password); i++) {
    char c = password[i];
    if (islower(c)) {
      char_classes[CHAR_CLASS_LOWER] = 1;
    } else if (isupper(c)) {
      char_classes[CHAR_CLASS_UPPER] = 1;
    } else if (isdigit(c)) {
      char_classes[CHAR_CLASS_DIGIT] = 1;
    } else {
      char_classes[CHAR_CLASS_SYMBOL] = 1;
    }
  }
  int num_char_classes = 0;
  for (int i = 0; i < 4; i++) {
    num_char_classes += char_classes[i];
  }
  score += num_char_classes * 5;

  // Check the password for consecutive characters
  int consecutive_chars = 0;
  for (int i = 0; i < strlen(password) - 1; i++) {
    char c1 = password[i];
    char c2 = password[i + 1];
    if (c1 == c2) {
      consecutive_chars++;
    }
  }
  if (consecutive_chars > 2) {
    score -= consecutive_chars;
  }

  // Check the password for common words
  const char *common_words[] = {
    "password", "123456", "qwerty", "abc123", "iloveyou", "princess", "football", "baseball", "basketball", "hockey",
    "computer", "internet", "facebook", "google", "amazon", "yahoo", "microsoft", "apple", "samsung", "sony",
  };
  int num_common_words = sizeof(common_words) / sizeof(char *);
  for (int i = 0; i < num_common_words; i++) {
    if (strcmp(password, common_words[i]) == 0) {
      score -= 20;
      break;
    }
  }

  // Return the password score
  return score;
}

// Define the main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password score
  int score = calculate_password_score(password);

  // Determine the password strength level
  int strength;
  if (score < 0) {
    strength = PASSWORD_STRENGTH_WEAK;
  } else if (score < 15) {
    strength = PASSWORD_STRENGTH_MEDIUM;
  } else {
    strength = PASSWORD_STRENGTH_STRONG;
  }

  // Print the password strength level
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
  }

  return 0;
}