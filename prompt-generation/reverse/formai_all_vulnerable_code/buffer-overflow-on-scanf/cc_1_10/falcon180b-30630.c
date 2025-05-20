//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>

// Define the drone's position and speed
#define POS_X 0
#define POS_Y 0
#define SPEED 1

// Define the remote control's buttons
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

void move_drone(int button) {
    switch (button) {
        case UP:
            printf("Drone moving up...\n");
            break;
        case DOWN:
            printf("Drone moving down...\n");
            break;
        case LEFT:
            printf("Drone moving left...\n");
            break;
        case RIGHT:
            printf("Drone moving right...\n");
            break;
        case STOP:
            printf("Drone stopped.\n");
            break;
        default:
            printf("Invalid button pressed.\n");
    }
}

void fly_drone() {
    int button;

    do {
        printf("Enter button number (1-5): ");
        scanf("%d", &button);

        move_drone(button);

    } while (button!= STOP);
}

int main() {
    fly_drone();

    return 0;
}