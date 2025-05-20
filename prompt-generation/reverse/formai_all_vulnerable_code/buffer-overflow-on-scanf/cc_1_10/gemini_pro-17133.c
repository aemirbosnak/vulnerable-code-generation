//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int checkPasswordStrength(char *password, int len) {
  // Base case: if the length of the password is less than 8, it is not strong
  if (len < 8) {
    return 0;
  }

  // Recursive case: check if the password contains at least one uppercase letter,
  // one lowercase letter, and one digit
  int hasUppercase = 0;
  int hasLowercase = 0;
  int hasDigit = 0;
  for (int i = 0; i < len; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      hasUppercase = 1;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      hasLowercase = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      hasDigit = 1;
    }
  }

  // If the password contains at least one uppercase letter, one lowercase letter,
  // and one digit, it is strong
  if (hasUppercase && hasLowercase && hasDigit) {
    return 1;
  }

  // Otherwise, the password is not strong
  else {
    return 0;
  }
}

// Function to generate a random password of a given length
char *generatePassword(int len) {
  // Create an array of all the possible characters for the password
  char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  int charsetLen = strlen(charset);

  // Allocate memory for the password
  char *password = malloc(len + 1);

  // Generate the password by randomly selecting characters from the charset
  for (int i = 0; i < len; i++) {
    int randomIndex = rand() % charsetLen;
    password[i] = charset[randomIndex];
  }

  // Terminate the password with a null character
  password[len] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Get the desired length of the password from the user
  int len;
  printf("Enter the desired length of the password: ");
  scanf("%d", &len);

  // Generate a random password of the given length
  char *password = generatePassword(len);

  // Check if the password is strong
  int isStrong = checkPasswordStrength(password, len);

  // Print the password and its strength
  printf("Password: %s\n", password);
  if (isStrong) {
    printf("The password is strong.\n");
  } else {
    printf("The password is not strong.\n");
  }

  // Free the memory allocated for the password
  free(password);

  return 0;
}