//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  printf("Welcome to Happy Admin v1.0!\n");
  printf("This program is designed to make system administration a joyful task!\n");

  // Display menu options
  printf("\n========== MENU ==========\n");
  printf("1. Create new user\n");
  printf("2. Delete user\n");
  printf("3. View all users\n");
  printf("4. System update\n");
  printf("5. Exit\n");

  int choice;
  printf("\nEnter your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      printf("\nCreating new user...\n");
      char username[50], password[50];
      printf("Username: ");
      scanf("%s", username);
      printf("Password: ");
      scanf("%s", password);
      // Add user to system
      printf("%s has been added as a new user! :)\n", username);
      break;

    case 2:
      printf("\nDeleting user...\n");
      char user[50];
      printf("Username: ");
      scanf("%s", user);
      // Delete user from system
      printf("%s has been deleted from system! :)\n", user);
      break;

    case 3:
      printf("\nViewing all users...\n");
      // Display all users on system
      printf("Users on system:\n");
      printf("User1\nUser2\nUser3\n");
      printf("Have a happy day! :)\n");
      break;

    case 4:
      printf("\nRunning system update...\n");
      // Perform system update
      printf("System has been updated! :)\n");
      break;

    case 5:
      printf("\nExiting program...\n");
      exit(0);

    default:
      printf("\nInvalid choice! Please try again :)\n");
  }

  return 0;
}