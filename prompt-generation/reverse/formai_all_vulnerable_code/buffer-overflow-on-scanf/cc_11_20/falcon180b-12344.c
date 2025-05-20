//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 90
#define MIN_TURN -90

#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3
#define STOP 4

int main() {
    int speed = 0;
    int turn = 0;
    int direction = FORWARD;
    int choice;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Stop\n");

    while (1) {
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                speed = MAX_SPEED;
                turn = 0;
                break;
            case 2:
                speed = -MAX_SPEED;
                turn = 0;
                break;
            case 3:
                turn = MAX_TURN;
                speed = 0;
                break;
            case 4:
                turn = -MAX_TURN;
                speed = 0;
                break;
            case 5:
                speed = 0;
                turn = 0;
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (speed!= 0) {
            if (direction == FORWARD) {
                printf("Moving forward at %d units/second.\n", speed);
            } else {
                printf("Moving backward at %d units/second.\n", speed);
            }
        } else if (turn!= 0) {
            if (turn > 0) {
                printf("Turning right at %d degrees/second.\n", turn);
            } else {
                printf("Turning left at %d degrees/second.\n", -turn);
            }
        } else {
            printf("Stopped.\n");
        }

        if (speed!= 0 || turn!= 0) {
            int random = rand() % 100;
            if (random > 50) {
                printf("Obstacle detected. Vehicle stopped.\n");
                speed = 0;
                turn = 0;
            }
        }

        if (speed == 0 && turn == 0) {
            printf("Press any key to continue...\n");
            getchar();
        }
    }

    return 0;
}