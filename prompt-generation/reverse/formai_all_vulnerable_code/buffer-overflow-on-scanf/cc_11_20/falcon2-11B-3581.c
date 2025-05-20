//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>

int main() {
    int x = 0; // current x-coordinate of the robot
    int y = 0; // current y-coordinate of the robot
    int direction = 1; // direction of the robot (1 = forward, -1 = backward, 0 = turn left, 2 = turn right)

    printf("Movement Control for a Robot\n\n");

    while (1) {
        printf("Enter command: ");
        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
            case 1: // move forward
                if (direction == 1) {
                    x++;
                    printf("Robot moved forward by 1 unit.\n");
                } else if (direction == -1) {
                    x--;
                    printf("Robot moved backward by 1 unit.\n");
                } else {
                    printf("Invalid command.\n");
                }
                break;
            case 2: // move backward
                if (direction == 1) {
                    x--;
                    printf("Robot moved backward by 1 unit.\n");
                } else if (direction == -1) {
                    x++;
                    printf("Robot moved forward by 1 unit.\n");
                } else {
                    printf("Invalid command.\n");
                }
                break;
            case 3: // turn left
                if (direction == 0) {
                    y--;
                    printf("Robot turned left by 1 unit.\n");
                } else if (direction == 2) {
                    y++;
                    printf("Robot turned right by 1 unit.\n");
                } else {
                    printf("Invalid command.\n");
                }
                break;
            case 4: // turn right
                if (direction == 0) {
                    y++;
                    printf("Robot turned right by 1 unit.\n");
                } else if (direction == 2) {
                    y--;
                    printf("Robot turned left by 1 unit.\n");
                } else {
                    printf("Invalid command.\n");
                }
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}