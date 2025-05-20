//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>

// function to move the robot forward
void move_forward(int distance) {
    if (distance == 0) {
        return;  // base case
    } else {
        printf("Moving forward...\n");
        move_forward(distance - 1);  // recursive call
    }
}

// function to move the robot backward
void move_backward(int distance) {
    if (distance == 0) {
        return;  // base case
    } else {
        printf("Moving backward...\n");
        move_backward(distance - 1);  // recursive call
    }
}

// function to turn the robot left
void turn_left(int angle) {
    if (angle == 0) {
        return;  // base case
    } else {
        printf("Turning left...\n");
        turn_left(angle - 1);  // recursive call
    }
}

// function to turn the robot right
void turn_right(int angle) {
    if (angle == 0) {
        return;  // base case
    } else {
        printf("Turning right...\n");
        turn_right(angle - 1);  // recursive call
    }
}

// function to control the robot's movement
void control_movement() {
    int distance, angle;
    char direction;
    printf("Enter a direction (F = forward, B = backward, L = left, R = right): ");
    scanf(" %c", &direction);
    switch (direction) {
        case 'F':
            printf("Enter a distance to move forward: ");
            scanf("%d", &distance);
            move_forward(distance);
            break;
        case 'B':
            printf("Enter a distance to move backward: ");
            scanf("%d", &distance);
            move_backward(distance);
            break;
        case 'L':
            printf("Enter an angle to turn left: ");
            scanf("%d", &angle);
            turn_left(angle);
            break;
        case 'R':
            printf("Enter an angle to turn right: ");
            scanf("%d", &angle);
            turn_right(angle);
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
    printf("Do you want to continue? (Y/N) ");
    scanf(" %c", &direction);
    if (direction == 'Y' || direction == 'y') {
        control_movement();  // recursive call
    }
}

int main() {
    control_movement();
    return 0;
}