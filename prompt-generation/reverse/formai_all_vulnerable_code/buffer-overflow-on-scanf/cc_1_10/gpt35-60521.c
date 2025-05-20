//FormAI DATASET v1.0 Category: Robot movement control ; Style: happy
// Happy Robot Movement Control Program

#include <stdio.h>

int main() {

    printf("Welcome to our happy robot movement control program!\n");
    printf("Let's make our robot move with joy!\n");

    int xPos = 0;
    int yPos = 0;

    while (1) {
        printf("Current position of the robot: (%d, %d)\n", xPos, yPos);
        printf("Enter the direction you want to move the robot:\n");
        printf("1. North\n");
        printf("2. South\n");
        printf("3. East\n");
        printf("4. West\n");

        int direction;
        scanf("%d", &direction);

        switch (direction) {
            case 1:
                printf("Moving robot North with joy!\n");
                yPos++;
                break;
            case 2:
                printf("Moving robot South with joy!\n");
                yPos--;
                break;
            case 3:
                printf("Moving robot East with joy!\n");
                xPos++;
                break;
            case 4:
                printf("Moving robot West with joy!\n");
                xPos--;
                break;
            default:
                printf("Invalid direction choice. Please try again with joy!\n");
        }

        printf("Robot has moved to position: (%d, %d)\n", xPos, yPos);
        printf("--------------------------------------------------\n");
    }

    return 0;
}