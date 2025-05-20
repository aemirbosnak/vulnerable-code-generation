//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character
char generate_random_character() {
  // Get a random number between 33 and 126
  int random_number = rand() % (126 - 33 + 1) + 33;

  // Convert the random number to a character
  char random_character = (char)random_number;

  // Return the random character
  return random_character;
}

// Function to generate a random password
char *generate_random_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    password[i] = generate_random_character();
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Function to print the password
void print_password(char *password) {
  // Print the password
  printf("Your password is: %s\n", password);
}

// Function to get the length of the password from the user
int get_password_length() {
  // Get the password length from the user
  int length;
  printf("Enter the length of the password you want: ");
  scanf("%d", &length);

  // Return the password length
  return length;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int length = get_password_length();

  // Generate a random password
  char *password = generate_random_password(length);

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}