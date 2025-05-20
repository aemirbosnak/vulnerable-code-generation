//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

void execute(char** args) {
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    execvp(args[0], args);
    printf("Error: could not execute %s\n", args[0]);
    exit(1);
  } else if (pid < 0) {
    // Fork error
    printf("Error: could not fork\n");
    exit(1);
  } else {
    // Parent process
    wait(&status);
  }
}

int main() {
  char* args[MAX_ARGS];
  char* input;
  char* cmd;
  char* arg;
  int i = 0;

  while (1) {
    printf("myShell> ");
    fgets(input, MAX_ARGS, stdin);
    input[strlen(input) - 1] = '\0';

    cmd = strtok(input, " ");
    while (cmd != NULL) {
      args[i++] = cmd;
      cmd = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else {
      execute(args);
    }
  }

  return 0;
}