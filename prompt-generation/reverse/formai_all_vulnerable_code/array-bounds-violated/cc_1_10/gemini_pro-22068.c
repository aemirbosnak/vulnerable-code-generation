//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024
#define SHELL "/bin/sh"

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("$ ");
    fflush(stdout);

    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      break;
    }

    if (strlen(line) == 1) {
      continue;
    }

    line[strlen(line) - 1] = '\0';  // Remove newline

    int argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL && argc < MAX_ARGS) {
      args[argc++] = token;
      token = strtok(NULL, " ");
    }

    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    pid_t child_pid = fork();
    if (child_pid == 0) {
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else {
      waitpid(child_pid, &status, 0);
    }
  }

  return 0;
}