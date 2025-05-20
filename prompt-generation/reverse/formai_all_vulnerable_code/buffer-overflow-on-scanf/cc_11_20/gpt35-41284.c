//FormAI DATASET v1.0 Category: Robot movement control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100

int main() {
    int direction = 0;
    int speed = 0;
    char input;

    while(1) {
        printf("Please choose a direction: (f)orward, (b)ackward, (l)eft or (r)ight.\n");
        scanf(" %c", &input);

        switch(input) {
            case 'f':
                direction = 1;
                break;
            case 'b':
                direction = -1;
                break;
            case 'l':
                direction = 2;
                break;
            case 'r':
                direction = -2;
                break;
            default:
                printf("Invalid direction! Please try again.\n");
                continue;
        }

        printf("Please choose a speed between 0 and %d.\n", MAX_SPEED);
        scanf("%d", &speed);

        if(speed < 0 || speed > MAX_SPEED) {
            printf("Invalid speed! Please try again.\n");
            continue;
        }

        printf("Moving the robot %s at speed %d.\n", 
            (direction == 1) ? "forward" : (direction == -1) ? "backward" : 
            (direction == 2) ? "left" : "right", speed);

        // Here we would send the movement commands to the robot
        // using some kind of communication protocol, like Bluetooth
    }

    return 0;
}