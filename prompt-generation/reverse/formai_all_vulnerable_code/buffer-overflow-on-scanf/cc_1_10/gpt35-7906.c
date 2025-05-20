//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point robot = {0, 0}; // Robot starting position
    int direction = 0; // Robot starting direction (0 = north)

    char movement[50]; // Maximum number of movements is 50
    printf("Enter robot movement instructions: ");
    scanf("%s", movement);

    for(int i = 0; movement[i] != '\0'; i++) {
        switch(movement[i]) {
            case 'F':
                // Move robot forward based on direction
                switch(direction) {
                    case 0: // North
                        robot.y++;
                        break;
                    case 1: // East
                        robot.x++;
                        break;
                    case 2: // South
                        robot.y--;
                        break;
                    case 3: // West
                        robot.x--;
                        break;
                    default:
                        printf("Invalid direction: %d\n", direction);
                        exit(1);
                }
                break;
            case 'L':
                // Turn robot left (counter-clockwise)
                direction = (direction + 3) % 4; // Subtracting 1 would result in negative numbers, so adding 3 is equivalent
                break;
            case 'R':
                // Turn robot right (clockwise)
                direction = (direction + 1) % 4;
                break;
            default:
                printf("Invalid movement instruction: %c\n", movement[i]);
                exit(1);
        }
    }

    printf("Robot final position: (%d, %d)\n", robot.x, robot.y);

    return 0;
}