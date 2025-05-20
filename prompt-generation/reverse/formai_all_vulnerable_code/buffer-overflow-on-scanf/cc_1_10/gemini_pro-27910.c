//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int main() {
  // Seed the random number generator with the current time.
  srand(time(NULL));

  // Get the length of the password from the user.
  int password_length;
  printf("Enter the length of the password you want to generate: ");
  scanf("%d", &password_length);

  // Check if the password length is valid.
  if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
    printf("Invalid password length. The password length must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    return 1;
  }

  // Declare an array to store the password.
  char password[MAX_PASSWORD_LENGTH + 1];

  // Generate the password.
  for (int i = 0; i < password_length; i++) {
    // Generate a random number between 0 and 94.
    int random_number = rand() % 95;

    // Convert the random number to a character.
    char character;
    if (random_number < 26) {
      // Generate a lowercase letter.
      character = 'a' + random_number;
    } else if (random_number < 52) {
      // Generate an uppercase letter.
      character = 'A' + random_number - 26;
    } else if (random_number < 78) {
      // Generate a digit.
      character = '0' + random_number - 52;
    } else {
      // Generate a special character.
      character = "!@#$%^&*()_+=-`~";
    }

    // Add the character to the password.
    password[i] = character;
  }

  // Terminate the password with a null character.
  password[password_length] = '\0';

  // Print the password to the console.
  printf("Your password is: %s\n", password);

  return 0;
}