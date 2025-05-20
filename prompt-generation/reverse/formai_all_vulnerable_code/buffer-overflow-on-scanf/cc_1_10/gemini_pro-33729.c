//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
char *generatePassword(int length) {
  // Array of all possible characters
  char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
  int charactersLength = strlen(characters);

  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate the password
  for (int i = 0; i < length; i++) {
    int randomIndex = rand() % charactersLength;
    password[i] = characters[randomIndex];
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Function to print a happy message
void printHappyMessage() {
  printf("Yay! You've got a new password!\n");
  printf("May it bring you joy and happiness!\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int length;
  printf("How long do you want your password to be?\n");
  scanf("%d", &length);

  // Generate the password
  char *password = generatePassword(length);

  // Print the password
  printf("Your new password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  // Print a happy message
  printHappyMessage();

  return 0;
}