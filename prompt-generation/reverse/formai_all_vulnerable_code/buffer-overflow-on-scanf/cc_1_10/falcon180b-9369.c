//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define TURN_RATE 10
#define FORWARD 1
#define BACKWARD -1
#define LEFT -1
#define RIGHT 1
#define STOP 0

typedef struct {
    int speed;
    int direction;
} vehicle_t;

void move_vehicle(vehicle_t *vehicle, int speed, int direction) {
    printf("Moving vehicle with speed %d and direction %d\n", speed, direction);
    if (speed > MAX_SPEED) {
        speed = MAX_SPEED;
    } else if (speed < MIN_SPEED) {
        speed = MIN_SPEED;
    }
    if (direction == FORWARD) {
        printf("Vehicle moving forward\n");
    } else if (direction == BACKWARD) {
        printf("Vehicle moving backward\n");
    } else if (direction == LEFT) {
        printf("Vehicle turning left\n");
    } else if (direction == RIGHT) {
        printf("Vehicle turning right\n");
    } else {
        printf("Vehicle stopped\n");
    }
}

int main() {
    srand(time(NULL));
    vehicle_t vehicle;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        scanf("%d", &choice);

        int speed = rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
        int direction;

        switch (choice) {
            case 1:
                direction = FORWARD;
                break;
            case 2:
                direction = BACKWARD;
                break;
            case 3:
                direction = LEFT;
                break;
            case 4:
                direction = RIGHT;
                break;
            case 5:
                direction = STOP;
                break;
            default:
                direction = STOP;
                break;
        }

        move_vehicle(&vehicle, speed, direction);

        usleep(100000);  // pause for a short time

    } while (1);

    return 0;
}