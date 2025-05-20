//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
// A basic Unix-like shell in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

char* prompt = "$ ";

void execute(char* cmd) {
  char* args[MAX_ARGS];
  int i, argc;

  // Tokenize the command
  char* token = strtok(cmd, " ");
  argc = 0;
  while (token != NULL) {
    args[argc++] = token;
    token = strtok(NULL, " ");
  }

  // Check if the command is a built-in
  if (strcmp(args[0], "cd") == 0) {
    if (argc == 1) {
      chdir(getenv("HOME"));
    } else if (argc == 2) {
      chdir(args[1]);
    }
    return;
  } else if (strcmp(args[0], "exit") == 0) {
    exit(0);
  }

  // Fork a new process
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    // Child process
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else {
    // Parent process
    wait(NULL);
  }
}

int main() {
  while (1) {
    printf("%s", prompt);
    char cmd[MAX_CMD_LEN];
    fgets(cmd, MAX_CMD_LEN, stdin);
    cmd[strlen(cmd) - 1] = '\0';
    execute(cmd);
  }
  return 0;
}