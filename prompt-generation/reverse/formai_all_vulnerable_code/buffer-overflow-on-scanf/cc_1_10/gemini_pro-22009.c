//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Check if the password is at least 8 characters long
int checkLength(char* password) {
  int length = strlen(password);
  if (length < 8) {
    printf("Your password is too short! It must be at least 8 characters long.\n");
    return 0;
  }
  return 1;
}

// Check if the password contains at least one uppercase letter
int checkUppercase(char* password) {
  int i;
  int found = 0;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Your password must contain at least one uppercase letter.\n");
    return 0;
  }
  return 1;
}

// Check if the password contains at least one lowercase letter
int checkLowercase(char* password) {
  int i;
  int found = 0;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Your password must contain at least one lowercase letter.\n");
    return 0;
  }
  return 1;
}

// Check if the password contains at least one digit
int checkDigit(char* password) {
  int i;
  int found = 0;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Your password must contain at least one digit.\n");
    return 0;
  }
  return 1;
}

// Check if the password contains at least one special character
int checkSpecialChar(char* password) {
  int i;
  int found = 0;
  for (i = 0; i < strlen(password); i++) {
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Your password must contain at least one special character (!, @, #, $, %)\n");
    return 0;
  }
  return 1;
}

int main() {
  char password[100];
  int strength = 0;
  printf("Enter your password: ");
  scanf("%s", password);

  if (checkLength(password)) {
    strength++;
    printf("1/5 - Your password is at least 8 characters long.\n");
  }
  if (checkUppercase(password)) {
    strength++;
    printf("2/5 - Your password contains at least one uppercase letter.\n");
  }
  if (checkLowercase(password)) {
    strength++;
    printf("3/5 - Your password contains at least one lowercase letter.\n");
  }
  if (checkDigit(password)) {
    strength++;
    printf("4/5 - Your password contains at least one digit.\n");
  }
  if (checkSpecialChar(password)) {
    strength++;
    printf("5/5 - Your password contains at least one special character.\n");
  }

  switch (strength) {
    case 0:
      printf("Your password is too weak. Please try again.\n");
      break;
    case 1:
      printf("Your password is weak. Please try again.\n");
      break;
    case 2:
      printf("Your password is getting stronger. Keep going!\n");
      break;
    case 3:
      printf("Your password is strong. Good job!\n");
      break;
    case 4:
      printf("Your password is very strong. You're a security expert!\n");
      break;
    case 5:
      printf("Your password is unbeatable. You're a cybersecurity ninja!\n");
      break;
  }

  return 0;
}