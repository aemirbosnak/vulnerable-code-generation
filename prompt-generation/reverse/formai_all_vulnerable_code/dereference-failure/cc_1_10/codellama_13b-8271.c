//Code Llama-13B DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <sys/resource.h>

  #define BUFFER_SIZE 1024

  void print_usage(const char *program_name) {
      printf("Usage: %s [-h] [--help] [--usage] <command>\n", program_name);
      printf("  -h, --help   Display this help message and exit\n");
      printf("  --usage      Display the current RAM usage and exit\n");
      printf("  <command>    The command to execute and monitor\n");
  }

  int main(int argc, char **argv) {
      if (argc < 2) {
          print_usage(argv[0]);
          return 1;
      }

      if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
          print_usage(argv[0]);
          return 0;
      }

      if (strcmp(argv[1], "--usage") == 0) {
          struct rusage usage;
          getrusage(RUSAGE_SELF, &usage);
          printf("Current RAM usage: %ld bytes\n", usage.ru_maxrss);
          return 0;
      }

      char *command = argv[1];
      int status = 0;

      if (execvp(command, &argv[1]) == -1) {
          perror("execvp");
          return 1;
      }

      wait(&status);

      if (WIFEXITED(status)) {
          printf("Command exited with code %d\n", WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
          printf("Command terminated by signal %d\n", WTERMSIG(status));
      }

      return 0;
  }