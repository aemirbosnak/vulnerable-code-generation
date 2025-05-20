//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// A snazzy header to welcome the user
void banner() {
  printf("\n##############################################################################\n");
  printf("##############################################################################\n");
  printf("######################      Eternal Process Viewer 0.1     ######################\n");
  printf("######################       By: The Code Navigator         ######################\n");
  printf("##############################################################################\n");
  printf("##############################################################################\n\n");
}

// Display process information in an organized and stylish manner
void displayProcesses() {
  // Fetch process information using system commands
  FILE *fp = popen("ps -aux | tail -n +2", "r");
  if (fp == NULL) {
    perror("Error: Unable to fetch process information");
    exit(1);
  }

  // Create headers for the information table
  printf("%-7s %-15s %-25s %-15s %-12s %-15s\n", "PID", "USER", "COMMAND", "STATUS", "TIME", "CPU%");

  // Parse and display process details
  char line[256];
  while (fgets(line, sizeof(line), fp)) {
    char pid[8], user[16], command[26], status[10], time[10], cpu[10];
    sscanf(line, "%s %s %s %s %s %s", pid, user, command, status, time, cpu);
    printf("%-7s %-15s %-25s %-15s %-12s %-15s\n", pid, user, command, status, time, cpu);
  }

  // Close the file stream
  pclose(fp);
}

// Handle user input and provide options
void userInput() {
  int choice;

  while (1) {
    printf("------------------------------------------------------------------------------\n");
    printf("1. View Running Processes\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        displayProcesses();
        break;
      case 2:
        printf("Exiting... Thank you for using Eternal Process Viewer!\n");
        exit(0);
      default:
        printf("Invalid choice. Please select a valid option.\n");
    }
  }
}

// The main function where the party starts
int main() {
  banner();
  userInput();

  return 0;
}