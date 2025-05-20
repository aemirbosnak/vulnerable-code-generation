//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>

// function to move the robot forward
void move_forward(int distance) {
    printf("Moving forward %d meters.\n", distance);
}

// function to turn the robot left
void turn_left(int degrees) {
    printf("Turning left %d degrees.\n", degrees);
}

// function to turn the robot right
void turn_right(int degrees) {
    printf("Turning right %d degrees.\n", degrees);
}

// function to stop the robot
void stop_robot() {
    printf("Stopping the robot.\n");
}

int main() {
    char direction;
    int distance, degrees;

    printf("Enter a direction (f for forward, l for left, r for right, s for stop): ");
    scanf("%c", &direction);

    switch (direction) {
        case 'f':
            printf("Enter a distance in meters: ");
            scanf("%d", &distance);
            move_forward(distance);
            break;
        case 'l':
            printf("Enter a turn angle in degrees: ");
            scanf("%d", &degrees);
            turn_left(degrees);
            break;
        case 'r':
            printf("Enter a turn angle in degrees: ");
            scanf("%d", &degrees);
            turn_right(degrees);
            break;
        case 's':
            stop_robot();
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }

    return 0;
}