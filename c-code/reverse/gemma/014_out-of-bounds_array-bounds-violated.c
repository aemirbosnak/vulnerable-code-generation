#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **argv = NULL;
  char *arg = malloc(1024);
  printf("Enter command: ");
  fgets(arg, 1024, stdin);

  // Array bounds violation
  argv = strtok(arg, " ");
  if (argv[1] && argv[1][0] >= 'a' && argv[1][0] <= 'z') {
    execv("/bin/bash", argv);
  } else {
    printf("Invalid command.\n");
  }

  free(arg);
  return 0;
}
