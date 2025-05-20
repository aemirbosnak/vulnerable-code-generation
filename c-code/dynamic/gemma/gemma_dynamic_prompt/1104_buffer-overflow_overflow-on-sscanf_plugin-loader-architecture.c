#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10] = "";
  char command[1024] = "";

  printf("Enter a command: ");
  scanf("%s", command);

  // Overflow the buffer
  sprintf(buffer, "echo %s", command);

  system(buffer);

  return 0;
}
