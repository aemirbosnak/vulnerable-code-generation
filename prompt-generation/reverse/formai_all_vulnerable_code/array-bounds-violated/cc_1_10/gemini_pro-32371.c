//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

char *args[MAX_ARGS];
char line[MAX_LINE_LENGTH];
int num_args;

int main() {
  while (1) {
    printf("Ada Lovelace Shell: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    if (feof(stdin)) {
      printf("Exiting shell.\n");
      exit(0);
    }
    line[strlen(line) - 1] = '\0';  // Remove newline character
    num_args = 0;
    args[num_args++] = strtok(line, " ");
    while (args[num_args - 1] != NULL && num_args < MAX_ARGS) {
      args[num_args++] = strtok(NULL, " ");
    }
    if (strcmp(args[0], "exit") == 0) {
      printf("Exiting shell.\n");
      exit(0);
    } else {
      int pid = fork();
      if (pid == 0) {  // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(1);
      } else {  // Parent process
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
          printf("Child process exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
          printf("Child process was terminated by signal %d.\n", WTERMSIG(status));
        } else {
          printf("Child process exited with unknown status.\n");
        }
      }
    }
  }
  return 0;
}