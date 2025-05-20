#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  char cmd[1024];

  printf("Enter command: ");
  scanf("%s", cmd);

  // Overflow the buffer
  strcpy(buf, cmd);

  // Execute the command
  system(buf);

  return 0;
}
