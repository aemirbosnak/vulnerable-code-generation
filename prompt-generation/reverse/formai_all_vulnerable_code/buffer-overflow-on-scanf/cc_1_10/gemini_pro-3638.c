//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  // Seed the random number generator with the current time.
  srand(time(NULL));

  // Get the length of the password from the user.
  int length;
  printf("Enter the length of the password you want to generate: ");
  scanf("%d", &length);

  // Create an array to store the password.
  char password[length + 1];

  // Generate the password.
  for (int i = 0; i < length; i++) {
    // Generate a random number between 33 and 126.
    int number = rand() % 94 + 33;

    // Convert the number to a character.
    char character = (char)number;

    // Add the character to the password.
    password[i] = character;
  }

  // Terminate the password with a null character.
  password[length] = '\0';

  // Print the password to the console.
  printf("Your password is: %s\n", password);
  
  if(length < 10)
  {
    printf("This password is weak, please consider using a longer password with a mix of characters and symbols!\n");
  }
  else if(length >= 10 && length < 15)
  {
    printf("This password is moderate, please consider using a mix of characters, symbols and numbers to make it stronger!\n");
  }
  else
  {
    printf("This password is strong, however, you can still improve it by using a mix of characters, numbers and symbols!\n");
  }
  
  return 0;
}