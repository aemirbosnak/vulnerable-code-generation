//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 256

// Function to generate a random password
char* generate_password(int length) {
  // Array of possible characters
  char* characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
  int num_characters = strlen(characters);

  // Allocate memory for the password
  char* password = malloc(length + 1);

  // Generate the password
  for (int i = 0; i < length; i++) {
    password[i] = characters[rand() % num_characters];
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Function to print a password
void print_password(char* password) {
  printf("Your new password is: %s\n", password);
}

// Main function
int main() {
  // Get the length of the password from the user
  int length;
  printf("How long do you want your password to be? ");
  scanf("%d", &length);

  // Generate a password
  char* password = generate_password(length);

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}