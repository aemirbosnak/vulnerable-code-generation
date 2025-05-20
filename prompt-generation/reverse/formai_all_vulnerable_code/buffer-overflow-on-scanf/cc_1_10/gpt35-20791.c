//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>

/*
* This program simulates a remote control for a drone
*/

// function declarations
void ascend();
void descend();
void forward();
void backward();
void left();
void right();
void stop();

int main() {
    char input;

    printf("Welcome to the drone remote control program!\n");

    while (1) {
        printf("\nPlease enter a command (a - ascend, d - descend, f - forward, b - backward, l - left, r - right, s - stop): ");
        scanf(" %c", &input);

        switch (input) {
            case 'a':
                ascend();
                break;
            case 'd':
                descend();
                break;
            case 'f':
                forward();
                break;
            case 'b':
                backward();
                break;
            case 'l':
                left();
                break;
            case 'r':
                right();
                break;
            case 's':
                stop();
                break;
            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}

void ascend() {
    printf("Drone ascending...\n");
}

void descend() {
    printf("Drone descending...\n");
}

void forward() {
    printf("Drone moving forward...\n");
}

void backward() {
    printf("Drone moving backward...\n");
}

void left() {
    printf("Drone moving left...\n");
}

void right() {
    printf("Drone moving right...\n");
}

void stop() {
    printf("Drone stopped.\n");
}