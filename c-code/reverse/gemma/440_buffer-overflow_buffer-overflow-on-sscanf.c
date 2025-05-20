#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char command[1024];
  scanf("%s", command);
  sscanf(command, "light %s", command);
  if (strcmp(command, "on") == 0) {
    // Turn on lights
  } else if (strcmp(command, "off") == 0) {
    // Turn off lights
  } else {
    // Invalid command
  }
  return 0;
}
