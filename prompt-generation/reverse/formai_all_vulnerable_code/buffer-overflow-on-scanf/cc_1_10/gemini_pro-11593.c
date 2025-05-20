//GEMINI-pro DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password.
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store.
#define NUM_PASSWORDS 10

// Define the password struct.
typedef struct {
  char password[MAX_PASSWORD_LENGTH];
  char website[MAX_PASSWORD_LENGTH];
} Password;

// Create an array of passwords.
Password passwords[NUM_PASSWORDS];

// Get a password from the user.
void get_password(char *password) {
  printf("Enter a password: ");
  scanf("%s", password);
}

// Get a website from the user.
void get_website(char *website) {
  printf("Enter the website for which the password is: ");
  scanf("%s", website);
}

// Save a password to the array.
void save_password(char *password, char *website) {
  // Find an empty slot in the array.
  int i;
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (strlen(passwords[i].password) == 0) {
      break;
    }
  }

  // If there is no empty slot, then overwrite the first password.
  if (i == NUM_PASSWORDS) {
    i = 0;
  }

  // Copy the password and website to the array.
  strcpy(passwords[i].password, password);
  strcpy(passwords[i].website, website);
}

// Print the passwords.
void print_passwords() {
  // Print the header.
  printf("Passwords:\n");

  // Print each password and website.
  int i;
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (strlen(passwords[i].password) > 0) {
      printf("%s: %s\n", passwords[i].website, passwords[i].password);
    }
  }
}

// Main function.
int main() {
  // Get the passwords from the user.
  int i;
  for (i = 0; i < NUM_PASSWORDS; i++) {
    get_password(passwords[i].password);
    get_website(passwords[i].website);
  }

  // Save the passwords to the array.
  for (i = 0; i < NUM_PASSWORDS; i++) {
    save_password(passwords[i].password, passwords[i].website);
  }

  // Print the passwords.
  print_passwords();

  return 0;
}