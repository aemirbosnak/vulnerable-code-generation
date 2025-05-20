//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void forward(int speed);
void backward(int speed);
void turn_left(int angle);
void turn_right(int angle);
void stop();

int main() {
    int speed = 0;
    int angle = 0;
    bool is_running = true;

    printf("Remote control vehicle simulation\n");

    while (is_running) {
        char command;
        printf("Enter a command (f to move forward, b to move backward, l to turn left, r to turn right, s to stop, q to quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                forward(speed);
                break;
            case 'b':
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                backward(speed);
                break;
            case 'l':
                printf("Enter angle (0-90): ");
                scanf("%d", &angle);
                turn_left(angle);
                break;
            case 'r':
                printf("Enter angle (0-90): ");
                scanf("%d", &angle);
                turn_right(angle);
                break;
            case 's':
                stop();
                break;
            case 'q':
                is_running = false;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}

void forward(int speed) {
    printf("Moving forward at speed %d\n", speed);
}

void backward(int speed) {
    printf("Moving backward at speed %d\n", speed);
}

void turn_left(int angle) {
    printf("Turning left at angle %d\n", angle);
}

void turn_right(int angle) {
    printf("Turning right at angle %d\n", angle);
}

void stop() {
    printf("Stopping\n");
}