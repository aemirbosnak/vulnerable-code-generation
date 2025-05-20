//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_ARGS 10

int parse_cmd_args(char *cmd_line, char *cmd_args[]) {
  int argc = 0;
  char *arg = strtok(cmd_line, " ");
  while (arg != NULL && argc < MAX_CMD_ARGS - 1) {
    cmd_args[argc++] = arg;
    arg = strtok(NULL, " ");
  }
  cmd_args[argc] = NULL;
  return argc;
}

int main() {
  char cmd_line[1024];
  char *cmd_args[MAX_CMD_ARGS];
  while (1) {
    printf("> ");
    fgets(cmd_line, 1024, stdin);
    if (strlen(cmd_line) == 1) {
      continue;
    }
    cmd_line[strlen(cmd_line) - 1] = '\0'; // remove newline character
    if (strcmp(cmd_line, "exit") == 0) {
      break;
    }
    int argc = parse_cmd_args(cmd_line, cmd_args);
    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // child
      if (execvp(cmd_args[0], cmd_args) == -1) {
        perror("exec");
        exit(EXIT_FAILURE);
      }
    } else {
      // parent
      wait(NULL);
    }
  }
  return 0;
}