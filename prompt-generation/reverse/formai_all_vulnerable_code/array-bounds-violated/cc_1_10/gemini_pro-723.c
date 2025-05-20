//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

char *prompt = "myshell>";

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int pid;
  int status;

  while (1) {
    printf("%s ", prompt);
    fgets(line, MAX_LINE_LENGTH, stdin);

    if (feof(stdin)) {
      printf("\n");
      break;
    }

    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';  // Remove the newline character
    }

    // Parse the line into arguments
    int num_args = parse_args(line, args);

    if (num_args == 0) {
      continue;  // Empty line, skip
    }

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
      printf("Exiting shell...\n");
      break;
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {  // Child process
      // Execute the command
      execvp(args[0], args);

      // If execvp fails, print an error message and exit
      perror(args[0]);
      exit(1);
    } else {  // Parent process
      // Wait for the child process to finish
      waitpid(pid, &status, 0);

      if (WIFEXITED(status)) {
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
      } else {
        printf("Child process terminated abnormally\n");
      }
    }
  }

  return 0;
}

int parse_args(char *line, char **args) {
  int num_args = 0;
  char *token;

  token = strtok(line, " ");
  while (token != NULL) {
    args[num_args++] = token;
    token = strtok(NULL, " ");
  }

  return num_args;
}