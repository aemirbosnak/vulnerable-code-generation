//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets used in password generation
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_NUMBERS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_+=-"

// Define the maximum length of the password
#define MAX_PASSWORD_LENGTH 20

// Generate a random password of the specified length
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);
  if (password == NULL) {
    return NULL;
  }

  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random password character by character
  for (int i = 0; i < length; i++) {
    // Select a random character set
    int charset_index = rand() % 4;
    char *charset;
    switch (charset_index) {
      case 0:
        charset = CHARSET_LOWERCASE;
        break;
      case 1:
        charset = CHARSET_UPPERCASE;
        break;
      case 2:
        charset = CHARSET_NUMBERS;
        break;
      case 3:
        charset = CHARSET_SYMBOLS;
        break;
    }

    // Select a random character from the selected character set
    int char_index = rand() % strlen(charset);
    password[i] = charset[char_index];
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the generated password
  return password;
}

// Display the generated password
void display_password(char *password) {
  printf("Your generated password is: %s\n", password);
}

// Get the desired password length from the user
int get_password_length() {
  int length;
  printf("Enter the desired password length (maximum %d): ", MAX_PASSWORD_LENGTH);
  scanf("%d", &length);
  while (length <= 0 || length > MAX_PASSWORD_LENGTH) {
    printf("Invalid input. Please enter a valid length (maximum %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
  }
  return length;
}

// Main function
int main() {
  // Get the desired password length from the user
  int length = get_password_length();

  // Generate a random password of the specified length
  char *password = generate_password(length);

  // Display the generated password
  display_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}