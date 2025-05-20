#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  char cmd[1024];

  printf("Enter a command: ");
  scanf("%s", cmd);

  if (strlen(cmd) > 1024) {
    printf("Error: command too long.\n");
  } else {
    sprintf(buf, "echo %s", cmd);
    system(buf);
  }

  return 0;
}
