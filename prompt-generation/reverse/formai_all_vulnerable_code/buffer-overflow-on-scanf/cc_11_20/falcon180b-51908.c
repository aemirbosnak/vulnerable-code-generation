//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN 100
#define MIN_TURN 0

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

int main() {
  int speed = MIN_SPEED;
  int turn = MIN_TURN;
  int direction = FORWARD;

  while (1) {
    printf("Current speed: %d\n", speed);
    printf("Current turn: %d\n", turn);
    printf("Current direction: %d\n", direction);

    int choice;
    printf("Enter your choice:\n");
    printf("1. Increase speed\n");
    printf("2. Decrease speed\n");
    printf("3. Increase turn\n");
    printf("4. Decrease turn\n");
    printf("5. Change direction\n");
    printf("6. Stop\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (speed < MAX_SPEED) {
          speed++;
        }
        break;
      case 2:
        if (speed > MIN_SPEED) {
          speed--;
        }
        break;
      case 3:
        if (turn < MAX_TURN) {
          turn++;
        }
        break;
      case 4:
        if (turn > MIN_TURN) {
          turn--;
        }
        break;
      case 5:
        direction = (direction + 1) % 4;
        break;
      case 6:
        speed = MIN_SPEED;
        turn = MIN_TURN;
        direction = FORWARD;
        break;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}