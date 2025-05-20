//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16

// Function to check if a character is a letter
int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a number
int is_number(char c) {
  return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int is_special(char c) {
  return !is_letter(c) && !is_number(c);
}

// Function to check the strength of a password
int check_strength(char* password) {
  int length = strlen(password);

  // Check if the password is too short
  if (length < 8) {
    return 0;
  }

  // Check if the password contains a mix of letters, numbers, and special characters
  int letters = 0, numbers = 0, special = 0;
  for (int i = 0; i < length; i++) {
    if (is_letter(password[i])) {
      letters++;
    } else if (is_number(password[i])) {
      numbers++;
    } else if (is_special(password[i])) {
      special++;
    }
  }

  if (letters == 0 || numbers == 0 || special == 0) {
    return 0;
  }

  // Check if the password contains any common patterns or sequences
  for (int i = 0; i < length - 2; i++) {
    if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
      return 0;
    }
  }

  // Check if the password is a dictionary word
  FILE* dict = fopen("dictionary.txt", "r");
  char word[MAX_PASSWORD_LENGTH + 1];
  while (fscanf(dict, "%s", word) != EOF) {
    if (strcmp(word, password) == 0) {
      return 0;
    }
  }
  fclose(dict);

  // If the password meets all the requirements, return 1
  return 1;
}

int main() {
  char password[MAX_PASSWORD_LENGTH + 1];

  // Prompt the user to enter a password
  printf("Enter a password: ");
  fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);

  // Check the strength of the password
  int strength = check_strength(password);

  // Print the result
  if (strength == 0) {
    printf("Your password is too weak!\n");
  } else {
    printf("Your password is strong!\n");
  }

  return 0;
}