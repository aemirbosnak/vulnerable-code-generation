//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MIN_LENGTH 8
#define MAX_LENGTH 128
#define MIN_SCORE 0
#define MAX_SCORE 10

// Data structures
typedef enum {
  WEAK,
  MEDIUM,
  STRONG
} PasswordStrength;

// Function prototypes
int checkLength(char *password);
int checkComplexity(char *password);
int calculateScore(int length, int complexity);
void printStrength(int score);

// Main function
int main() {
  char password[MAX_LENGTH + 1];  // +1 for null-terminator

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password length
  int lengthScore = checkLength(password);

  // Check the password complexity
  int complexityScore = checkComplexity(password);

  // Calculate the overall password score
  int score = calculateScore(lengthScore, complexityScore);

  // Print the password strength
  printStrength(score);

  return 0;
}

// Function to check the password length
int checkLength(char *password) {
  int length = strlen(password);

  if (length < MIN_LENGTH) {
    return 0;
  } else if (length >= MIN_LENGTH && length <= MAX_LENGTH) {
    return 1;
  } else {
    return 2;
  }
}

// Function to check the password complexity
int checkComplexity(char *password) {
  int complexityScore = 0;

  // Check for uppercase letters
  if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
    complexityScore++;
  }

  // Check for lowercase letters
  if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
    complexityScore++;
  }

  // Check for digits
  if (strpbrk(password, "0123456789")) {
    complexityScore++;
  }

  // Check for special characters
  if (strpbrk(password, "!@#$%^&*()-_=+[]{}\\|;:,<.>/?`~")) {
    complexityScore++;
  }

  return complexityScore;
}

// Function to calculate the overall password score
int calculateScore(int lengthScore, int complexityScore) {
  int score = 0;

  // Add the length score to the total score
  score += lengthScore;

  // Add the complexity score to the total score
  score += complexityScore;

  return score;
}

// Function to print the password strength
void printStrength(int score) {
  switch (score) {
    case WEAK:
      printf("Your password is weak.\n");
      break;
    case MEDIUM:
      printf("Your password is medium.\n");
      break;
    case STRONG:
      printf("Your password is strong.\n");
      break;
    default:
      printf("Invalid password score.\n");
      break;
  }
}