//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Array of characters to choose from
const char chars[] = "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "0123456789"
                     "!@#$%^&*()";

// Function to generate a random password
char *generate_password(int length) {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate the password
  for (int i = 0; i < length; i++) {
    // Generate a random index into the characters array
    int index = rand() % (sizeof(chars) - 1);

    // Set the character at the current index in the password
    password[i] = chars[index];
  }

  // Null-terminate the password
  password[length] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Get the desired password length from the user
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);

  // Generate a password
  char *password = generate_password(length);

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}