#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LIGHTS 10

int main() {
  char input[100];
  int num_lights = 0;
  int i;

  printf("Enter command (e.g. turn on light 1, dim light 2 to 50%): ");
  scanf("%s", input);

  // Process user command
  sscanf(input, "turn on light %d", &num_lights);
  if (num_lights > MAX_LIGHTS) {
    printf("Error: number of lights exceeded limit.\n");
  } else {
    for (i = 0; i < num_lights; i++) {
      // Turn on light
      printf("Light %d is on.\n", i + 1);
    }
  }

  sscanf(input, "dim light %d to %d%%", &num_lights, &i);
  if (num_lights > MAX_LIGHTS) {
    printf("Error: number of lights exceeded limit.\n");
  } else {
    for (i = 0; i < num_lights; i++) {
      // Dim light
      printf("Light %d is dimmed to %d%.\n", i + 1, i);
    }
  }

  return 0;
}
