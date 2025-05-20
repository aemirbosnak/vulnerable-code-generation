//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

struct command {
  char* name;
  char* args[MAX_ARGS];
  int argc;
};

void parse_args(char* line, struct command* cmd) {
  char* arg;
  char* saveptr;
  cmd->argc = 0;
  arg = strtok_r(line, " ", &saveptr);
  while (arg != NULL) {
    cmd->args[cmd->argc++] = arg;
    arg = strtok_r(NULL, " ", &saveptr);
  }
}

void execute_command(struct command* cmd) {
  if (cmd->argc == 0) {
    return;
  }
  if (strcmp(cmd->name, "cd") == 0) {
    chdir(cmd->args[0]);
  } else if (strcmp(cmd->name, "pwd") == 0) {
    char* cwd = getcwd(NULL, 0);
    printf("%s\n", cwd);
    free(cwd);
  } else if (strcmp(cmd->name, "echo") == 0) {
    for (int i = 0; i < cmd->argc; i++) {
      printf("%s ", cmd->args[i]);
    }
    printf("\n");
  } else {
    printf("Unknown command: %s\n", cmd->name);
  }
}

int main() {
  char line[1024];
  struct command cmd;
  while (1) {
    printf("$ ");
    fgets(line, 1024, stdin);
    parse_args(line, &cmd);
    execute_command(&cmd);
  }
  return 0;
}