//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROBOTS 100
#define MAX_MOVEMENTS 1000

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position position;
  int direction; // 0: north, 1: east, 2: south, 3: west
} Robot;

Robot robots[MAX_ROBOTS];
int num_robots;

char movements[MAX_MOVEMENTS];
int num_movements;

void parse_input() {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Error opening input file");
    exit(1);
  }

  fscanf(fp, "%d", &num_robots);
  for (int i = 0; i < num_robots; i++) {
    fscanf(fp, "%d %d", &robots[i].position.x, &robots[i].position.y);
    robots[i].direction = 0;
  }

  fscanf(fp, "%s", movements);
  num_movements = strlen(movements);

  fclose(fp);
}

void move_robots() {
  for (int i = 0; i < num_robots; i++) {
    Robot *robot = &robots[i];

    for (int j = 0; j < num_movements; j++) {
      char movement = movements[j];

      switch (movement) {
        case 'N':
          robot->direction = 0;
          break;
        case 'E':
          robot->direction = 1;
          break;
        case 'S':
          robot->direction = 2;
          break;
        case 'W':
          robot->direction = 3;
          break;
        case 'F':
          switch (robot->direction) {
            case 0:
              robot->position.y++;
              break;
            case 1:
              robot->position.x++;
              break;
            case 2:
              robot->position.y--;
              break;
            case 3:
              robot->position.x--;
              break;
          }
          break;
        case 'L':
          robot->direction = (robot->direction + 3) % 4;
          break;
        case 'R':
          robot->direction = (robot->direction + 1) % 4;
          break;
      }
    }
  }
}

void print_robots() {
  FILE *fp = fopen("output.txt", "w");
  if (fp == NULL) {
    perror("Error opening output file");
    exit(1);
  }

  fprintf(fp, "%d\n", num_robots);
  for (int i = 0; i < num_robots; i++) {
    Robot *robot = &robots[i];
    fprintf(fp, "%d %d %d\n", i + 1, robot->position.x, robot->position.y);
  }

  fclose(fp);
}

int main() {
  parse_input();
  move_robots();
  print_robots();

  return 0;
}