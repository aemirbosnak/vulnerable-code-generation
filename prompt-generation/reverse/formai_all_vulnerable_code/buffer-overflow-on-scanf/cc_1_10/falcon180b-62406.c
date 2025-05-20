//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 1
#define MAX_TURN 100
#define MIN_TURN 1
#define FREQUENCY 50

enum {
    FORWARD = 0,
    BACKWARD = 1,
    LEFT = 2,
    RIGHT = 3,
    STOP = 4
};

void move(int direction, int speed, int turn) {
    printf("Moving %d at %d speed with %d turn\n", direction, speed, turn);
}

int main() {
    int choice;
    int speed = MAX_SPEED;
    int turn = MAX_TURN;

    printf("Welcome to the remote control vehicle simulator!\n");
    printf("Choose an action:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Change speed\n");
    printf("6. Change turn\n");
    printf("7. Stop\n");

    while (1) {
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(FORWARD, speed, turn);
                break;
            case 2:
                move(BACKWARD, speed, turn);
                break;
            case 3:
                move(LEFT, speed, turn);
                break;
            case 4:
                move(RIGHT, speed, turn);
                break;
            case 5:
                printf("Enter new speed (1-%d): ", MAX_SPEED);
                scanf("%d", &speed);
                printf("New speed set to %d\n", speed);
                break;
            case 6:
                printf("Enter new turn (1-%d): ", MAX_TURN);
                scanf("%d", &turn);
                printf("New turn set to %d\n", turn);
                break;
            case 7:
                move(STOP, 0, 0);
                break;
            default:
                printf("Invalid choice\n");
        }

        usleep(1000000 / FREQUENCY);
    }

    return 0;
}