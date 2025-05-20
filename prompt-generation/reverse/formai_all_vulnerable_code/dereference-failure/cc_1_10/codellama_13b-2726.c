//Code Llama-13B DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <errno.h>
  #include <syslog.h>
  #include <sys/resource.h>
  #include <sys/wait.h>
  #include <signal.h>

  int main(int argc, char **argv) {
      // Check if the user is the root user
      if (getuid() != 0) {
          printf("Only the root user can run this program\n");
          return 1;
      }

      // Parse the arguments
      if (argc < 2) {
          printf("Usage: %s <command> [arguments]\n", argv[0]);
          return 1;
      }
      char *command = argv[1];
      char *arguments[argc - 2];
      for (int i = 2; i < argc; i++) {
          arguments[i - 2] = argv[i];
      }

      // Fork a new process
      pid_t pid = fork();
      if (pid == 0) {
          // Child process
          // Execute the command
          execvp(command, arguments);
          printf("Error executing command: %s\n", strerror(errno));
          return 1;
      } else if (pid < 0) {
          // Error forking the process
          printf("Error forking the process: %s\n", strerror(errno));
          return 1;
      } else {
          // Parent process
          // Wait for the child process to terminate
          int status;
          waitpid(pid, &status, 0);
          if (WIFEXITED(status)) {
              // Child process terminated normally
              printf("Command completed successfully\n");
          } else {
              // Child process terminated with an error
              printf("Error executing command: %s\n", strerror(errno));
              return 1;
          }
      }
      return 0;
  }