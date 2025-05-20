//GEMINI-pro DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct password {
  char *name;
  char *password;
} password_t;

// Create an array of passwords
password_t passwords[NUM_PASSWORDS];

// Get a password from the user
void get_password(char *name, char *password) {
  printf("Enter the name of the password: ");
  scanf("%s", name);
  printf("Enter the password: ");
  scanf("%s", password);
}

// Store a password in the array
void store_password(char *name, char *password) {
  int i;
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].name == NULL) {
      passwords[i].name = strdup(name);
      passwords[i].password = strdup(password);
      break;
    }
  }
}

// Print the passwords
void print_passwords() {
  int i;
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].name != NULL) {
      printf("Password %d:\n", i);
      printf("Name: %s\n", passwords[i].name);
      printf("Password: %s\n", passwords[i].password);
    }
  }
}

// Free the memory allocated for the passwords
void free_passwords() {
  int i;
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].name != NULL) {
      free(passwords[i].name);
      passwords[i].name = NULL;
      free(passwords[i].password);
      passwords[i].password = NULL;
    }
  }
}

// Main function
int main() {
  int choice;
  char name[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  do {
    printf("1. Get password\n");
    printf("2. Store password\n");
    printf("3. Print passwords\n");
    printf("4. Free passwords\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        get_password(name, password);
        break;
      case 2:
        store_password(name, password);
        break;
      case 3:
        print_passwords();
        break;
      case 4:
        free_passwords();
        break;
      case 5:
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}