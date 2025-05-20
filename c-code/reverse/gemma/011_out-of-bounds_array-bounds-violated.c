#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char cmd[1024];
  scanf("%s", cmd);
  pid_t pid = fork();
  if (pid == 0) {
    execlp("/bin/bash", "bash", "-c", cmd, NULL);
  } else if (pid > 0) {
    wait(NULL);
  } else {
    perror("Error");
  }
  return 0;
}
