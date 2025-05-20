//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
// Claude Shannon Password Strength Checker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define the password strength criteria
#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define MIN_UPPER 1
#define MIN_LOWER 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

// Define the password strength levels
#define WEAK "Weak"
#define FAIR "Fair"
#define GOOD "Good"
#define STRONG "Strong"
#define EXCELLENT "Excellent"

int main() {
  // Declare variables
  char password[MAX_LENGTH + 1];
  int length, upper, lower, digit, special;
  int total_upper, total_lower, total_digit, total_special;
  int total_char;
  int password_strength;

  // Get the password from the user
  printf("Enter your password: ");
  fgets(password, MAX_LENGTH + 1, stdin);

  // Calculate the password length
  length = strlen(password);

  // Count the number of uppercase, lowercase, digits, and special characters
  for (int i = 0; i < length; i++) {
    if (isupper(password[i])) {
      upper++;
    } else if (islower(password[i])) {
      lower++;
    } else if (isdigit(password[i])) {
      digit++;
    } else {
      special++;
    }
  }

  // Calculate the total number of characters
  total_char = length - (upper + lower + digit + special);

  // Calculate the password strength
  if (length < MIN_LENGTH) {
    password_strength = 0;
  } else if (upper < MIN_UPPER || lower < MIN_LOWER || digit < MIN_DIGIT || special < MIN_SPECIAL) {
    password_strength = 1;
  } else if (upper < MIN_UPPER * 2 || lower < MIN_LOWER * 2 || digit < MIN_DIGIT * 2 || special < MIN_SPECIAL * 2) {
    password_strength = 2;
  } else if (upper < MIN_UPPER * 3 || lower < MIN_LOWER * 3 || digit < MIN_DIGIT * 3 || special < MIN_SPECIAL * 3) {
    password_strength = 3;
  } else {
    password_strength = 4;
  }

  // Print the password strength
  switch (password_strength) {
    case 0:
      printf("Password is too short.\n");
      break;
    case 1:
      printf("Password is weak.\n");
      break;
    case 2:
      printf("Password is fair.\n");
      break;
    case 3:
      printf("Password is good.\n");
      break;
    case 4:
      printf("Password is strong.\n");
      break;
  }

  return 0;
}