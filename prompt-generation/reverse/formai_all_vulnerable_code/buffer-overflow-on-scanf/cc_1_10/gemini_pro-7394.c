//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 256

// Function prototypes

int get_password_length();
char* get_password();
int check_password_strength(char* password);
void print_password_strength(int strength);

int main() {
  char* password;
  int password_length;
  int password_strength;

  // Get the password length from the user
  password_length = get_password_length();

  // Allocate memory for the password
  password = malloc(password_length + 1);

  // Get the password from the user
  strcpy(password, get_password());

  // Check the password strength
  password_strength = check_password_strength(password);

  // Print the password strength
  print_password_strength(password_strength);

  // Free the memory allocated for the password
  free(password);

  return 0;
}

int get_password_length() {
  int password_length;

  printf("Enter the length of the password: ");
  scanf("%d", &password_length);

  return password_length;
}

char* get_password() {
  char* password;
  int password_length;

  printf("Enter the password: ");
  scanf("%s", password);

  return password;
}

int check_password_strength(char* password) {
  int password_strength = 0;
  int password_length = strlen(password);

  // Check the password length
  if (password_length >= MIN_PASSWORD_LENGTH && password_length <= MAX_PASSWORD_LENGTH) {
    password_strength += 1;
  }

  // Check the password for uppercase letters
  for (int i = 0; i < password_length; i++) {
    if (isupper(password[i])) {
      password_strength += 1;
      break;
    }
  }

  // Check the password for lowercase letters
  for (int i = 0; i < password_length; i++) {
    if (islower(password[i])) {
      password_strength += 1;
      break;
    }
  }

  // Check the password for digits
  for (int i = 0; i < password_length; i++) {
    if (isdigit(password[i])) {
      password_strength += 1;
      break;
    }
  }

  // Check the password for special characters
  for (int i = 0; i < password_length; i++) {
    if (!isalnum(password[i])) {
      password_strength += 1;
      break;
    }
  }

  return password_strength;
}

void print_password_strength(int strength) {
  switch (strength) {
    case 0:
      printf("The password is weak.\n");
      break;
    case 1:
      printf("The password is fair.\n");
      break;
    case 2:
      printf("The password is good.\n");
      break;
    case 3:
      printf("The password is strong.\n");
      break;
    case 4:
      printf("The password is very strong.\n");
    default:
      printf("The password is invalid.\n");
  }
}