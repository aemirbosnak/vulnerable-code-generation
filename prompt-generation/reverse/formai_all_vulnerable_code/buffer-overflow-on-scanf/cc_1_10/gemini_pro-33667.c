//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 100

typedef struct {
  char name[32];
  int state;
} light_t;

light_t lights[MAX_LIGHTS];
int num_lights = 0;

void add_light(char *name) {
  if (num_lights == MAX_LIGHTS) {
    printf("Error: Maximum number of lights reached.\n");
    return;
  }
  strcpy(lights[num_lights].name, name);
  lights[num_lights].state = 0;
  num_lights++;
}

void remove_light(char *name) {
  int i;
  for (i = 0; i < num_lights; i++) {
    if (strcmp(lights[i].name, name) == 0) {
      break;
    }
  }
  if (i == num_lights) {
    printf("Error: Light not found.\n");
    return;
  }
  for (; i < num_lights - 1; i++) {
    lights[i] = lights[i + 1];
  }
  num_lights--;
}

void toggle_light(char *name) {
  int i;
  for (i = 0; i < num_lights; i++) {
    if (strcmp(lights[i].name, name) == 0) {
      break;
    }
  }
  if (i == num_lights) {
    printf("Error: Light not found.\n");
    return;
  }
  lights[i].state = !lights[i].state;
}

void print_lights() {
  int i;
  for (i = 0; i < num_lights; i++) {
    printf("%s: %s\n", lights[i].name, lights[i].state ? "On" : "Off");
  }
}

int main() {
  char command[32];
  char name[32];

  while (1) {
    printf("> ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      scanf("%s", name);
      add_light(name);
    } else if (strcmp(command, "remove") == 0) {
      scanf("%s", name);
      remove_light(name);
    } else if (strcmp(command, "toggle") == 0) {
      scanf("%s", name);
      toggle_light(name);
    } else if (strcmp(command, "list") == 0) {
      print_lights();
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}