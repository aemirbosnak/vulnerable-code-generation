//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// Defines the maximum length of a command line
#define MAX_LINE_LENGTH 1024

// Defines the maximum number of arguments in a command line
#define MAX_ARGS 32

// Parse the command line into an array of arguments
int parse_args(char *line, char **args) {
  int i = 0;
  char *token;

  // Split the line into tokens using strtok()
  token = strtok(line, " ");
  while (token != NULL) {
    // Store the token in the args array
    args[i] = token;
    i++;

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Terminate the args array with a NULL pointer
  args[i] = NULL;

  // Return the number of arguments
  return i;
}

// Execute the command
int execute_command(char **args) {
  // Create a child process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return -1;
  }

  // Child process
  if (pid == 0) {
    // Execute the command
    execvp(args[0], args);

    // If execvp() returns, it means that the command was not found
    perror("execvp");
    exit(1);
  }

  // Parent process
  else {
    // Wait for the child process to finish
    int status;
    wait(&status);

    // Check the exit status of the child process
    if (WIFEXITED(status)) {
      // The child process exited normally
      return WEXITSTATUS(status);
    } else {
      // The child process exited abnormally
      return -1;
    }
  }
}

// Main loop
int main() {
  // Declare the command line buffer
  char line[MAX_LINE_LENGTH];

  // Declare the argument array
  char *args[MAX_ARGS];

  // Run the main loop
  while (1) {
    // Print the prompt
    printf("shell> ");

    // Read the command line
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Parse the command line into an array of arguments
    int num_args = parse_args(line, args);

    // Execute the command
    int status = execute_command(args);

    // Check the exit status of the command
    if (status == -1) {
      perror("execute_command");
    }
  }

  // Return 0
  return 0;
}