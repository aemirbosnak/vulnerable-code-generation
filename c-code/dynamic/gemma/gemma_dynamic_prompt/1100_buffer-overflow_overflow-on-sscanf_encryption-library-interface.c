#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  char command[1024];

  scanf("%s", command);

  if (strlen(command) > 10) {
    printf("Error: command too long.\n");
  } else {
    sprintf(buffer, "echo %s", command);
    system(buffer);
  }

  return 0;
}
