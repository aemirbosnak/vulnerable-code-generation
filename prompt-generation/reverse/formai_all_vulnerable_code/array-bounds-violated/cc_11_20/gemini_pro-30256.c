//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(void) {
  char line[MAX_LINE];
  char *args[MAX_LINE / 2 + 1];  
  int status;
  
  while (1) {
    printf("~> ");
    if (!fgets(line, MAX_LINE, stdin))
      break;
    if (line[strlen(line) - 1] == '\n')
      line[strlen(line) - 1] = '\0';

    // Tokenize the input
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    if (num_args == 0)
      continue;

    // Handle built-in commands
    if (!strcmp(args[0], "exit"))
      break;
    else if (!strcmp(args[0], "cd")) {
      if (num_args != 2) {
        printf("Usage: cd <directory>\n");
        continue;
      }
      if (chdir(args[1]) != 0)
        printf("Error: could not change directory to %s\n", args[1]);
      continue;
    }

    // Fork a child process and execute the command
    pid_t pid = fork();
    if (pid == 0) {  // Child process
      if (execvp(args[0], args) == -1) {
        printf("Error: could not execute command %s\n", args[0]);
        exit(1);
      }
    } else {  // Parent process
      wait(&status);
      if (WIFEXITED(status)) {
        if (WEXITSTATUS(status) != 0)
          printf("Error: command %s exited with status %d\n", args[0], WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
        printf("Error: command %s was terminated by signal %d\n", args[0], WTERMSIG(status));
      }
    }
  }

  return 0;
}