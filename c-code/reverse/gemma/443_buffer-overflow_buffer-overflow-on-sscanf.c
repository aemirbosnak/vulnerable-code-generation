#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10

int main() {
  int lights[MAX_LIGHTS] = {0};
  char command[20];
  int light_num;

  printf("Welcome to the smart home lighting system. Please enter a command: ");
  scanf("%s", command);

  if (strcmp(command, "help") == 0) {
    printf("Available commands:\n");
    printf("  on [light_num]: Turns on the specified light.\n");
    printf("  off [light_num]: Turns off the specified light.\n");
    printf("  help: Lists available commands.\n");
  } else if (strcmp(command, "on") == 0) {
    scanf("Enter the light number: ", &light_num);
    if (light_num < 1 || light_num > MAX_LIGHTS) {
      printf("Invalid light number.\n");
    } else {
      lights[light_num - 1] = 1;
      printf("Light %d is on.\n", light_num);
    }
  } else if (strcmp(command, "off") == 0) {
    scanf("Enter the light number: ", &light_num);
    if (light_num < 1 || light_num > MAX_LIGHTS) {
      printf("Invalid light number.\n");
    } else {
      lights[light_num - 1] = 0;
      printf("Light %d is off.\n", light_num);
    }
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}
