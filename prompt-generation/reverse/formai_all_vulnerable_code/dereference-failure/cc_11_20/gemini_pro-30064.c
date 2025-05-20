//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the maximum number of arguments that a command can have
#define MAX_ARGS 10

// Define the maximum length of a command line
#define MAX_LINE_LENGTH 100

// Define the maximum number of commands that can be stored in history
#define MAX_HISTORY_SIZE 10

// Define the history file name
#define HISTORY_FILE ".history"

// Define the prompt string
#define PROMPT "unix$ "

// Declare the history array
char *history[MAX_HISTORY_SIZE];

// Declare the current history index
int history_index = 0;

// Declare the current working directory
char cwd[MAX_LINE_LENGTH];

// Main function
int main() {
  // Get the current working directory
  getcwd(cwd, sizeof(cwd));

  // Print the prompt
  printf("%s", PROMPT);

  // Read the command line
  char line[MAX_LINE_LENGTH];
  fgets(line, sizeof(line), stdin);

  // Parse the command line into arguments
  char *args[MAX_ARGS];
  int argc = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    args[argc++] = token;
    token = strtok(NULL, " ");
  }

  // Check if the command is a built-in command
  if (strcmp(args[0], "cd") == 0) {
    // Change the current working directory
    if (argc == 1) {
      chdir(getenv("HOME"));
    } else {
      chdir(args[1]);
    }
  } else if (strcmp(args[0], "history") == 0) {
    // Print the history of commands
    for (int i = 0; i < history_index; i++) {
      printf("%s\n", history[i]);
    }
  } else if (strcmp(args[0], "exit") == 0) {
    // Exit the shell
    exit(0);
  } else {
    // Fork a new process to execute the command
    pid_t pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else if (pid > 0) {
      // Parent process
      int status;
      waitpid(pid, &status, 0);
    } else {
      // Error
      perror("fork");
    }
  }

  // Add the command to the history
  history[history_index++] = strdup(line);

  // Print the prompt again
  printf("%s", PROMPT);

  // Repeat the loop until the user enters the "exit" command
  while (strcmp(args[0], "exit") != 0) {
    // Read the command line
    fgets(line, sizeof(line), stdin);

    // Parse the command line into arguments
    argc = 0;
    token = strtok(line, " ");
    while (token != NULL) {
      args[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Check if the command is a built-in command
    if (strcmp(args[0], "cd") == 0) {
      // Change the current working directory
      if (argc == 1) {
        chdir(getenv("HOME"));
      } else {
        chdir(args[1]);
      }
    } else if (strcmp(args[0], "history") == 0) {
      // Print the history of commands
      for (int i = 0; i < history_index; i++) {
        printf("%s\n", history[i]);
      }
    } else if (strcmp(args[0], "exit") == 0) {
      // Exit the shell
      exit(0);
    } else {
      // Fork a new process to execute the command
      pid_t pid = fork();
      if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(1);
      } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
      } else {
        // Error
        perror("fork");
      }
    }

    // Add the command to the history
    history[history_index++] = strdup(line);

    // Print the prompt again
    printf("%s", PROMPT);
  }

  // Free the history array
  for (int i = 0; i < history_index; i++) {
    free(history[i]);
  }

  return 0;
}