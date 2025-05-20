#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct Light {
  char name[20];
  int state;
} Light;

Light lights[MAX_LIGHTS] = {
  {"Living Room Light", 0},
  {"Kitchen Light", 0},
  {"Bedroom Light", 0},
  {"Dining Room Light", 0},
  {"Hallway Light", 0},
  {"Staircase Light", 0},
  {"Reading Light", 0},
  {"TV Room Light", 0},
    {"Office Light", 0},
    {"Guest Room Light", 0}
};

int main() {
  char command[100];
  int light_number;
  int light_state;

  printf("Enter command (e.g. 'on light1', 'off light2', 'dim light3 50%'): ");
  scanf("%s", command);

  if (sscanf(command, "on %d", &light_number) == 1) {
    lights[light_number - 1].state = 1;
  } else if (sscanf(command, "off %d", &light_number) == 1) {
    lights[light_number - 1].state = 0;
  } else if (sscanf(command, "dim %d %d", &light_number, &light_state) == 2) {
    if (light_state > 100 || light_state < 0) {
      printf("Error: Invalid light state.\n");
    } else {
      lights[light_number - 1].state = light_state;
    }
  } else {
    printf("Error: Invalid command.\n");
  }

  return 0;
}
