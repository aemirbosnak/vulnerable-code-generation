//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SYMBOL 3

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Define the password strength messages
#define MSG_WEAK "Weak password"
#define MSG_MEDIUM "Medium password"
#define MSG_STRONG "Strong password"

// Function to check if a character is in a certain character class
int char_in_class(char c, int char_class) {
  switch (char_class) {
    case CHAR_CLASS_LOWER:
      return c >= 'a' && c <= 'z';
    case CHAR_CLASS_UPPER:
      return c >= 'A' && c <= 'Z';
    case CHAR_CLASS_DIGIT:
      return c >= '0' && c <= '9';
    case CHAR_CLASS_SYMBOL:
      return !char_in_class(c, CHAR_CLASS_LOWER) && !char_in_class(c, CHAR_CLASS_UPPER) && !char_in_class(c, CHAR_CLASS_DIGIT);
    default:
      return 0;
  }
}

// Function to check the strength of a password
int check_password_strength(char *password) {
  // Check if the password is long enough
  if (strlen(password) < MIN_LENGTH) {
    return STRENGTH_WEAK;
  }

  // Check if the password is too long
  if (strlen(password) > MAX_LENGTH) {
    return STRENGTH_WEAK;
  }

  // Check if the password contains at least one character from each character class
  int char_classes[4] = {0, 0, 0, 0};
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < 4; j++) {
      if (char_in_class(password[i], j)) {
        char_classes[j] = 1;
      }
    }
  }
  if (!char_classes[CHAR_CLASS_LOWER] || !char_classes[CHAR_CLASS_UPPER] || !char_classes[CHAR_CLASS_DIGIT] || !char_classes[CHAR_CLASS_SYMBOL]) {
    return STRENGTH_WEAK;
  }

  // Check if the password contains any common words
  char *common_words[] = {"password", "123456", "qwerty", "abc123", "iloveyou"};
  for (int i = 0; i < 5; i++) {
    if (strstr(password, common_words[i]) != NULL) {
      return STRENGTH_WEAK;
    }
  }

  // If the password meets all of the above criteria, then it is strong
  return STRENGTH_STRONG;
}

// Main function
int main() {
  // Get the password from the user
  char password[MAX_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_password_strength(password);

  // Print the password strength message
  switch (strength) {
    case STRENGTH_WEAK:
      printf("%s\n", MSG_WEAK);
      break;
    case STRENGTH_MEDIUM:
      printf("%s\n", MSG_MEDIUM);
      break;
    case STRENGTH_STRONG:
      printf("%s\n", MSG_STRONG);
      break;
  }

  return 0;
}