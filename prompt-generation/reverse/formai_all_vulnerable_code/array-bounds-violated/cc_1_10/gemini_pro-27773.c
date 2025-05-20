//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to execute a command
int execute_command(char *command) {
  // Create a child process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return -1;
  }

  // Child process
  if (pid == 0) {
    // Execute the command
    execlp("/bin/sh", "sh", "-c", command, NULL);
    // If the execlp() call fails, print an error message and exit
    perror("execlp");
    exit(1);
  }

  // Parent process
  else {
    // Wait for the child process to finish
    int status;
    waitpid(pid, &status, 0);

    // Check the exit status of the child process
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else {
      return -1;
    }
  }
}

// Function to get the current working directory
char *get_cwd() {
  // Allocate memory for the current working directory
  char *cwd = malloc(1024);
  if (cwd == NULL) {
    perror("malloc");
    return NULL;
  }

  // Get the current working directory
  if (getcwd(cwd, 1024) == NULL) {
    perror("getcwd");
    free(cwd);
    return NULL;
  }

  // Return the current working directory
  return cwd;
}

// Function to print the prompt
void print_prompt() {
  // Get the current working directory
  char *cwd = get_cwd();
  if (cwd == NULL) {
    perror("get_cwd");
    return;
  }

  // Print the prompt
  printf("%s$ ", cwd);

  // Free the memory allocated for the current working directory
  free(cwd);
}

// Main function
int main() {
  // Main loop
  while (1) {
    // Print the prompt
    print_prompt();

    // Get the command from the user
    char command[1024];
    fgets(command, 1024, stdin);

    // Remove the newline character from the command
    command[strlen(command) - 1] = '\0';

    // If the command is empty, continue to the next iteration of the loop
    if (strcmp(command, "") == 0) {
      continue;
    }

    // If the command is "exit", break out of the loop and exit the program
    if (strcmp(command, "exit") == 0) {
      break;
    }

    // Execute the command
    int status = execute_command(command);
    if (status == -1) {
      perror("execute_command");
      continue;
    }
  }

  return 0;
}