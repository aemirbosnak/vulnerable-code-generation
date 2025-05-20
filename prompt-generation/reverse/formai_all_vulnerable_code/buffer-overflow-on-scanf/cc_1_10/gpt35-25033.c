//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[50]; // store the password here

void changePassword() {
  char currentPassword[50], newPassword[50], confirmPassword[50];

  // ask the user for their current password
  printf("Enter current password: ");
  scanf("%s", currentPassword);

  // check if current password matches the stored password
  if (strcmp(currentPassword, password) == 0) {
    // ask the user for their new password and confirm password
    printf("Enter new password: ");
    scanf("%s", newPassword);

    printf("Confirm new password: ");
    scanf("%s", confirmPassword);

    // check if the new password and confirm password match
    if (strcmp(newPassword, confirmPassword) == 0) {
      // update the stored password
      strcpy(password, newPassword);
      printf("Password successfully updated!\n");
    } else {
      printf("Passwords do not match, please try again.\n");
    }
  } else {
    printf("Incorrect password, please try again.\n");
  }
}

int main() {
  char option;

  // set the initial password
  strcpy(password, "password");

  while (1) {
    // print the menu
    printf("Welcome to Password Manager!\n");
    printf("1. View current password\n");
    printf("2. Change password\n");
    printf("3. Exit\n");
    printf("Enter option: ");

    // get the user's choice
    scanf(" %c", &option);

    switch (option) {
      case '1': // view current password
        printf("Current password: %s\n", password);
        break;
      case '2': // change password
        changePassword();
        break;
      case '3': // exit
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid option, please try again.\n");
    }

    // add some space for readability
    printf("\n");
  }

  return 0;
}