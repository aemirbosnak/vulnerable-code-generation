//GEMINI-pro DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
  // Welcome to a simulation of the SysAdmin's Realm:
  printf("Prepare to embark on an immersive system administration adventure! Brace yourself for an arcane world of commands, processes, and pixelated prowess...\n");

  // Begin with a blank canvas - a pristine system:
  printf("Type 'new' to create your virtual system. Once ready, execute 'run' to commence:\n");

  // Wait for user to create and start the system:
  char command[10];
  while (1) {
    scanf("%s", command);
    if (!strcmp(command, "new")) {
      printf("System initialized! Type 'ls' to list processes or 'ps' to see running programs.\n");
      break;
    } else if (!strcmp(command, "run")) {
      printf("System running! Now navigating the labyrinth of processes...\n");
      break;
    } else {
      printf("Unrecognized command. Please enter 'new' or 'run'.\n");
    }
  }

  // Main operational loop:
  while (1) {
    printf("\nEnter a command (ls, ps, kill, exit):\n");
    scanf("%s", command);

    if (!strcmp(command, "ls")) {
      // List processes:
      system("ps -ef");

    } else if (!strcmp(command, "ps")) {
      // Show running programs:
      system("ps -aux");

    } else if (!strcmp(command, "kill")) {
      // Terminate a process:
      int pid;
      printf("Enter PID to terminate: ");
      scanf("%d", &pid);
      kill(pid, SIGTERM);

    } else if (!strcmp(command, "exit")) {
      // Exit the simulation:
      printf("Exiting the SysAdmin's Realm. Farewell, brave admin!\n");
      break;

    } else {
      // Invalid command:
      printf("Unrecognized command. Try 'ls', 'ps', 'kill', or 'exit'.\n");
    }
  }

  return 0;
}