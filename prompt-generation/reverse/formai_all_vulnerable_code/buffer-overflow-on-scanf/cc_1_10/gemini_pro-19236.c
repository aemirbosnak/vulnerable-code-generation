//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style
#define printf(...) fprintf(stderr, __VA_ARGS__)

// Remote control vehicle simulation
struct vehicle {
  int x, y;
  int speed;
  int direction;
};

// Romeo and Juliet style
void move(struct vehicle *v, char *cmd) {
  if (!strcmp(cmd, "forward")) {
    v->y += v->speed;
  } else if (!strcmp(cmd, "backward")) {
    v->y -= v->speed;
  } else if (!strcmp(cmd, "left")) {
    v->x -= v->speed;
  } else if (!strcmp(cmd, "right")) {
    v->x += v->speed;
  } else {
    printf("Invalid command: %s\n", cmd);
  }
}

// Romeo and Juliet style
void print_position(struct vehicle *v) {
  printf("Romeo's position: (%d, %d)\n", v->x, v->y);
}

int main(int argc, char **argv) {
  if (argc != 5) {
    printf("Usage: %s <speed> <direction> <x> <y>\n", argv[0]);
    return 1;
  }

  struct vehicle v;
  v.speed = atoi(argv[1]);
  v.direction = atoi(argv[2]);
  v.x = atoi(argv[3]);
  v.y = atoi(argv[4]);

  char cmd[10];
  while (1) {
    printf("Enter a command (forward, backward, left, right, quit): ");
    scanf("%s", cmd);
    if (!strcmp(cmd, "quit")) {
      break;
    }

    move(&v, cmd);
    print_position(&v);
  }

  return 0;
}