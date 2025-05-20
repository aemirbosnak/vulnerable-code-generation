//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

typedef struct ShellState {
  char **history;
  int history_size;
  char prompt[MAX_CMD_LEN];
  char cmd[MAX_CMD_LEN];
  int cmd_pos;
  int exit_flag;
} ShellState;

ShellState shell_state;

void shell_init() {
  shell_state.history = NULL;
  shell_state.history_size = 0;
  shell_state.prompt[0] = '$';
  shell_state.prompt[1] = '\0';
  shell_state.cmd[0] = '\0';
  shell_state.cmd_pos = 0;
  shell_state.exit_flag = 0;
}

void shell_prompt() {
  printf("%s", shell_state.prompt);
  fflush(stdout);
}

void shell_read_cmd() {
  shell_state.cmd_pos = 0;
  shell_state.cmd[0] = '\0';
  getline(shell_state.cmd, MAX_CMD_LEN, stdin);
  shell_state.cmd[shell_state.cmd_pos - 1] = '\0';
  shell_state.history_size++;
  shell_state.history = realloc(shell_state.history, shell_state.history_size * sizeof(char *));
  shell_state.history[shell_state.history_size - 1] = strdup(shell_state.cmd);
}

void shell_execute() {
  char **argv = NULL;
  char *cmd_ptr = shell_state.cmd;
  int argc = 0;

  // Tokenize the command
  while (*cmd_ptr) {
    if (*cmd_ptr == ' ') {
      argv = realloc(argv, (argc + 1) * sizeof(char *));
      argv[argc++] = malloc(MAX_CMD_LEN);
      cmd_ptr++;
      strcpy(argv[argc - 1], cmd_ptr);
    } else {
      cmd_ptr++;
    }
  }

  // Execute the command
  if (argc > 0) {
    execvp(argv[0], argv);
  } else {
    printf("Error: invalid command\n");
  }

  free(argv);
}

int main() {
  shell_init();

  while (!shell_state.exit_flag) {
    shell_prompt();
    shell_read_cmd();
    shell_execute();
  }

  return 0;
}