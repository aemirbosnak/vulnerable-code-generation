//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define robot movements
enum Directions { FORWARD, BACKWARD, LEFT, RIGHT };

// define the robot structure
struct Robot {
  int x, y;
  enum Directions dir;
};

// function to move the robot
void moveRobot(struct Robot* r) {
  switch (r->dir) {
    case FORWARD:
      printf("Moved Forward.\n");
      r->y++;
      break;
    case BACKWARD:
      printf("Moved Backward.\n");
      r->y--;
      break;
    case LEFT:
      printf("Moved Left.\n");
      r->x--;
      break;
    case RIGHT:
      printf("Moved Right.\n");
      r->x++;
      break;
  }
}

int main() {
  struct Robot robot = { 0, 0, FORWARD };
  char ch;

  do {
    printf("\nCurrent Position: (%d, %d)\n", robot.x, robot.y);
    printf("Select Direction (F)orward, (B)ackward, (L)eft, (R)ight. Press (Q) to quit: ");
    scanf(" %c", &ch);
    
    // validate user input
    bool validInput = true;
    switch (ch) {
      case 'f':
      case 'F':
        robot.dir = FORWARD;
        break;
      case 'b':
      case 'B':
        robot.dir = BACKWARD;
        break;
      case 'l':
      case 'L':
        robot.dir = LEFT;
        break;
      case 'r':
      case 'R':
        robot.dir = RIGHT;
        break;
      case 'q':
      case 'Q':
        printf("\nQuitting Program...\n");
        return 0;
      default:
        printf("\nInvalid Input. Please Try Again.\n");
        validInput = false;
        break;
    }

    if (validInput) {
      moveRobot(&robot);
    }
  } while (true);

  return 0;
}