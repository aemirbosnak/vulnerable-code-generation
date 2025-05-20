//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password(char *password) {
  int strength = 0;
  int len = strlen(password);

  // Check if the password is at least 8 characters long
  if (len >= 8) {
    strength++;
  }

  // Check if the password contains at least one uppercase letter
  for (int i = 0; i < len; i++) {
    if ('A' <= password[i] && password[i] <= 'Z') {
      strength++;
      break;
    }
  }

  // Check if the password contains at least one lowercase letter
  for (int i = 0; i < len; i++) {
    if ('a' <= password[i] && password[i] <= 'z') {
      strength++;
      break;
    }
  }

  // Check if the password contains at least one digit
  for (int i = 0; i < len; i++) {
    if ('0' <= password[i] && password[i] <= '9') {
      strength++;
      break;
    }
  }

  // Check if the password contains at least one special character
  int special_characters[] = {'!', '@', '#', '$', '%', '^', '&', '*'};
  int num_special_characters = sizeof(special_characters) / sizeof(special_characters[0]);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < num_special_characters; j++) {
      if (password[i] == special_characters[j]) {
        strength++;
        break;
      }
    }
  }

  // Check if the password contains any sequences of three or more identical characters
  for (int i = 0; i < len - 2; i++) {
    if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
      strength--;
      break;
    }
  }

  // Check if the password contains any common words
  char *common_words[] = {"password", "123456", "qwerty", "iloveyou", "princess", "rockstar", "superman", "batman"};
  int num_common_words = sizeof(common_words) / sizeof(common_words[0]);
  for (int i = 0; i < num_common_words; i++) {
    if (strcmp(password, common_words[i]) == 0) {
      strength--;
      break;
    }
  }

  return strength;
}

// Function to print the password strength
void print_password_strength(int strength) {
  switch (strength) {
    case 0:
      printf("Very weak password\n");
      break;
    case 1:
      printf("Weak password\n");
      break;
    case 2:
      printf("Fair password\n");
      break;
    case 3:
      printf("Good password\n");
      break;
    case 4:
      printf("Strong password\n");
      break;
    case 5:
      printf("Very strong password\n");
      break;
    default:
      printf("Invalid password\n");
      break;
  }
}

// Main function
int main() {
  char password[100];

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  int strength = check_password(password);

  // Print the password strength
  print_password_strength(strength);

  return 0;
}