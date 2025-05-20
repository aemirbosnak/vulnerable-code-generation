//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>

int main() {
    int forward = 1, backward = 0, left = 0, right = 0, stop = 0;
    char direction;
    printf("Welcome to Robot Movement Control Program!\n");
    printf("Enter 'F' to move forward, 'B' to move backward, 'L' to turn left, 'R' to turn right, or 'S' to stop: ");

    while(1) {
        scanf("%c", &direction);
        while(getchar() != '\n'); // Clear input buffer

        switch(direction) {
            case 'F':
                forward = 1;
                backward = left = right = stop = 0;
                printf("Moving forward...\n");
                break;
            case 'B':
                backward = 1;
                forward = left = right = stop = 0;
                printf("Moving backward...\n");
                break;
            case 'L':
                left = 1;
                forward = backward = right = stop = 0;
                printf("Turning left...\n");
                break;
            case 'R':
                right = 1;
                forward = backward = left = stop = 0;
                printf("Turning right...\n");
                break;
            case 'S':
                stop = 1;
                forward = backward = left = right = 0;
                printf("Stopping...\n");
                break;
            default:
                printf("Invalid direction! Please enter 'F', 'B', 'L', 'R', or 'S': ");
                continue;
        }

        printf("Current movement: ");
        if(forward) {
            printf("Forward\n");
        } else if(backward) {
            printf("Backward\n");
        } else if(left) {
            printf("Left\n");
        } else if(right) {
            printf("Right\n");
        } else {
            printf("Stop\n");
        }

        printf("Enter next direction: ");
    }

    return 0;
}