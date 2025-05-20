//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generate_random_char() {
  // Generate a random number between 32 and 126 (inclusive)
  int random_num = rand() % (126 - 32 + 1) + 32;

  // Convert the random number to a character
  char random_char = (char)random_num;

  return random_char;
}

// Function to generate a random password
char *generate_random_password(int length) {
  // Allocate memory for the password
  char *password = (char *)malloc(length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    password[i] = generate_random_char();
  }

  // Terminate the password with a null character
  password[length] = '\0';

  return password;
}

// Function to print the password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the password from the user
  int length;
  printf("Enter the length of the password you want: ");
  scanf("%d", &length);

  // Generate a random password
  char *password = generate_random_password(length);

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}