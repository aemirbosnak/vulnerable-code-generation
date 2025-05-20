//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_SPEED 100
#define MIN_SPEED 1
#define TURN_SPEED 20
#define MOVE_SPEED 50
#define STOP_SPEED 0
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT 3

typedef struct {
    int speed;
    int direction;
} Move;

void *moveRobot(void *arg) {
    Move *move = arg;
    while (1) {
        if (move->speed == STOP_SPEED) {
            usleep(100000);
            continue;
        }
        if (move->direction == FORWARD) {
            printf("Moving forward at %d speed\n", move->speed);
            usleep(100000 - (MAX_SPEED - move->speed));
        } else if (move->direction == BACKWARD) {
            printf("Moving backward at %d speed\n", move->speed);
            usleep(100000 - (MAX_SPEED - move->speed));
        } else if (move->direction == LEFT) {
            printf("Turning left at %d speed\n", TURN_SPEED);
            usleep(100000 - TURN_SPEED);
        } else if (move->direction == RIGHT) {
            printf("Turning right at %d speed\n", TURN_SPEED);
            usleep(100000 - TURN_SPEED);
        }
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    Move move;

    printf("Enter the initial speed (1-100): ");
    scanf("%d", &move.speed);

    printf("Enter the initial direction (1:forward, 2:left, 3:right, 0:stop): ");
    scanf("%d", &move.direction);

    pthread_create(&thread_id, NULL, moveRobot, &move);

    while (1) {
        printf("Enter the new speed (1-100): ");
        scanf("%d", &move.speed);

        printf("Enter the new direction (1:forward, 2:left, 3:right, 0:stop): ");
        scanf("%d", &move.direction);
    }

    return 0;
}