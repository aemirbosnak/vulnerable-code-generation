//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

void parse_args(char *line, char **args) {
  int i = 0;
  char *arg = strtok(line, " ");
  while (arg && i < MAX_ARGS) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;
}

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("> ");
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      printf("\n");
      exit(0);
    }

    line[strlen(line) - 1] = '\0';

    if (strcmp(line, "exit") == 0) {
      exit(0);
    }

    parse_args(line, args);

    if (fork() == 0) {
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else {
      wait(&status);
    }
  }

  return 0;
}