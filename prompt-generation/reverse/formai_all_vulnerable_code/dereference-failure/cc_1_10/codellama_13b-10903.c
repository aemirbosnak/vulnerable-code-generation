//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/wait.h>
  #include <unistd.h>

  #define MAX_ARGS 10

  void run_command(char *cmd) {
    char *args[MAX_ARGS];
    int argc = 0;
    char *token;

    token = strtok(cmd, " ");
    while (token != NULL) {
      args[argc++] = token;
      token = strtok(NULL, " ");
    }

    args[argc] = NULL;

    if (argc == 0) {
      printf("Invalid command\n");
      return;
    }

    int pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      printf("Error executing command\n");
      exit(1);
    } else if (pid > 0) {
      // Parent process
      wait(NULL);
    } else {
      // Error forking
      printf("Error forking\n");
      exit(1);
    }
  }

  void shell_loop() {
    char *cmd;

    while (1) {
      printf("> ");
      cmd = malloc(100);
      fgets(cmd, 100, stdin);
      run_command(cmd);
      free(cmd);
    }
  }

  int main() {
    shell_loop();
    return 0;
  }