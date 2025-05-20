//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Define some funny colors for our shell
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define the maximum length of a command
#define MAX_CMD_LENGTH 1024

// Define the maximum number of arguments in a command
#define MAX_ARGS 32

// Define the maximum number of commands in a pipeline
#define MAX_PIPES 10

// Define the shell prompt
#define PROMPT "LOL Shell> "

// Define the shell's built-in commands
char *builtin_cmds[] = {"exit", "cd", "ls", "pwd", "echo", "help"};

// Define the shell's help message
char *help_msg = 
"LOL Shell\n"
"A simple, yet powerful Unix-like shell.\n"
"Commands:\n"
"  exit: Exit the shell.\n"
"  cd: Change the current working directory.\n"
"  ls: List the files in the current working directory.\n"
"  pwd: Print the current working directory.\n"
"  echo: Print a message to the console.\n"
"  help: Display this help message.\n";

// Main function
int main() {
  // Set up the shell's environment
  char *env[] = {"PATH=/bin:/usr/bin", NULL};

  // Main loop
  while (1) {
    // Print the shell prompt
    printf(GREEN "%s " WHITE, PROMPT);

    // Read the user's input
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);

    // Parse the user's input
    char *args[MAX_ARGS];
    int num_args = 0;
    char *cmd = strtok(line, " ");
    while (cmd != NULL) {
      args[num_args++] = cmd;
      cmd = strtok(NULL, " ");
    }

    // Check if the user entered a built-in command
    int is_builtin = 0;
    for (int i = 0; i < sizeof(builtin_cmds) / sizeof(char *); i++) {
      if (strcmp(args[0], builtin_cmds[i]) == 0) {
        is_builtin = 1;
        break;
      }
    }

    // Execute the command
    if (is_builtin) {
      // Built-in command
      switch (num_args) {
        case 1:
          if (strcmp(args[0], "exit") == 0) {
            exit(0);
          } else if (strcmp(args[0], "cd") == 0) {
            chdir(getenv("HOME"));
          } else if (strcmp(args[0], "ls") == 0) {
            system("ls");
          } else if (strcmp(args[0], "pwd") == 0) {
            system("pwd");
          } else if (strcmp(args[0], "echo") == 0) {
            printf("%s\n", args[1]);
          } else if (strcmp(args[0], "help") == 0) {
            printf("%s", help_msg);
          }
          break;
        case 2:
          if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
          } else if (strcmp(args[0], "echo") == 0) {
            printf("%s %s\n", args[1], args[2]);
          }
          break;
        default:
          printf("Invalid number of arguments for built-in command.\n");
          break;
      }
    } else {
      // External command
      pid_t pid = fork();
      if (pid == 0) {
        // Child process
        execve(args[0], args, env);
        printf("Error: execve failed.\n");
        exit(1);
      } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
      }
    }

    // Free the user's input
    free(line);
  }

  return 0;
}