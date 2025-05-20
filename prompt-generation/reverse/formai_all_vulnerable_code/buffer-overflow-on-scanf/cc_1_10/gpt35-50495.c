//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>

int main() {
  printf("Surprise! Welcome to the Sysadmin Portal");
  printf("\n");

  printf("Please input your server name: ");
  char server_name[100];
  scanf("%s", server_name);

  printf("Please input your administrator username: ");
  char username[100];
  scanf("%s", username);

  printf("\n");

  printf("System loading...\n");
  printf("Initializing authentication...\n");

  printf("\n");

  printf("You've been granted superuser access to %s as %s!\n", server_name, username);

  int option;
  printf("What would you like to do?\n\n");
  printf("1. Check server status\n");
  printf("2. Perform system updates\n");
  printf("3. View logs\n");
  printf("4. Exit\n");
  scanf("%d", &option);

  switch(option) {
    case 1:
      printf("\n");
      printf("Checking server status...\n");
      printf("Server is up and running!\n");
      break;

    case 2:
      printf("\n");
      printf("Initializing system update...\n");
      printf("System update complete!\n");
      break;

    case 3:
      printf("\n");
      printf("Opening log file...\n");
      printf("File not found. But don't worry, we've got backups!\n");
      break;

    case 4:
      printf("\n");
      printf("Exiting Sysadmin Portal. Thank you for using our services!\n");
      return 0;

    default:
      printf("\n");
      printf("Invalid option selected. Please try again.\n");
      break;
  }

  return 0;
}