//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Password struct */
struct password {
  char website[50];
  char username[50];
  char password[50];
};

/* Global variables */
int num_passwords = 0;
struct password passwords[100];

/* Main function */
int main() {
  printf("Welcome to the Password Manager 3000!\n");
  while (1) {
    /* Menu */
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit\n");

    /* User's choice */
    int choice;
    printf("What would you like to do? ");
    scanf("%d", &choice);
    printf("\n");

    /* Handle the user's choice */
    switch (choice) {
      /* Add a password */
      case 1: {
        printf("Enter the website: ");
        scanf("%s", passwords[num_passwords].website);
        printf("Enter the username: ");
        scanf("%s", passwords[num_passwords].username);
        printf("Enter the password: ");
        scanf("%s", passwords[num_passwords].password);
        printf("Password added!\n\n");
        num_passwords++;
        break;
      }
      /* View passwords */
      case 2: {
        printf("Your passwords:\n");
        for (int i = 0; i < num_passwords; i++) {
          printf("%s %s %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
        printf("\n");
        break;
      }
      /* Delete a password */
      case 3: {
        printf("Which password would you like to delete? Enter the website: ");
        char website[50];
        scanf("%s", website);
        int index = -1;
        for (int i = 0; i < num_passwords; i++) {
          if (strcmp(passwords[i].website, website) == 0) {
            index = i;
            break;
          }
        }
        if (index == -1) {
          printf("Password not found!\n\n");
        } else {
          for (int i = index; i < num_passwords - 1; i++) {
            passwords[i] = passwords[i+1];
          }
          num_passwords--;
          printf("Password deleted!\n\n");
        }
        break;
      }
      /* Exit */
      case 4: {
        printf("Goodbye!\n");
        return 0;
      }
      /* Invalid choice */
      default: {
        printf("Invalid choice.\n\n");
        break;
      }
    }
  }
  return 0;
}