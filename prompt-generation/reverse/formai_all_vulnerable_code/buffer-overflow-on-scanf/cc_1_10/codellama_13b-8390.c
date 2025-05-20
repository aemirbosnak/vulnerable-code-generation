//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
/*
 * Password Strength Checker
 *
 * This program checks the strength of a given password and provides feedback
 * on its strength based on a set of criteria.
 */

#include <stdio.h>
#include <string.h>

// Define the strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2
#define VERY_STRONG 3

// Define the criteria for each strength level
#define WEAK_CRITERIA "1234567890"
#define MEDIUM_CRITERIA "1234567890!@#$%^&*()"
#define STRONG_CRITERIA "1234567890!@#$%^&*()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define VERY_STRONG_CRITERIA "1234567890!@#$%^&*()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-"

// Function to check the strength of a password
int check_strength(char *password) {
  int strength = WEAK;
  int criteria_length = strlen(WEAK_CRITERIA);
  int i;

  for (i = 0; i < criteria_length; i++) {
    if (strchr(password, WEAK_CRITERIA[i]) != NULL) {
      strength = WEAK;
      break;
    }
  }

  criteria_length = strlen(MEDIUM_CRITERIA);
  for (i = 0; i < criteria_length; i++) {
    if (strchr(password, MEDIUM_CRITERIA[i]) != NULL) {
      strength = MEDIUM;
      break;
    }
  }

  criteria_length = strlen(STRONG_CRITERIA);
  for (i = 0; i < criteria_length; i++) {
    if (strchr(password, STRONG_CRITERIA[i]) != NULL) {
      strength = STRONG;
      break;
    }
  }

  criteria_length = strlen(VERY_STRONG_CRITERIA);
  for (i = 0; i < criteria_length; i++) {
    if (strchr(password, VERY_STRONG_CRITERIA[i]) != NULL) {
      strength = VERY_STRONG;
      break;
    }
  }

  return strength;
}

// Function to print the strength of a password
void print_strength(int strength) {
  switch (strength) {
    case WEAK:
      printf("Password is weak\n");
      break;
    case MEDIUM:
      printf("Password is medium\n");
      break;
    case STRONG:
      printf("Password is strong\n");
      break;
    case VERY_STRONG:
      printf("Password is very strong\n");
      break;
    default:
      printf("Password is unknown\n");
      break;
  }
}

int main() {
  char password[20];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int strength = check_strength(password);

  // Print the strength of the password
  print_strength(strength);

  return 0;
}