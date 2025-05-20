//Code Llama-13B DATASET v1.0 Category: Password management ; Style: realistic
/*
 * C Password Management Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Structure to store a password
typedef struct {
  char *password;
  char *username;
} Password;

// Function to generate a random password
void generatePassword(char *password, int length) {
  int i;
  for (i = 0; i < length; i++) {
    password[i] = (char)(rand() % 26) + 'a';
  }
}

// Function to check if two passwords match
int checkPassword(char *password1, char *password2) {
  if (strcmp(password1, password2) == 0) {
    return 1;
  }
  return 0;
}

// Function to save a password to a file
void savePassword(Password *password) {
  FILE *fp;
  fp = fopen("passwords.txt", "a");
  fprintf(fp, "%s:%s\n", password->username, password->password);
  fclose(fp);
}

// Function to load a password from a file
Password *loadPassword(char *username) {
  FILE *fp;
  Password *password = (Password *)malloc(sizeof(Password));
  fp = fopen("passwords.txt", "r");
  while (fscanf(fp, "%s:%s\n", password->username, password->password) != EOF) {
    if (strcmp(password->username, username) == 0) {
      break;
    }
  }
  fclose(fp);
  return password;
}

// Main function
int main() {
  // Create a new password
  Password *password = (Password *)malloc(sizeof(Password));
  password->username = "john.doe";
  generatePassword(password->password, MAX_PASSWORD_LENGTH);
  savePassword(password);

  // Load the password
  Password *loadedPassword = loadPassword("john.doe");

  // Check if the passwords match
  int match = checkPassword(password->password, loadedPassword->password);
  if (match) {
    printf("The passwords match.\n");
  } else {
    printf("The passwords do not match.\n");
  }

  // Free the memory
  free(password);
  free(loadedPassword);

  return 0;
}