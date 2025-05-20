//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char randomChar() {
  int r = rand() % 26;
  return 'a' + r;
}

// Function to generate a random number
int randomNumber() {
  return rand() % 10;
}

// Function to generate a random symbol
char randomSymbol() {
  int r = rand() % 3;
  switch (r) {
    case 0:
      return '!';
    case 1:
      return '@';
    case 2:
      return '#';
  }
}

// Function to generate a random password
char* generatePassword(int length) {
  char* password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int r = rand() % 3;
    switch (r) {
      case 0:
        password[i] = randomChar();
        break;
      case 1:
        password[i] = randomNumber() + '0';
        break;
      case 2:
        password[i] = randomSymbol();
        break;
    }
  }
  password[length] = '\0';
  return password;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int length;
  printf("Enter the length of the password: ");
  scanf("%d", &length);

  // Generate a random password
  char* password = generatePassword(length);

  // Print the password to the console
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}