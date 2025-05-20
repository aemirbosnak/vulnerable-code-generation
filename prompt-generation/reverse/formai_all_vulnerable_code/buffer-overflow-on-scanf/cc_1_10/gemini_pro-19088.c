//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int score = 0;

  // Check the length of the password
  if (strlen(password) < 8) {
    score += 1;
  }

  // Check if the password contains any uppercase letters
  if (!strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
    score += 1;
  }

  // Check if the password contains any lowercase letters
  if (!strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
    score += 1;
  }

  // Check if the password contains any digits
  if (!strpbrk(password, "0123456789")) {
    score += 1;
  }

  // Check if the password contains any special characters
  if (!strpbrk(password, "!@#$%^&*()-+?")) {
    score += 1;
  }

  // Check if the password contains any repeated characters
  for (int i = 0; i < strlen(password); i++) {
    for (int j = i + 1; j < strlen(password); j++) {
      if (password[i] == password[j]) {
        score += 1;
      }
    }
  }

  // Check if the password is commonly used
  char *common_passwords[] = {"password", "123456", "12345678", "qwerty", "abc123"};
  for (int i = 0; i < sizeof(common_passwords) / sizeof(char *); i++) {
    if (strcmp(password, common_passwords[i]) == 0) {
      score += 5;
    }
  }

  // Return the score
  return score;
}

// Function to generate a strong password
char *generate_strong_password(int length) {
  // Create a string of all possible characters
  char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-+?";

  // Create a buffer to store the password
  char *password = malloc(sizeof(char) * (length + 1));

  // Generate a random password
  for (int i = 0; i < length; i++) {
    password[i] = characters[rand() % (sizeof(characters) - 1)];
  }

  // Null-terminate the password
  password[length] = '\0';

  // Return the password
  return password;
}

int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the strength of the password
  int score = check_password_strength(password);

  // Print the strength of the password
  if (score == 0) {
    printf("Your password is strong.\n");
  } else if (score <= 2) {
    printf("Your password is weak.\n");
  } else {
    printf("Your password is very weak.\n");
  }

  // Generate a strong password
  char *strong_password = generate_strong_password(10);

  // Print the strong password
  printf("Here is a strong password: %s\n", strong_password);

  // Free the memory allocated for the strong password
  free(strong_password);

  return 0;
}