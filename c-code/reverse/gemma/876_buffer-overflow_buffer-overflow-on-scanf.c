#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char cmd[10];
  scanf("%s", cmd);

  if (strlen(cmd) > 10) {
    printf("Error: command too long.\n");
  } else {
    // Process command
  }

  return 0;
}
