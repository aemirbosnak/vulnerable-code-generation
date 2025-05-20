//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_SIZE 256
#define MAX_ARGS 10

int main(int argc, char *argv[]) {
  char cmd[MAX_CMD_SIZE];
  char *args[MAX_ARGS];
  int cmd_len;
  int args_len;
  int i;
  int status;

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_SIZE, stdin);
    cmd_len = strlen(cmd);
    cmd[cmd_len - 1] = '\0';
    args_len = split_args(cmd, args);
    if (args_len == 0) {
      continue;
    }
    if (strcmp(args[0], "exit") == 0) {
      break;
    }
    if (strcmp(args[0], "cd") == 0) {
      if (args_len == 1) {
        printf("Missing argument for 'cd'\n");
        continue;
      }
      if (chdir(args[1]) != 0) {
        printf("Could not change directory\n");
        continue;
      }
    } else {
      pid_t pid = fork();
      if (pid == 0) {
        execvp(args[0], args);
        exit(1);
      }
      waitpid(pid, &status, 0);
    }
  }
  return 0;
}

int split_args(char *cmd, char *args[]) {
  int args_len = 0;
  char *token = strtok(cmd, " ");
  while (token != NULL) {
    args[args_len] = token;
    args_len++;
    token = strtok(NULL, " ");
  }
  return args_len;
}