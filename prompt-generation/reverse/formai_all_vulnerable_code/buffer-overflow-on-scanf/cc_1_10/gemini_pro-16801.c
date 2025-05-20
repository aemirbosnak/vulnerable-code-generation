//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct light {
  char *name;
  bool is_on;
} light_t;

void turn_on(light_t *light) {
  light->is_on = true;
  printf("%s is now on.\n", light->name);
}

void turn_off(light_t *light) {
  light->is_on = false;
  printf("%s is now off.\n", light->name);
}

void toggle(light_t *light) {
  light->is_on = !light->is_on;
  printf("%s is now %s.\n", light->name, light->is_on ? "on" : "off");
}

void print_status(light_t *light) {
  printf("%s is %s.\n", light->name, light->is_on ? "on" : "off");
}

void control_light(light_t *light, char *command) {
  if (strcmp(command, "on") == 0) {
    turn_on(light);
  } else if (strcmp(command, "off") == 0) {
    turn_off(light);
  } else if (strcmp(command, "toggle") == 0) {
    toggle(light);
  } else if (strcmp(command, "status") == 0) {
    print_status(light);
  } else {
    printf("Invalid command: %s\n", command);
  }
}

void control_lights(light_t **lights, int num_lights, char *command) {
  for (int i = 0; i < num_lights; i++) {
    control_light(lights[i], command);
  }
}

int main() {
  light_t lights[] = {
    { .name = "Living Room Light", .is_on = false },
    { .name = "Kitchen Light", .is_on = false },
    { .name = "Bedroom Light", .is_on = false }
  };

  char command[100];
  while (true) {
    printf("Enter a command (on, off, toggle, status, quit): ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else {
      control_lights(lights, sizeof(lights) / sizeof(light_t), command);
    }
  }

  return 0;
}