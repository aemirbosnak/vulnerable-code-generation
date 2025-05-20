#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char cmd[1024];
  scanf("%s", cmd);

  if (strlen(cmd) > 1024) {
    printf("Error: Command too long.\n");
  } else if (strcmp(cmd, "forward") == 0) {
    printf("Drone moving forward.\n");
  } else if (strcmp(cmd, "right") == 0) {
    printf("Drone moving right.\n");
  } else if (strcmp(cmd, "left") == 0) {
    printf("Drone moving left.\n");
  } else if (strcmp(cmd, "stop") == 0) {
    printf("Drone stopped.\n");
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}
