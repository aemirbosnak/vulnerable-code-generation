//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
  char site[30];
  char username[20];
  char password[MAX_PASSWORD_LENGTH + 1];
} PasswordEntry;

int main(void) {
  PasswordEntry passwordList[MAX_PASSWORDS];
  int numPasswords = 0;
  
  printf("Welcome to your personal password manager!\n");
  printf("Please choose an option:\n");
  printf("1. Add a new password\n");
  printf("2. View all saved passwords\n");
  printf("3. Delete a password\n");
  printf("4. Exit\n");
  printf("\nYour choice: ");
  
  int choice;
  scanf("%d", &choice);
  
  while (choice != 4) {
    switch (choice) {
      case 1:
        if (numPasswords == MAX_PASSWORDS) {
          printf("\nSorry, your password vault is full! You need to upgrade to Platinum Edition for unlimited password storage.\n");
          printf("Please choose an option: ");
          scanf("%d", &choice);
          continue;
        }
        printf("Please enter the site name: ");
        scanf("%s", passwordList[numPasswords].site);
        printf("Please enter your username: ");
        scanf("%s", passwordList[numPasswords].username);
        printf("Please enter your password (max length %d): ", MAX_PASSWORD_LENGTH);
        scanf("%s", passwordList[numPasswords].password);
        numPasswords++;
        break;
        
      case 2:
        if (numPasswords == 0) {
          printf("\nYou have no saved passwords, what have you been doing all day?\n");
          printf("Please choose an option: ");
          scanf("%d", &choice);
          continue;
        }
        printf("\nYour stored passwords:\n");
        for (int i = 0; i < numPasswords; i++) {
          printf("Site: %s\n", passwordList[i].site);
          printf("Username: %s\n", passwordList[i].username);
          printf("Password: %s\n", passwordList[i].password);
          printf("\n");
        }
        printf("Please choose an option: ");
        scanf("%d", &choice);
        break;
        
      case 3:
        if (numPasswords == 0) {
          printf("\nYou have no passwords to delete! Quit playing around...\n");
          printf("Please choose an option: ");
          scanf("%d", &choice);
          continue;
        }
        printf("\nPlease enter the site name of the password to delete: ");
        char siteToDelete[30];
        scanf("%s", siteToDelete);
        int passwordDeleted = 0;
        for (int i = 0; i < numPasswords; i++) {
          if (strcmp(siteToDelete, passwordList[i].site) == 0) {
            printf("Password deleted successfully. Deleting memories!\n");
            strncpy(passwordList[i].site, "", 1);
            strncpy(passwordList[i].username, "", 1);
            strncpy(passwordList[i].password, "", 1);
            numPasswords--;
            passwordDeleted = 1;
            break;
          }
        }
        if (!passwordDeleted) {
          printf("\nSorry, no password found for site: %s\n", siteToDelete);
        }
        printf("Please choose an option: ");
        scanf("%d", &choice);
        break;
        
      default:
        printf("\nYou must enter a number from 1 to 4, smarty-pants!\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        break;
    }
  }
  
  printf("Saving your passwords...\n");
  printf("Exiting your personal password manager. Thank you for trusting us with your most important secrets.\n");
  
  return 0;
}