//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASS_LENGTH 8
#define MAX_PASS_LENGTH 32

// Function to generate a random character between 'a' and 'z'
char generate_random_lowercase_char() {
  return 'a' + (rand() % 26);
}

// Function to generate a random character between 'A' and 'Z'
char generate_random_uppercase_char() {
  return 'A' + (rand() % 26);
}

// Function to generate a random character between '0' and '9'
char generate_random_number() {
  return '0' + (rand() % 10);
}

// Function to generate a random character between '!' and '/'
char generate_random_symbol() {
  return '!' + (rand() % 15);
}

// Function to generate a random password
char* generate_random_password(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int type = rand() % 4;
    switch (type) {
      case 0:
        password[i] = generate_random_lowercase_char();
        break;
      case 1:
        password[i] = generate_random_uppercase_char();
        break;
      case 2:
        password[i] = generate_random_number();
        break;
      case 3:
        password[i] = generate_random_symbol();
        break;
    }
  }
  password[length] = '\0';
  return password;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the desired password length from the user
  int length;
  printf("Enter the desired password length (between %d and %d): ", MIN_PASS_LENGTH, MAX_PASS_LENGTH);
  scanf("%d", &length);

  // Validate the password length
  if (length < MIN_PASS_LENGTH || length > MAX_PASS_LENGTH) {
    printf("Invalid password length. Please enter a length between %d and %d.\n", MIN_PASS_LENGTH, MAX_PASS_LENGTH);
    return 1;
  }

  // Generate a random password
  char *password = generate_random_password(length);

  // Print the generated password
  printf("Your random password is: %s\n", password);

  // Free the allocated memory
  free(password);

  return 0;
}