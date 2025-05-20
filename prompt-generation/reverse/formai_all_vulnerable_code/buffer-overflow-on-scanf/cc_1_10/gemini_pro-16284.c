//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character set for the password
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Get a random number in the range [0, n)
int get_random_number(int n) {
  return rand() % n;
}

// Generate a random password of length n
char *generate_password(int n) {
  // Allocate memory for the password
  char *password = malloc(n + 1);  // +1 for the null terminator

  // Iterate over the password and generate each character randomly
  for (int i = 0; i < n; i++) {
    int index = get_random_number(strlen(CHARSET));
    password[i] = CHARSET[index];
  }

  // Null-terminate the password
  password[n] = '\0';

  // Return the password
  return password;
}

// Get the length of the password from the user
int get_password_length() {
  int n;
  printf("Enter the desired password length: ");
  scanf("%d", &n);
  return n;
}

// Print the generated password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
  free(password);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int n = get_password_length();

  // Generate a random password
  char *password = generate_password(n);

  // Print the generated password
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}