#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_DISTANCE 100

int main() {
  int speed = 0, direction = 1, distance = 0, time = 0;
  char command;

  while (1) {
    printf("Enter command (s/d/r/q): ");
    scanf(" %c", &command);

    switch (command) {
      case 's':
        if (speed < MAX_SPEED) {
          speed++;
        }
        break;
      case 'd':
        if (speed > 0) {
          speed--;
        }
        break;
      case 'r':
        direction *= -1;
        break;
      case 'q':
        printf("Total distance traveled: %d\n", distance);
        printf("Total time elapsed: %d seconds\n", time);
        return 0;
    }

    distance += speed * direction * time;
    time++;
  }
}
