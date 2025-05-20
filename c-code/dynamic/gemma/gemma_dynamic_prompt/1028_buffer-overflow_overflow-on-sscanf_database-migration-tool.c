#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char command[1024];

  printf("Enter a command: ");
  scanf("%s", command);

  // Exploit buffer overflow vulnerability
  sprintf(buffer, "echo %s", command);
  system(buffer);

  return 0;
}
