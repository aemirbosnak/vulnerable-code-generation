//GEMINI-pro DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the password manager structure
typedef struct {
  char *website;
  char *username;
  char *password;
} Password;

// Function to create a new password
Password *createPassword(char *website, char *username, char *password) {
  // Allocate memory for the new password
  Password *newPass = malloc(sizeof(Password));

  // Copy the website, username, and password into the new password
  newPass->website = malloc(strlen(website) + 1);
  strcpy(newPass->website, website);
  newPass->username = malloc(strlen(username) + 1);
  strcpy(newPass->username, username);
  newPass->password = malloc(strlen(password) + 1);
  strcpy(newPass->password, password);

  // Return the new password
  return newPass;
}

// Function to delete a password
void deletePassword(Password *pass) {
  // Free the memory allocated for the website, username, and password
  free(pass->website);
  free(pass->username);
  free(pass->password);

  // Free the memory allocated for the password
  free(pass);
}

// Function to print a password
void printPassword(Password *pass) {
  // Print the website, username, and password
  printf("Website: %s\n", pass->website);
  printf("Username: %s\n", pass->username);
  printf("Password: %s\n", pass->password);
}

// Main function
int main() {
  // Create a new password manager
  Password *passManager[100];

  // Get the number of passwords to be stored
  int numPasswords;
  printf("How many passwords would you like to store? ");
  scanf("%d", &numPasswords);

  // Get the details of each password
  for (int i = 0; i < numPasswords; i++) {
    char website[100];
    char username[100];
    char password[100];

    printf("\nEnter the details of password %d:\n", i + 1);
    printf("Website: ");
    scanf("%s", website);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Create a new password and store it in the password manager
    passManager[i] = createPassword(website, username, password);
  }

  // Print the passwords
  printf("\nYour passwords are:\n");
  for (int i = 0; i < numPasswords; i++) {
    printPassword(passManager[i]);
    printf("\n");
  }

  // Delete the passwords
  for (int i = 0; i < numPasswords; i++) {
    deletePassword(passManager[i]);
  }

  return 0;
}