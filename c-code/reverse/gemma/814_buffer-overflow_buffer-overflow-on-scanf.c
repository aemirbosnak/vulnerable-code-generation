#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char command[1024];

  printf("Enter command: ");
  scanf("%s", command);

  if (strcmp(command, "light on") == 0) {
    printf("Light is on.\n");
  } else if (strcmp(command, "light off") == 0) {
    printf("Light is off.\n");
  } else if (strcmp(command, "menu") == 0) {
    printf("Available commands:\n");
    printf("1. Light on\n");
    printf("2. Light off\n");
    printf("3. Menu\n");
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}
