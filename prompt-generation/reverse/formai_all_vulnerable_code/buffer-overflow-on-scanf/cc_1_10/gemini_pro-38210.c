//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 100

// Function to check if the password contains at least one digit
int hasDigit(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Function to check if the password contains at least one lowercase letter
int hasLowercase(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Function to check if the password contains at least one uppercase letter
int hasUppercase(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Function to check if the password contains at least one special character
int hasSpecialCharacter(char *password) {
  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      return 1;
    }
  }
  return 0;
}

// Function to check the strength of the password
int checkPasswordStrength(char *password) {
  int score = 0;

  // Check the length of the password
  if (strlen(password) < MIN_LENGTH) {
    printf("Your password is too short! It should be at least %d characters long.\n", MIN_LENGTH);
  } else if (strlen(password) > MAX_LENGTH) {
    printf("Your password is too long! It should be less than %d characters long.\n", MAX_LENGTH);
  } else {
    score++;
  }

  // Check if the password contains at least one digit
  if (hasDigit(password)) {
    score++;
  } else {
    printf("Your password should contain at least one digit.\n");
  }

  // Check if the password contains at least one lowercase letter
  if (hasLowercase(password)) {
    score++;
  } else {
    printf("Your password should contain at least one lowercase letter.\n");
  }

  // Check if the password contains at least one uppercase letter
  if (hasUppercase(password)) {
    score++;
  } else {
    printf("Your password should contain at least one uppercase letter.\n");
  }

  // Check if the password contains at least one special character
  if (hasSpecialCharacter(password)) {
    score++;
  } else {
    printf("Your password should contain at least one special character.\n");
  }

  return score;
}

int main() {
  char password[MAX_LENGTH];

  printf("Please enter your password: ");
  scanf("%s", password);

  int score = checkPasswordStrength(password);

  switch (score) {
    case 0:
      printf("Your password is too weak!\n");
      break;
    case 1:
      printf("Your password is weak!\n");
      break;
    case 2:
      printf("Your password is OK!\n");
      break;
    case 3:
      printf("Your password is good!\n");
      break;
    case 4:
      printf("Your password is strong!\n");
      break;
    case 5:
      printf("Your password is very strong!\n");
      break;
    default:
      printf("Invalid password!\n");
  }

  return 0;
}