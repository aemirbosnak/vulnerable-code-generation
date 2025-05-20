//FormAI DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdio.h>

#define FORWARD 1
#define BACKWARD 0

void move(int direction, int steps) {
    if(direction == FORWARD) {
        printf("Moving Forward %d steps\n", steps);
    } else {
        printf("Moving Backward %d steps\n", steps);
    }
}

void turn(char side) {
    if(side == 'l') {
        printf("Turning Left\n");
    } else if (side == 'r') {
        printf("Turning Right\n");
    } else {
        printf("Invalid turn direction\n");
    }
}

void jump(int height) {
    printf("Jumping %d meters\n", height);
}

int main() {
    printf("Welcome to the Mind-Bending Robot Movement Control Program!\n");
    printf("Please enter the type of movement you want to perform: \n");
    printf("1 - Move Forward, 0 - Move Backward, l - Turn Left, r - Turn Right, j - Jump\n");

    char moveType;
    int direction, steps, height;
    scanf("%c", &moveType);

    switch(moveType) {
        case '1':
            printf("Enter the number of steps: ");
            scanf("%d", &steps);
            direction = FORWARD;
            move(direction, steps);
            break;
        case '0':
            printf("Enter the number of steps: ");
            scanf("%d", &steps);
            direction = BACKWARD;
            move(direction, steps);
            break;
        case 'l':
            turn('l');
            break;
        case 'r':
            turn('r');
            break;
        case 'j':
            printf("Enter the height of the jump (in meters): ");
            scanf("%d", &height);
            jump(height);
            break;
        default:
            printf("Invalid movement type selected\n");
            break;
    }

    printf("Thank you for using the Mind-Bending Robot Movement Control Program\n");
    return 0;
}