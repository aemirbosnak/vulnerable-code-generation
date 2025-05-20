//GEMINI-pro DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password management functions
int createPassword(char *password);
int verifyPassword(char *password);
void changePassword(char *oldPassword, char *newPassword);

// Main function
int main() {
  // Initialize variables
  char password[50];
  int choice;

  // Welcome message
  printf("Welcome to the Password Manager!\n");

  // Main menu
  while (1) {
    // Display menu
    printf("\nPlease choose an option:\n");
    printf("1. Create a new password\n");
    printf("2. Verify a password\n");
    printf("3. Change a password\n");
    printf("4. Exit\n");

    // Get user input
    printf("Choice: ");
    scanf("%d", &choice);

    // Handle user input
    switch (choice) {
      case 1:
        // Create a new password
        if (createPassword(password)) {
          printf("Password created successfully!\n");
        } else {
          printf("Error creating password. Please try again.\n");
        }
        break;
      case 2:
        // Verify a password
        if (verifyPassword(password)) {
          printf("Password verified successfully!\n");
        } else {
          printf("Password verification failed. Please try again.\n");
        }
        break;
      case 3:
        // Change a password
        changePassword(password, password);
        break;
      case 4:
        // Exit the program
        printf("Exiting the Password Manager. Goodbye!\n");
        exit(0);
      default:
        // Invalid input
        printf("Invalid choice. Please enter a valid option.\n");
    }
  }

  return 0;
}

// Create a new password
int createPassword(char *password) {
  // Get the password from the user
  printf("Enter a new password: ");
  scanf("%s", password);

  // Check the password strength
  if (strlen(password) < 8) {
    printf("Password must be at least 8 characters long.\n");
    return 0;
  }

  if (!strchr(password, '!') && !strchr(password, '@') && !strchr(password, '#') && !strchr(password, '$') && !strchr(password, '%') && !strchr(password, '^') && !strchr(password, '&') && !strchr(password, '*')) {
    printf("Password must contain at least one special character (!, @, #, $, %, ^, &, *).\n");
    return 0;
  }

  if (!strchr(password, '0') && !strchr(password, '1') && !strchr(password, '2') && !strchr(password, '3') && !strchr(password, '4') && !strchr(password, '5') && !strchr(password, '6') && !strchr(password, '7') && !strchr(password, '8') && !strchr(password, '9')) {
    printf("Password must contain at least one digit (0-9).\n");
    return 0;
  }

  // The password is strong enough
  return 1;
}

// Verify a password
int verifyPassword(char *password) {
  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);

  // Check the password strength
  if (strlen(password) < 8) {
    printf("Password must be at least 8 characters long.\n");
    return 0;
  }

  if (!strchr(password, '!') && !strchr(password, '@') && !strchr(password, '#') && !strchr(password, '$') && !strchr(password, '%') && !strchr(password, '^') && !strchr(password, '&') && !strchr(password, '*')) {
    printf("Password must contain at least one special character (!, @, #, $, %, ^, &, *).\n");
    return 0;
  }

  if (!strchr(password, '0') && !strchr(password, '1') && !strchr(password, '2') && !strchr(password, '3') && !strchr(password, '4') && !strchr(password, '5') && !strchr(password, '6') && !strchr(password, '7') && !strchr(password, '8') && !strchr(password, '9')) {
    printf("Password must contain at least one digit (0-9).\n");
    return 0;
  }

  // The password is strong enough
  return 1;
}

// Change a password
void changePassword(char *oldPassword, char *newPassword) {
  // Get the old and new passwords from the user
  printf("Enter your old password: ");
  scanf("%s", oldPassword);

  printf("Enter your new password: ");
  scanf("%s", newPassword);

  // Check if the old password is correct
  if (!verifyPassword(oldPassword)) {
    printf("Old password is incorrect. Please try again.\n");
    return;
  }

  // Check if the new password is strong enough
  if (!createPassword(newPassword)) {
    printf("New password is not strong enough. Please try again.\n");
    return;
  }

  // The new password is strong enough
  printf("Password changed successfully!\n");
}