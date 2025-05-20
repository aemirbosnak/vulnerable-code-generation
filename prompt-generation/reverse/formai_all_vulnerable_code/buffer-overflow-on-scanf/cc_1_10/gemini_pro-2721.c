//GEMINI-pro DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password requirements
#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define REQUIRES_UPPERCASE
#define REQUIRES_LOWERCASE
#define REQUIRES_NUMBER
#define REQUIRES_SPECIAL_CHARACTER

// Special character list
char special_characters[] = "!@#$%^&*()-_=+";

// Function to check if a password is valid
int is_valid_password(char *password) {
  int length = strlen(password);

  // Check the length of the password
  if (length < MIN_LENGTH || length > MAX_LENGTH) {
    return 0;
  }

  // Check if the password contains an uppercase letter
  int contains_uppercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      contains_uppercase = 1;
      break;
    }
  }
  if (!contains_uppercase) {
    return 0;
  }

  // Check if the password contains a lowercase letter
  int contains_lowercase = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      contains_lowercase = 1;
      break;
    }
  }
  if (!contains_lowercase) {
    return 0;
  }

  // Check if the password contains a number
  int contains_number = 0;
  for (int i = 0; i < length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      contains_number = 1;
      break;
    }
  }
  if (!contains_number) {
    return 0;
  }

  // Check if the password contains a special character
  int contains_special_character = 0;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < strlen(special_characters); j++) {
      if (password[i] == special_characters[j]) {
        contains_special_character = 1;
        break;
      }
    }
  }
  if (!contains_special_character) {
    return 0;
  }

  // The password is valid if it meets all of the requirements
  return 1;
}

// Function to generate a random password
char *generate_random_password() {
  // Create a random seed
  srand(time(NULL));

  // Generate a random password length
  int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;

  // Generate a random password
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int type = rand() % 4;

    if (type == 0) {
      password[i] = rand() % 26 + 'a';
    } else if (type == 1) {
      password[i] = rand() % 26 + 'A';
    } else if (type == 2) {
      password[i] = rand() % 10 + '0';
    } else {
      password[i] = special_characters[rand() % strlen(special_characters)];
    }
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Get the user's input
  char *password = malloc(MAX_LENGTH + 1);
  printf("Enter a password (8-16 characters, must contain at least one uppercase letter, one lowercase letter, one number, and one special character): ");
  scanf("%s", password);

  // Check if the password is valid
  int is_valid = is_valid_password(password);

  // If the password is valid, print it out
  if (is_valid) {
    printf("Your password is valid.\n");
  } else {
    printf("Your password is invalid.\n");

    // Generate a random password
    char *random_password = generate_random_password();

    // Print out the random password
    printf("Here is a random password that meets the requirements: %s\n", random_password);

    // Free the memory allocated for the random password
    free(random_password);
  }

  // Free the memory allocated for the user's input
  free(password);

  return 0;
}