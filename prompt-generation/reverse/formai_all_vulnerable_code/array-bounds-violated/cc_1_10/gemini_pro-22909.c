//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// A simple shell program that can execute commands

// The main function
int main() {
  // The command buffer
  char buffer[1024];

  // The current working directory
  char cwd[1024];

  // The prompt
  const char *prompt = "myshell> ";

  // The main loop
  while (1) {
    // Display the prompt
    printf("%s", prompt);

    // Read the command from the user
    fgets(buffer, sizeof(buffer), stdin);

    // Remove the newline character from the buffer
    buffer[strlen(buffer) - 1] = '\0';

    // If the user entered an empty command, continue to the next iteration of the loop
    if (strcmp(buffer, "") == 0) {
      continue;
    }

    // If the user entered the "exit" command, exit the shell
    if (strcmp(buffer, "exit") == 0) {
      break;
    }

    // If the user entered the "cd" command, change the current working directory
    if (strncmp(buffer, "cd", 2) == 0) {
      // Get the new directory name
      char *new_dir = buffer + 3;

      // Change the current working directory
      if (chdir(new_dir) != 0) {
        printf("Error: could not change directory to %s\n", new_dir);
      }

      // Continue to the next iteration of the loop
      continue;
    }

    // Fork a child process
    pid_t pid = fork();

    // If the fork failed, print an error message and exit the shell
    if (pid == -1) {
      printf("Error: could not fork child process\n");
      exit(1);
    }

    // If the child process is the child, execute the command
    if (pid == 0) {
      // Execute the command
      if (execlp(buffer, buffer, NULL) == -1) {
        printf("Error: could not execute command %s\n", buffer);
        exit(1);
      }
    }

    // If the child process is the parent, wait for the child process to finish
    if (pid > 0) {
      int status;
      waitpid(pid, &status, 0);
    }
  }

  // Exit the shell
  return 0;
}