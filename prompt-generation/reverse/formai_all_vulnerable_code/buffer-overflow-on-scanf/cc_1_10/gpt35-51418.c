//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>

int main() {
  int num_servers = 5;
  int num_admins = 3;

  printf("Welcome to the Best Server Admin Program Ever!\n");

  printf("Currently managing %d servers and %d admins.\n", num_servers, num_admins);

  printf("What would you like to do today?\n");
  printf("1. Add a server\n");
  printf("2. Remove a server\n");
  printf("3. Add an admin\n");
  printf("4. Remove an admin\n");
  printf("5. Get the status of all servers\n");
  printf("6. Get the status of all admins\n");
  printf("7. Quit\n");

  int choice;
  scanf("%d", &choice);

  while (choice != 7) {
    switch (choice) {
      case 1:
        num_servers++;
        printf("Server Added! Total Servers now: %d\n", num_servers);
        break;
      case 2:
        num_servers--;
        printf("Server Removed! Total Servers now: %d\n", num_servers);
        break;
      case 3:
        num_admins++;
        printf("Admin Added! Total Admins now: %d\n", num_admins);
        break;
      case 4:
        num_admins--;
        printf("Admin Removed! Total Admins now: %d\n", num_admins);
        break;
      case 5:
        printf("Status of all servers\n");
        for (int i = 0; i < num_servers; i++) {
          printf("Server %d: Online\n", i+1);
        }
        break;
      case 6:
        printf("Status of all admins\n");
        for (int i = 0; i < num_admins; i++) {
          printf("Admin %d: Frazzled\n", i+1);
        }
        break;
      default:
        printf("Invalid selection!\n");
        break;
    }

    printf("What would you like to do next?\n");
    printf("1. Add a server\n");
    printf("2. Remove a server\n");
    printf("3. Add an admin\n");
    printf("4. Remove an admin\n");
    printf("5. Get the status of all servers\n");
    printf("6. Get the status of all admins\n");
    printf("7. Quit\n");

    scanf("%d", &choice);
  }

  printf("Goodbye! Thank you for using the Best Server Admin Program Ever!\n");

  return 0;
}