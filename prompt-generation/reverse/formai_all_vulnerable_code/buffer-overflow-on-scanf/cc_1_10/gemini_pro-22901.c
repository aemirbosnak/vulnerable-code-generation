//GEMINI-pro DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Create a structure to store a password
typedef struct {
  char *password;
  char *website;
} Password;

// Create an array of passwords
Password passwords[NUM_PASSWORDS];

// Get a password from the user
char *get_password(char *prompt) {
  char *password = malloc(MAX_PASSWORD_LENGTH);
  printf("%s", prompt);
  scanf("%s", password);
  return password;
}

// Get a website from the user
char *get_website(char *prompt) {
  char *website = malloc(MAX_PASSWORD_LENGTH);
  printf("%s", prompt);
  scanf("%s", website);
  return website;
}

// Add a password to the array
void add_password(char *password, char *website) {
  for (int i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].password == NULL) {
      passwords[i].password = password;
      passwords[i].website = website;
      break;
    }
  }
}

// Print the passwords
void print_passwords() {
  for (int i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].password != NULL) {
      printf("Website: %s\n", passwords[i].website);
      printf("Password: %s\n", passwords[i].password);
      printf("\n");
    }
  }
}

// Main function
int main() {
  // Get the master password
  char *master_password = get_password("Enter the master password: ");

  // Get the number of passwords to add
  int num_passwords;
  printf("How many passwords do you want to add? ");
  scanf("%d", &num_passwords);

  // Get the passwords and websites
  for (int i = 0; i < num_passwords; i++) {
    char *password = get_password("Enter the password: ");
    char *website = get_website("Enter the website: ");
    add_password(password, website);
  }

  // Print the passwords
  print_passwords();

  return 0;
}