//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MAX_TURN 100
#define MIN_SPEED -MAX_SPEED
#define MIN_TURN -MAX_TURN

struct vehicle {
    int speed;
    int turn;
};

void move_vehicle(struct vehicle *v, int direction, int speed) {
    if (direction == 0) {
        v->speed = speed;
    } else if (direction == 1) {
        v->turn = speed;
    } else {
        printf("Invalid direction\n");
    }
}

int main() {
    struct vehicle vehicle;
    int direction, speed;

    printf("Enter initial speed (0-100): ");
    scanf("%d", &vehicle.speed);

    printf("Enter initial turn (0-100): ");
    scanf("%d", &vehicle.turn);

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Display current state\n");
        printf("5. Exit\n");

        scanf("%d", &direction);

        switch (direction) {
        case 1:
            printf("Enter speed (0-100): ");
            scanf("%d", &speed);
            move_vehicle(&vehicle, 0, speed);
            break;

        case 2:
            printf("Enter turn speed (0-100): ");
            scanf("%d", &speed);
            move_vehicle(&vehicle, 1, speed);
            break;

        case 3:
            printf("Enter turn speed (0-100): ");
            scanf("%d", &speed);
            move_vehicle(&vehicle, 2, speed);
            break;

        case 4:
            printf("Current speed: %d\n", vehicle.speed);
            printf("Current turn: %d\n", vehicle.turn);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}