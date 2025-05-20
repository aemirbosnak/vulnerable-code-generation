//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 32

int main(int argc, char *argv[]) {
  char *args[MAX_ARGS];
  int i, status;

  while (1) {
    printf("> ");
    fflush(stdout);

    // Read input
    char input[1024];
    if (fgets(input, sizeof(input), stdin) == NULL) {
      perror("fgets");
      exit(EXIT_FAILURE);
    }

    // Parse input
    i = 0;
    char *token = strtok(input, " ");
    while (token != NULL && i < MAX_ARGS) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Handle special commands
    if (strcmp(args[0], "exit") == 0) {
      exit(EXIT_SUCCESS);
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) == -1) {
        perror("chdir");
      }
      continue;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(EXIT_FAILURE);
    } else {
      // Parent process
      waitpid(pid, &status, 0);
      if (WIFEXITED(status)) {
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
        printf("Child process terminated by signal %d\n", WTERMSIG(status));
      }
    }
  }

  return 0;
}