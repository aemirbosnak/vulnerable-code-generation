//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef enum {
    TAKEOFF,
    LAND,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    HOVER,
    QUIT
} Command;

void takeoff() {
    printf("Drone is taking off...\n");
    sleep(2);
    printf("Drone is now in the air!\n");
}

void land() {
    printf("Drone is landing...\n");
    sleep(2);
    printf("Drone has landed safely.\n");
}

void move_forward() {
    printf("Drone is moving forward...\n");
    sleep(1);
    printf("Drone has moved forward.\n");
}

void move_backward() {
    printf("Drone is moving backward...\n");
    sleep(1);
    printf("Drone has moved backward.\n");
}

void move_left() {
    printf("Drone is moving left...\n");
    sleep(1);
    printf("Drone has moved left.\n");
}

void move_right() {
    printf("Drone is moving right...\n");
    sleep(1);
    printf("Drone has moved right.\n");
}

void hover() {
    printf("Drone is hovering in place...\n");
    sleep(2);
    printf("Drone is still hovering.\n");
}

Command get_command() {
    int input;
    printf("Enter command (0: Takeoff, 1: Land, 2: Forward, 3: Backward, 4: Left, 5: Right, 6: Hover, 7: Quit): ");
    scanf("%d", &input);

    if (input < 0 || input > 7) {
        printf("Invalid command. Try again.\n");
        return get_command();
    }
    return (Command)input;
}

int main() {
    bool isFlying = false;
    printf("Welcome to the Drone Remote Control Program!\n");

    while (true) {
        Command cmd = get_command();

        switch (cmd) {
            case TAKEOFF:
                if (!isFlying) {
                    takeoff();
                    isFlying = true;
                } else {
                    printf("Drone already in the air!\n");
                }
                break;

            case LAND:
                if (isFlying) {
                    land();
                    isFlying = false;
                } else {
                    printf("Drone is already on the ground!\n");
                }
                break;

            case FORWARD:
                if (isFlying) {
                    move_forward();
                } else {
                    printf("Drone is on the ground! Take off first!\n");
                }
                break;

            case BACKWARD:
                if (isFlying) {
                    move_backward();
                } else {
                    printf("Drone is on the ground! Take off first!\n");
                }
                break;

            case LEFT:
                if (isFlying) {
                    move_left();
                } else {
                    printf("Drone is on the ground! Take off first!\n");
                }
                break;

            case RIGHT:
                if (isFlying) {
                    move_right();
                } else {
                    printf("Drone is on the ground! Take off first!\n");
                }
                break;

            case HOVER:
                if (isFlying) {
                    hover();
                } else {
                    printf("Drone is on the ground! Take off first!\n");
                }
                break;

            case QUIT:
                printf("Exiting the Drone Remote Control Program. Goodbye!\n");
                exit(0);
                break;
        }
    }

    return 0;
}