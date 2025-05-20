//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define HIST_SIZE 10

typedef struct CmdHistory {
  char **cmds;
  int idx;
} CmdHistory;

CmdHistory history;

void add_history(char *cmd) {
  if (history.cmds == NULL) {
    history.cmds = malloc(sizeof(char *) * HIST_SIZE);
  }

  if (history.idx >= HIST_SIZE - 1) {
    history.cmds = realloc(history.cmds, sizeof(char *) * HIST_SIZE * 2);
    history.idx = HIST_SIZE - 2;
  }

  history.cmds[history.idx++] = strdup(cmd);
}

void print_history() {
  for (int i = 0; i < history.idx; i++) {
    printf("%s\n", history.cmds[i]);
  }
}

int main() {
  history.cmds = NULL;
  history.idx = 0;

  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    scanf("%s", cmd);

    add_history(cmd);

    if (strcmp(cmd, "exit") == 0) {
      break;
    }

    // Execute command
  }

  print_history();

  return 0;
}