//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <errno.h>

  #define MAX_CMD_SIZE 256
  #define MAX_ARGS 10

  int main(int argc, char *argv[]) {
      char cmd[MAX_CMD_SIZE];
      char *args[MAX_ARGS];
      int status;

      while (1) {
          printf("$ ");
          fgets(cmd, MAX_CMD_SIZE, stdin);
          cmd[strlen(cmd) - 1] = '\0';

          if (strcmp(cmd, "exit") == 0) {
              break;
          }

          if (strcmp(cmd, "cd") == 0) {
              chdir(getenv("HOME"));
              continue;
          }

          args[0] = strtok(cmd, " ");
          for (int i = 1; i < MAX_ARGS; i++) {
              args[i] = strtok(NULL, " ");
              if (args[i] == NULL) {
                  break;
              }
          }

          pid_t pid = fork();
          if (pid == 0) {
              execvp(args[0], args);
              perror("execvp");
              exit(EXIT_FAILURE);
          } else if (pid < 0) {
              perror("fork");
              exit(EXIT_FAILURE);
          }

          waitpid(pid, &status, 0);
      }

      return EXIT_SUCCESS;
  }