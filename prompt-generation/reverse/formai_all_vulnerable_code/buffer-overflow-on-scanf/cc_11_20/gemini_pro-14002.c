//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROBOTS 10
#define MAX_COMMANDS 100

struct robot {
  int x;
  int y;
  int facing; // 0 = north, 1 = east, 2 = south, 3 = west
};

struct command {
  char *cmd;
  int arg;
};

int main() {
  int num_robots, num_commands;
  struct robot robots[MAX_ROBOTS];
  struct command commands[MAX_COMMANDS];

  // Read input
  scanf("%d %d", &num_robots, &num_commands);
  for (int i = 0; i < num_robots; i++) {
    scanf("%d %d %d", &robots[i].x, &robots[i].y, &robots[i].facing);
  }
  for (int i = 0; i < num_commands; i++) {
    scanf("%s %d", commands[i].cmd, &commands[i].arg);
  }

  // Execute commands
  for (int i = 0; i < num_commands; i++) {
    for (int j = 0; j < num_robots; j++) {
      if (strcmp(commands[i].cmd, "move") == 0) {
        switch (robots[j].facing) {
          case 0:
            robots[j].y += commands[i].arg;
            break;
          case 1:
            robots[j].x += commands[i].arg;
            break;
          case 2:
            robots[j].y -= commands[i].arg;
            break;
          case 3:
            robots[j].x -= commands[i].arg;
            break;
        }
      } else if (strcmp(commands[i].cmd, "turn") == 0) {
        robots[j].facing = (robots[j].facing + commands[i].arg) % 4;
      }
    }
  }

  // Print output
  for (int i = 0; i < num_robots; i++) {
    printf("%d %d %d\n", robots[i].x, robots[i].y, robots[i].facing);
  }

  return 0;
}