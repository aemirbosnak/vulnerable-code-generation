#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256

int main() {
  char command[MAX_COMMAND_LENGTH];

  printf("Enter command: ");
  scanf("%s", command);

  if (strlen(command) > MAX_COMMAND_LENGTH - 1) {
    printf("Error: Command too long.\n");
  } else if (strcmp(command, "on") == 0) {
    printf("Light is on.\n");
  } else if (strcmp(command, "off") == 0) {
    printf("Light is off.\n");
  } else {
    printf("Error: Invalid command.\n");
  }

  return 0;
}
