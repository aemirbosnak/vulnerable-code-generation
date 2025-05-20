//GEMINI-pro DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct {
  char *password;
  int length;
} Password;

// Define the array of passwords
Password passwords[NUM_PASSWORDS];

// Get a password from the user
char *get_password() {
  char *password;
  char ch;
  int i = 0;

  // Allocate memory for the password
  password = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));
  if (password == NULL) {
    fprintf(stderr, "Error allocating memory for password\n");
    exit(1);
  }

  // Get the password from the user
  printf("Enter a password: ");
  while ((ch = getchar()) != '\n') {
    if (i < MAX_PASSWORD_LENGTH) {
      password[i++] = ch;
    }
  }

  // Null-terminate the password
  password[i] = '\0';

  // Return the password
  return password;
}

// Store a password in the array of passwords
void store_password(char *password) {
  int i;

  // Find an empty slot in the array of passwords
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].password == NULL) {
      break;
    }
  }

  // If there is no empty slot, exit the program
  if (i == NUM_PASSWORDS) {
    fprintf(stderr, "Error: no more slots available in the array of passwords\n");
    exit(1);
  }

  // Store the password in the array of passwords
  passwords[i].password = password;
  passwords[i].length = strlen(password);
}

// Get a password from the array of passwords
char *get_password_by_index(int index) {
  // Check if the index is valid
  if (index < 0 || index >= NUM_PASSWORDS) {
    fprintf(stderr, "Error: invalid index\n");
    exit(1);
  }

  // Return the password
  return passwords[index].password;
}

// Print the passwords in the array of passwords
void print_passwords() {
  int i;

  // Print the passwords
  for (i = 0; i < NUM_PASSWORDS; i++) {
    if (passwords[i].password != NULL) {
      printf("Password %d: %s\n", i + 1, passwords[i].password);
    }
  }
}

// Main function
int main() {
  int choice;
  char *password;

  // Get the user's choice
  do {
    printf("1. Store a password\n");
    printf("2. Get a password\n");
    printf("3. Print the passwords\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
  } while (choice < 1 || choice > 4);

  // Perform the user's choice
  switch (choice) {
    case 1:
      password = get_password();
      store_password(password);
      break;
    case 2:
      password = get_password_by_index(0);
      printf("Password: %s\n", password);
      break;
    case 3:
      print_passwords();
      break;
    case 4:
      exit(0);
  }

  return 0;
}