//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the password strength levels
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3

// Define the password length range
#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Define the password character sets
#define LOWERCASE_CHARSET "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMERIC_CHARSET "0123456789"
#define SYMBOLIC_CHARSET "!@#$%^&*()_+=-`~"

// Define the password scoring parameters
#define LENGTH_SCORE 4
#define TYPE_SCORE 3
#define ORDER_SCORE 2

// Define the password strength thresholds
#define WEAK_THRESHOLD 20
#define FAIR_THRESHOLD 40
#define GOOD_THRESHOLD 60
#define STRONG_THRESHOLD 80

// Function to calculate the password length score
int calculate_length_score(int length) {
  if (length < MIN_LENGTH) {
    return 0;
  } else if (length > MAX_LENGTH) {
    return LENGTH_SCORE;
  } else {
    return (length - MIN_LENGTH) * LENGTH_SCORE / (MAX_LENGTH - MIN_LENGTH);
  }
}

// Function to calculate the password type score
int calculate_type_score(char *password) {
  int type_score = 0;

  if (strpbrk(password, LOWERCASE_CHARSET) != NULL) {
    type_score++;
  }

  if (strpbrk(password, UPPERCASE_CHARSET) != NULL) {
    type_score++;
  }

  if (strpbrk(password, NUMERIC_CHARSET) != NULL) {
    type_score++;
  }

  if (strpbrk(password, SYMBOLIC_CHARSET) != NULL) {
    type_score++;
  }

  return type_score * TYPE_SCORE;
}

// Function to calculate the password order score
int calculate_order_score(char *password) {
  int order_score = 0;

  for (int i = 0; i < strlen(password) - 1; i++) {
    if (password[i] > password[i + 1]) {
      order_score++;
    }
  }

  return order_score * ORDER_SCORE;
}

// Function to calculate the password strength score
int calculate_strength_score(char *password) {
  int length_score = calculate_length_score(strlen(password));
  int type_score = calculate_type_score(password);
  int order_score = calculate_order_score(password);

  return length_score + type_score + order_score;
}

// Function to determine the password strength level
int determine_strength_level(int strength_score) {
  if (strength_score < WEAK_THRESHOLD) {
    return WEAK;
  } else if (strength_score < FAIR_THRESHOLD) {
    return FAIR;
  } else if (strength_score < GOOD_THRESHOLD) {
    return GOOD;
  } else {
    return STRONG;
  }
}

// Function to print the password strength level
void print_strength_level(int strength_level) {
  switch (strength_level) {
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

// Main function
int main() {
  // Get the password from the user
  char password[MAX_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength score
  int strength_score = calculate_strength_score(password);

  // Determine the password strength level
  int strength_level = determine_strength_level(strength_score);

  // Print the password strength level
  print_strength_level(strength_level);

  return 0;
}