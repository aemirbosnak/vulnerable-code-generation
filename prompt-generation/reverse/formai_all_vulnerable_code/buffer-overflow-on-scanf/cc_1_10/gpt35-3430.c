//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100  // maximum number of passwords that can be stored
#define MAX_LENGTH 20      // maximum length of password string
#define MASTER_PASS "password123"  // master password to access the password manager

// function declarations
void print_menu();
void add_password(char passwords[MAX_PASSWORDS][MAX_LENGTH], int *count);
void view_passwords(char passwords[MAX_PASSWORDS][MAX_LENGTH], int count);

int main() {
  char passwords[MAX_PASSWORDS][MAX_LENGTH];  // array to store passwords
  int count = 0;  // number of passwords stored
  char master_password[MAX_LENGTH];  // variable to store user input for master password

  printf("Welcome to the Password Manager!\n");
  
  // ask user for master password
  printf("Please enter the master password to access your saved passwords: ");
  scanf("%s", master_password);
  
  // check if master password is correct
  if (strcmp(master_password, MASTER_PASS) != 0) {
    printf("Sorry, the password is incorrect. Goodbye.\n");
    exit(EXIT_FAILURE);  // quit program if master password is incorrect
  }
  
  // print menu and prompt user for action
  while (1) {
    print_menu();
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // discard newline character from input buffer
  
    switch (choice) {
      case 1:
        add_password(passwords, &count);
        break;
      case 2:
        view_passwords(passwords, count);
        break;
      case 3:
        printf("Goodbye!\n");
        exit(EXIT_SUCCESS);
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  }
  
  return 0;
}

// print menu of password manager options
void print_menu() {
  printf("\n1. Add a new password\n");
  printf("2. View saved passwords\n");
  printf("3. Quit\n");
}

// function to add a new password
void add_password(char passwords[MAX_PASSWORDS][MAX_LENGTH], int *count) {
  char password[MAX_LENGTH];  // variable to store user input for password
  char confirm[MAX_LENGTH];  // variable to store user input for password confirmation
  int i;
  
  printf("Enter the new password (maximum length of 20 characters): ");
  fgets(password, MAX_LENGTH, stdin);
  password[strcspn(password, "\n")] = '\0';  // remove newline character added by fgets
  
  // check if password meets minimum requirements
  if (strlen(password) < 8) {
    printf("Password must be at least 8 characters.\n");
    return;
  }
  
  int has_uppercase = 0;
  int has_lowercase = 0;
  int has_number = 0;
  int has_special = 0;
  
  for (i = 0; password[i] != '\0'; i++) {
    if (isupper(password[i])) {
      has_uppercase = 1;
    }
    else if (islower(password[i])) {
      has_lowercase = 1;
    }
    else if (isdigit(password[i])) {
      has_number = 1;
    }
    else if (ispunct(password[i])) {
      has_special = 1;
    }
  }
  
  if (!has_uppercase || !has_lowercase || !has_number || !has_special) {
    printf("Password must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
    return;
  }
  
  // ask user to confirm new password
  printf("Confirm the new password: ");
  fgets(confirm, MAX_LENGTH, stdin);
  confirm[strcspn(confirm, "\n")] = '\0';
  
  // check if confirmation matches new password
  if (strcmp(password, confirm) != 0) {
    printf("Passwords do not match. Please try again.\n");
    return;
  }
  
  // check if maximum number of passwords has been reached
  if (*count >= MAX_PASSWORDS) {
    printf("Maximum number of passwords reached. Please delete a password before adding a new one.\n");
    return;
  }
  
  // add new password to array
  strcpy(passwords[*count], password);
  (*count)++;
  
  printf("Password added successfully!\n");
}

// function to view all saved passwords
void view_passwords(char passwords[MAX_PASSWORDS][MAX_LENGTH], int count) {
  int i;
  
  if (count == 0) {
    printf("No passwords saved.\n");
    return;
  }
  
  printf("Here are all of your saved passwords:\n");
  
  for (i = 0; i < count; i++) {
    printf("%s\n", passwords[i]);
  }
}