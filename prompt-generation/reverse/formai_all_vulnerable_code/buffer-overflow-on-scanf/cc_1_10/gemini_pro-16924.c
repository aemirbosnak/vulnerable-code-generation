//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom string comparison function that ignores case
int strcicmp(const char *s1, const char *s2) {
  int i;
  for (i = 0; tolower(s1[i]) != '\0' && tolower(s2[i]) != '\0'; i++) {
    if (tolower(s1[i]) != tolower(s2[i])) {
      return tolower(s1[i]) - tolower(s2[i]);
    }
  }
  return 0;
}

// Custom function to check if a character is a special character
int is_special_char(char c) {
  static const char special_chars[] = "!@#$%^&*()-=+[]{}\\|;:'\",<>./?";
  int i;
  for (i = 0; i < strlen(special_chars); i++) {
    if (c == special_chars[i]) {
      return 1;
    }
  }
  return 0;
}

// Custom function to calculate the strength of a password
int calculate_password_strength(const char *password) {
  int score = 0;
  int length_score = 0;
  int lowercase_score = 0;
  int uppercase_score = 0;
  int digit_score = 0;
  int special_char_score = 0;

  // Check the length of the password
  if (strlen(password) >= 8) {
    length_score += 5;
  } else if (strlen(password) >= 6) {
    length_score += 3;
  } else if (strlen(password) >= 4) {
    length_score += 1;
  }

  // Check for lowercase characters
  for (int i = 0; password[i] != '\0'; i++) {
    if (islower(password[i])) {
      lowercase_score += 1;
    }
  }
  if (lowercase_score >= 3) {
    lowercase_score += 2;
  } else if (lowercase_score >= 1) {
    lowercase_score += 1;
  }

  // Check for uppercase characters
  for (int i = 0; password[i] != '\0'; i++) {
    if (isupper(password[i])) {
      uppercase_score += 1;
    }
  }
  if (uppercase_score >= 3) {
    uppercase_score += 2;
  } else if (uppercase_score >= 1) {
    uppercase_score += 1;
  }

  // Check for digits
  for (int i = 0; password[i] != '\0'; i++) {
    if (isdigit(password[i])) {
      digit_score += 1;
    }
  }
  if (digit_score >= 3) {
    digit_score += 2;
  } else if (digit_score >= 1) {
    digit_score += 1;
  }

  // Check for special characters
  for (int i = 0; password[i] != '\0'; i++) {
    if (is_special_char(password[i])) {
      special_char_score += 1;
    }
  }
  if (special_char_score >= 3) {
    special_char_score += 2;
  } else if (special_char_score >= 1) {
    special_char_score += 1;
  }

  // Calculate the total score
  score = length_score + lowercase_score + uppercase_score + digit_score + special_char_score;

  return score;
}

// Custom function to print the strength of a password
void print_password_strength(const char *password) {
  int score = calculate_password_strength(password);

  if (score >= 8) {
    printf("Your password is very strong!\n");
  } else if (score >= 6) {
    printf("Your password is strong!\n");
  } else if (score >= 4) {
    printf("Your password is moderate!\n");
  } else if (score >= 2) {
    printf("Your password is weak!\n");
  } else {
    printf("Your password is very weak!\n");
  }
}

// Main function
int main() {
  char password[100];

  printf("Enter your password: ");
  scanf("%s", password);

  print_password_strength(password);

  return 0;
}