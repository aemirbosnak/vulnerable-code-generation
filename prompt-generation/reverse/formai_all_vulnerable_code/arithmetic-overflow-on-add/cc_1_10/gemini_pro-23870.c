//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character
char generateCharacter() {
  // Generate a random number between 0 and 93
  int randomNumber = rand() % 94;

  // Map the random number to a character
  char character;
  if (randomNumber < 26) {
    character = 'a' + randomNumber;
  } else if (randomNumber < 52) {
    character = 'A' + randomNumber - 26;
  } else if (randomNumber < 78) {
    character = '0' + randomNumber - 52;
  } else {
    character = "!@#$%^&*()_+=-";
  }

  return character;
}

// Function to generate a random password
char* generatePassword(int length) {
  // Allocate memory for the password
  char* password = malloc(length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    password[i] = generateCharacter();
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
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

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}