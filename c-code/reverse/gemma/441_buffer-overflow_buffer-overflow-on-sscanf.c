#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LIGHTS 10

int main() {
  int lights[MAX_LIGHTS] = {0};
  char cmd[100];

  printf("Current light status:\n");
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %d: %s\n", i + 1, lights[i] ? "On" : "Off");
  }

  printf("Enter command (e.g. 'on 5', 'off 2'): ");
  scanf("%s", cmd);

  if (sscanf(cmd, "on %d", &lights[0]) == 1) {
    lights[0] = 1;
  } else if (sscanf(cmd, "off %d", &lights[0]) == 1) {
    lights[0] = 0;
  } else {
    printf("Invalid command.\n");
  }

  printf("Updated light status:\n");
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %d: %s\n", i + 1, lights[i] ? "On" : "Off");
  }

  return 0;
}
