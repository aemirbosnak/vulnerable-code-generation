//FormAI DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char cmd[50];
  printf("Welcome to the System Administration Program\n");

  while(1) {
    printf("\nEnter a command (type 'help' for a list of commands): ");
    scanf("%s", cmd);

    // Exit Program
    if(strcmp(cmd, "quit") == 0) {
      printf("Exiting program...\n");
      exit(0);
    }
    // Display Commands
    else if(strcmp(cmd, "help") == 0) {
      printf("Here is a list of commands:\n");
      printf("  help - display this list of commands\n");
      printf("  clear - clear the terminal screen\n");
      printf("  reboot - reboot the system\n");
      printf("  shutdown - shutdown the system\n");
    }
    // Clear Terminal Screen
    else if(strcmp(cmd, "clear") == 0) {
      system("clear");
      printf("Terminal screen cleared\n");
    }
    // Reboot System
    else if(strcmp(cmd, "reboot") == 0) {
      printf("Are you sure you want to reboot the system? (y/n): ");
      char response[1];
      scanf("%s", response);
      if(response[0] == 'y') {
        system("reboot");
      }
      printf("System not rebooted\n");
    }
    // Shutdown System
    else if(strcmp(cmd, "shutdown") == 0) {
      printf("Are you sure you want to shutdown the system? (y/n): ");
      char response[1];
      scanf("%s", response);
      if(response[0] == 'y') {
        system("shutdown -h now");
      }
      printf("System not shutdown\n");
    }
    // Invalid Command
    else {
      printf("Invalid command\n");
    }
  }

  return 0;
}