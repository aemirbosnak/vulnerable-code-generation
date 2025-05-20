//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Grateful System Administration Example Program!\n");
  printf("This program will help you manage your system like never before.\n");
  char input[20], command[20];
  int i, pid;

  while(1) {
    printf("Enter a command (help to see available commands): ");
    scanf("%s", input);

    if(strcmp(input, "exit") == 0) {
      printf("Thank you for using the Grateful System Administration Example Program!\n");
      break;
    }
    else if(strcmp(input, "help") == 0) {
      printf("Available commands:\n");
      printf("\ta) process <pid> - get information about a process\n");
      printf("\tb) memusage - get memory usage information\n");
      printf("\tc) diskusage - get disk usage information\n");
      printf("\td) users - get logged in users information\n");
      printf("\te) reboot - reboot the system\n");
      printf("\tf) shutdown - shutdown the system\n");
    }
    else if(strcmp(input, "process") == 0) {
      printf("Enter the process ID: ");
      scanf("%d", &pid);
      sprintf(command, "ps -p %d -o user,pid,ppid,%cpu,%mem,vsz,rss,stat,command", pid);
      system(command);
    }
    else if(strcmp(input, "memusage") == 0) {
      system("free -m");
    }
    else if(strcmp(input, "diskusage") == 0) {
      system("df -h");
    }
    else if(strcmp(input, "users") == 0) {
      system("w");
    }
    else if(strcmp(input, "reboot") == 0) {
      printf("Are you sure you want to reboot the system? (y/n): ");
      scanf("%s", input);
      if(strcmp(input, "y") == 0) {
        system("reboot");
      }
    }
    else if(strcmp(input, "shutdown") == 0) {
      printf("Are you sure you want to shutdown the system? (y/n): ");
      scanf("%s", input);
      if(strcmp(input, "y") == 0) {
        system("shutdown now");
      }
    }
    else {
      printf("Invalid command, type 'help' to see available commands.\n");
    }
  }

  return 0;
}