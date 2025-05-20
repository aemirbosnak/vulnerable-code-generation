//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the System Administration Example Program!\n");

  // Prompt user for input
  printf("Please enter your name: ");
  char name[20];
  scanf("%s", name);

  printf("Hi %s, what would you like to do?\n", name);

  int choice;
  do {
    // Display options
    printf("1. View system information\n");
    printf("2. Manage users\n");
    printf("3. Manage processes\n");
    printf("4. Exit\n");

    // Prompt user for choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("System Information:\n");
        system("uname -a"); // Run system command to display system information
        break;
      case 2:
        printf("User Management:\n");
        system("sudo useradd -m newuser"); // Run system command to add a new user
        printf("New user added successfully!\n");
        break;
      case 3:
        printf("Process Management:\n");
        system("ps -ef"); // Run system command to display running processes
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while(choice != 4);

  printf("Thank you for using the System Administration Example Program.\n");

  return 0;
}