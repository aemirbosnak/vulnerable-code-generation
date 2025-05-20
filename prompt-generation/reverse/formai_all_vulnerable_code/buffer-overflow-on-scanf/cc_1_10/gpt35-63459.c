//FormAI DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

  char *username = ""; // initialize empty username
  char *password = ""; // initialize empty password
  int attempts = 0; // track login attempts
  int max_attempts = 3; // maximum attempts before program exits

  // prompt for username and password
  while (1) {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // check if username and password are correct
    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
      printf("Login successful.\n");
      break;
    } else {
      attempts++;
      if (attempts == max_attempts) {
        printf("Maximum login attempts exceeded. Program exiting.\n");
        exit(EXIT_FAILURE);
      }
      printf("Login failed. Please try again.\n");
    }
  }

  // execute system commands
  while (1) {
    char command[100];
    printf("Enter command [exit to quit]: ");
    scanf("%s", command);

    // exit program if user enters 'exit'
    if (strcmp(command, "exit") == 0) {
      printf("Program exiting.\n");
      exit(EXIT_SUCCESS);
    }

    // execute system command
    pid_t pid = fork();
    if (pid == -1) {
      printf("Error forking.\n");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // child process
      printf("Executing command: %s\n", command);
      execlp(command, command, NULL);
      printf("Command execution failed.\n"); // execlp() only returns if there is an error
      exit(EXIT_FAILURE);
    } else {
      // parent process
      int status;
      waitpid(pid, &status, 0);
      if (WIFEXITED(status)) {
        printf("Command exited with status: %d\n", WEXITSTATUS(status));
      } else {
        printf("Command exited abnormally.\n");
      }
    }
  }
}