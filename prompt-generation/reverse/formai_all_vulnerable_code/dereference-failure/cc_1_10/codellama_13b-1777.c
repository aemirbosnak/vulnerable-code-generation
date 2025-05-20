//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
// C Secure Password Generator Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to generate a random number between 0 and 100
int randomNumber(int max) {
  return (rand() % max) + 1;
}

// Function to generate a random uppercase letter
char randomUppercaseLetter() {
  return (char)(rand() % 26) + 65;
}

// Function to generate a random lowercase letter
char randomLowercaseLetter() {
  return (char)(rand() % 26) + 97;
}

// Function to generate a random number or letter
char randomChar() {
  return (rand() % 2) ? randomNumber(10) : (char)(rand() % 26) + 65;
}

// Function to generate a random password
char* generatePassword(int length) {
  char* password = (char*)malloc(length + 1);
  for (int i = 0; i < length; i++) {
    password[i] = randomChar();
  }
  password[length] = '\0';
  return password;
}

// Function to check if a password is valid
bool isValidPassword(char* password) {
  if (strlen(password) < 8) return false;
  bool hasUppercase = false;
  bool hasLowercase = false;
  bool hasNumber = false;
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 65 && password[i] <= 90) hasUppercase = true;
    else if (password[i] >= 97 && password[i] <= 122) hasLowercase = true;
    else if (password[i] >= 48 && password[i] <= 57) hasNumber = true;
  }
  return hasUppercase && hasLowercase && hasNumber;
}

// Main function
int main() {
  srand(time(NULL));
  int length = 10;
  char* password = generatePassword(length);
  printf("Your secure password is: %s\n", password);
  if (isValidPassword(password)) printf("Your password is valid.\n");
  else printf("Your password is not valid.\n");
  free(password);
  return 0;
}