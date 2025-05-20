//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the character class weights
#define CHAR_CLASS_LOWER_WEIGHT 1
#define CHAR_CLASS_UPPER_WEIGHT 2
#define CHAR_CLASS_DIGIT_WEIGHT 3
#define CHAR_CLASS_SPECIAL_WEIGHT 4

// Define the entropy calculation function
double calculate_entropy(char *password) {
  // Get the password length
  int password_length = strlen(password);

  // Create an array to store the character class counts
  int char_class_counts[CHAR_CLASS_SPECIAL + 1];

  // Initialize the character class counts to 0
  for (int i = 0; i < CHAR_CLASS_SPECIAL + 1; i++) {
    char_class_counts[i] = 0;
  }

  // Count the number of characters in each character class
  for (int i = 0; i < password_length; i++) {
    char character = password[i];

    if (character >= 'a' && character <= 'z') {
      char_class_counts[CHAR_CLASS_LOWER]++;
    } else if (character >= 'A' && character <= 'Z') {
      char_class_counts[CHAR_CLASS_UPPER]++;
    } else if (character >= '0' && character <= '9') {
      char_class_counts[CHAR_CLASS_DIGIT]++;
    } else {
      char_class_counts[CHAR_CLASS_SPECIAL]++;
    }
  }

  // Calculate the entropy
  double entropy = 0;

  for (int i = 0; i < CHAR_CLASS_SPECIAL + 1; i++) {
    if (char_class_counts[i] > 0) {
      double probability = (double)char_class_counts[i] / password_length;
      entropy += -probability * log2(probability);
    }
  }

  return entropy;
}

// Define the password strength calculation function
int calculate_password_strength(char *password) {
  // Get the password entropy
  double entropy = calculate_entropy(password);

  // Get the password length
  int password_length = strlen(password);

  // Calculate the password strength
  int password_strength;

  if (password_length < MIN_PASSWORD_LENGTH) {
    password_strength = PASSWORD_STRENGTH_WEAK;
  } else if (entropy < 40) {
    password_strength = PASSWORD_STRENGTH_MEDIUM;
  } else {
    password_strength = PASSWORD_STRENGTH_STRONG;
  }

  return password_strength;
}

// Define the main function
int main() {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Calculate the password strength
  int password_strength = calculate_password_strength(password);

  // Print the password strength
  switch (password_strength) {
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