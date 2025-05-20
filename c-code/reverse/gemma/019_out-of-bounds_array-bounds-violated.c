#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char buf[1024];
  char **args;
  char **path;
  pid_t pid;

  while (1) {
    printf("$ ");
    fgets(buf, 1024, stdin);

    args = strtok(buf, " ");
    path = strchr(args[0], '/') ? args[0] : NULL;

    if (path) {
      if (fork() == 0) {
        execv(path, args);
      } else {
        pid = wait(NULL);
      }
    } else {
      printf("Error: command not found.\n");
    }
  }

  return 0;
}
