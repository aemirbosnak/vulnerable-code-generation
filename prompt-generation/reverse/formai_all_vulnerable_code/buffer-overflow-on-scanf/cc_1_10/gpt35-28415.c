//FormAI DATASET v1.0 Category: Robot movement control ; Style: systematic
#include <stdio.h>

// function prototypes
void move_forward(int steps);
void move_backward(int steps);
void turn_left();
void turn_right();

int main() {
    int choice, steps;
    printf("ROBOT MOVEMENT CONTROL\n");
    printf("======================\n");
    printf("Select a direction (1-4):\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter number of steps: ");
            scanf("%d", &steps);
            move_forward(steps);
            break;
        case 2:
            printf("Enter number of steps: ");
            scanf("%d", &steps);
            move_backward(steps);
            break;
        case 3:
            turn_left();
            break;
        case 4:
            turn_right();
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}

void move_forward(int steps) {
    printf("Moving forward %d steps...\n", steps);
    // code to actually move robot forward
}

void move_backward(int steps) {
    printf("Moving backward %d steps...\n", steps);
    // code to actually move robot backward
}

void turn_left() {
    printf("Turning left...\n");
    // code to actually turn robot left
}

void turn_right() {
    printf("Turning right...\n");
    // code to actually turn robot right
}