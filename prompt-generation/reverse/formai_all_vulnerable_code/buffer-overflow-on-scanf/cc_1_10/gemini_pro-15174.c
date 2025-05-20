//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the password character set and its length
const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+";
const size_t charset_length = sizeof(charset) - 1;

// Generate a random password of the given length
char *generate_password(size_t length) {
  char *password = malloc((length + 1) * sizeof(char));
  if (!password) {
    return NULL; // Error: could not allocate memory
  }

  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate each character of the password randomly
  for (size_t i = 0; i < length; i++) {
    password[i] = charset[rand() % charset_length];
  }

  // Null-terminate the password string
  password[length] = '\0';

  return password;
}

// Display the generated password
void display_password(const char *password) {
  printf("Your new password is: %s\n", password);
}

int main() {
  // Get the desired password length from the user
  size_t length;
  printf("How long do you want your password to be? ");
  scanf("%zu", &length);

  // Generate the password and display it
  char *password = generate_password(length);
  display_password(password);

  // Free the allocated memory
  free(password);

  return 0;
}