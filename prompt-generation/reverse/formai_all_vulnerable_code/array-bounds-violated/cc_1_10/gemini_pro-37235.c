//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

void parse_args(char *line, char **args) {
  char *token;
  int i = 0;

  token = strtok(line, " ");
  while (token != NULL) {
    args[i] = token;
    i++;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;
}

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  pid_t pid;
  int status;

  while (1) {
    printf("> ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    line[strlen(line) - 1] = '\0';  // Remove newline character

    if (strcmp(line, "exit") == 0) {
      break;
    }

    parse_args(line, args);

    pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else {
      // Parent process
      waitpid(pid, &status, 0);
      if (WIFEXITED(status)) {
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
        printf("Child process was terminated by signal %d\n", WTERMSIG(status));
      }
    }
  }

  return 0;
}