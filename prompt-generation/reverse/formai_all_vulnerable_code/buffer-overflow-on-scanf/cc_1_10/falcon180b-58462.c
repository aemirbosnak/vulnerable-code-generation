//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 90
#define MIN_TURN 1
#define MAX_DISTANCE 100
#define MIN_DISTANCE 1

struct vehicle {
    int speed;
    int turn;
    int distance;
};

void init_vehicle(struct vehicle *v) {
    v->speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    v->turn = rand() % (MAX_TURN - MIN_TURN + 1) + MIN_TURN;
    v->distance = 0;
}

void move_vehicle(struct vehicle *v) {
    v->distance += v->speed;
    if (v->distance >= MAX_DISTANCE) {
        v->distance = MAX_DISTANCE;
    } else if (v->distance <= MIN_DISTANCE) {
        v->distance = MIN_DISTANCE;
    }
}

void turn_vehicle(struct vehicle *v, int direction) {
    v->turn += direction;
    if (v->turn >= MAX_TURN) {
        v->turn = MAX_TURN;
    } else if (v->turn <= MIN_TURN) {
        v->turn = MIN_TURN;
    }
}

int main() {
    srand(time(NULL));

    struct vehicle my_vehicle;
    init_vehicle(&my_vehicle);

    int choice;
    do {
        printf("Choose an action:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Check status\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_vehicle(&my_vehicle);
                printf("You moved %d units.\n", my_vehicle.speed);
                break;
            case 2:
                turn_vehicle(&my_vehicle, -1);
                printf("You turned %d degrees to the left.\n", my_vehicle.turn);
                break;
            case 3:
                turn_vehicle(&my_vehicle, 1);
                printf("You turned %d degrees to the right.\n", my_vehicle.turn);
                break;
            case 4:
                printf("Your current speed is %d, your current turn is %d degrees, and you have moved %d units.\n", my_vehicle.speed, my_vehicle.turn, my_vehicle.distance);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}