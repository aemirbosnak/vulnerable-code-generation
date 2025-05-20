//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
  int x;
  int y;
  int z;
} drone;

typedef struct {
  char *command;
  int (*function)(drone *);
} command_map;

int move_up(drone *d) { d->z++; }
int move_down(drone *d) { d->z--; }
int move_left(drone *d) { d->x--; }
int move_right(drone *d) { d->x++; }
int move_forward(drone *d) { d->y++; }
int move_backward(drone *d) { d->y--; }

command_map commands[] = {
  {"up", move_up},
  {"down", move_down},
  {"left", move_left},
  {"right", move_right},
  {"forward", move_forward},
  {"backward", move_backward}
};

int main() {
  drone d = {0, 0, 0};

  char input[100];
  while (1) {
    printf("Enter a command: ");
    gets(input);

    int command_found = 0;
    for (int i = 0; i < sizeof(commands) / sizeof(command_map); i++) {
      if (strcmp(input, commands[i].command) == 0) {
        commands[i].function(&d);
        command_found = 1;
        break;
      }
    }
    if (!command_found) {
      printf("Invalid command.\n");
    }

    printf("Drone position: (%d, %d, %d)\n", d.x, d.y, d.z);
  }
  return 0;
}