//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void move_forward(int speed) {
    printf("Moving forward at speed %d\n", speed);
}

void move_backward(int speed) {
    printf("Moving backward at speed %d\n", speed);
}

void turn_left(int degree) {
    printf("Turning left by %d degrees\n", degree);
}

void turn_right(int degree) {
    printf("Turning right by %d degrees\n", degree);
}

int main() {
    int speed = 0, degree = 0;
    bool is_running = true;

    while (is_running) {
        printf("Enter a command:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");

        int command;
        scanf("%d", &command);
        switch (command) {
            case 1:
                printf("Enter speed: ");
                scanf("%d", &speed);
                move_forward(speed);
                break;
            case 2:
                printf("Enter speed: ");
                scanf("%d", &speed);
                move_backward(speed);
                break;
            case 3:
                printf("Enter degree: ");
                scanf("%d", &degree);
                turn_left(degree);
                break;
            case 4:
                printf("Enter degree: ");
                scanf("%d", &degree);
                turn_right(degree);
                break;
            case 5:
                is_running = false;
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        usleep(100000); // wait for 100ms
        system("clear"); // clear console
    }

    return 0;
}