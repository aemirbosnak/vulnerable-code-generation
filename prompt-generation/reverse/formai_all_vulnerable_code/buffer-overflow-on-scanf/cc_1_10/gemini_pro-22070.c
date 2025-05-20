//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password) {
  int strength = 0;

  // Check the length of the password
  if (strlen(password) >= 8) {
    strength += 1;
  }

  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      strength += 1;
      break;
    }
  }

  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      strength += 1;
      break;
    }
  }

  // Check if the password contains at least one digit
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      strength += 1;
      break;
    }
  }

  // Check if the password contains at least one special character
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      strength += 1;
      break;
    }
  }

  return strength;
}

// Function to print the password strength
void print_password_strength(int strength) {
  switch (strength) {
    case 0:
      printf("Your password is weak.\n");
      break;
    case 1:
      printf("Your password is okay.\n");
      break;
    case 2:
      printf("Your password is good.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
    case 5:
      printf("Your password is awesome!\n");
      break;
  }
}

int main() {
  // Get the password from the user
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password_strength(password);

  // Print the password strength
  print_password_strength(strength);

  return 0;
}