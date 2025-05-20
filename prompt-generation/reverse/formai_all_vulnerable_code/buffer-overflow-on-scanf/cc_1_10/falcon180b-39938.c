//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define LEFT_MOTOR 1
#define RIGHT_MOTOR 2
#define FORWARD_SPEED 100
#define BACKWARD_SPEED -100
#define TURN_SPEED 50
#define STRAIGHT_SPEED 0
#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} Point;

void move(int speed, int duration, bool turn) {
    int i;
    for (i = 0; i < duration; i++) {
        if (turn) {
            printf("Turning...\n");
        } else {
            printf("Moving forward...\n");
        }
        usleep(33333); // Sleep for 33 milliseconds
    }
    printf("Stopped.\n");
}

void turn(int speed, int duration) {
    int i;
    for (i = 0; i < duration; i++) {
        printf("Turning...\n");
        usleep(33333); // Sleep for 33 milliseconds
    }
    printf("Stopped.\n");
}

int main() {
    int choice;
    Point current_position = {0, 0};
    bool is_moving = FALSE;

    do {
        printf("Current position: (%d, %d)\n", current_position.x, current_position.y);
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move(FORWARD_SPEED, 10, FALSE);
                current_position.x += 10 * FORWARD_SPEED / PI;
                current_position.y += 10 * FORWARD_SPEED / PI;
                break;
            case 2:
                turn(TURN_SPEED, 5);
                current_position.x += 5 * TURN_SPEED / PI;
                current_position.y -= 5 * TURN_SPEED / PI;
                break;
            case 3:
                turn(TURN_SPEED, 5);
                current_position.x -= 5 * TURN_SPEED / PI;
                current_position.y += 5 * TURN_SPEED / PI;
                break;
            case 4:
                is_moving = FALSE;
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (TRUE);

    return 0;
}