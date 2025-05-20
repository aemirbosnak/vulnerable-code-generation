//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the drone
void initialize_drone() {
    printf("Drone initialized\n");
}

// Function to take off the drone
void take_off() {
    printf("Drone taking off...\n");
}

// Function to land the drone
void land() {
    printf("Drone landing...\n");
}

// Function to move the drone forward
void move_forward(int distance) {
    printf("Drone moving forward %d meters...\n", distance);
}

// Function to move the drone backward
void move_backward(int distance) {
    printf("Drone moving backward %d meters...\n", distance);
}

// Function to rotate the drone clockwise
void rotate_clockwise(int degrees) {
    printf("Drone rotating clockwise %d degrees...\n", degrees);
}

// Function to rotate the drone counter-clockwise
void rotate_counter_clockwise(int degrees) {
    printf("Drone rotating counter-clockwise %d degrees...\n", degrees);
}

int main()
{
    char input;
    int distance, degrees;

    initialize_drone();
    take_off();

    while(1) {
        printf("Enter a command (f = forward, b = backward, c = clockwise, o = counter-clockwise, l = land): ");
        scanf("%c", &input);
        fflush(stdin);

        switch(input) {
            case 'f':
                printf("Enter the distance to move forward (in meters): ");
                scanf("%d", &distance);
                move_forward(distance);
                break;
            case 'b':
                printf("Enter the distance to move backward (in meters): ");
                scanf("%d", &distance);
                move_backward(distance);
                break;
            case 'c':
                printf("Enter the degrees to rotate clockwise: ");
                scanf("%d", &degrees);
                rotate_clockwise(degrees);
                break;
            case 'o':
                printf("Enter the degrees to rotate counter-clockwise: ");
                scanf("%d", &degrees);
                rotate_counter_clockwise(degrees);
                break;
            case 'l':
                land();
                exit(0);
                break;
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}