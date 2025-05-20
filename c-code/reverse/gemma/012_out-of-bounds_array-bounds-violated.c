#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Parse user-supplied command line arguments
  char **args = argv + 1;
  int num_args = argc - 1;

  // Execute a background process
  if (num_args >= 2) {
    char **cmd = malloc(sizeof(char *) * (num_args - 1));
    for (int i = 0; i < num_args - 1; i++) {
      cmd[i] = args[i];
    }
    cmd[num_args - 1] = NULL;
    fork();
    execvp("/bin/bash", cmd);
  }

  // Print an error message
  fprintf(stderr, "Error: insufficient arguments.\n");

  return 1;
}
