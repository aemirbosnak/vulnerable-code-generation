//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define STOP 5

int g_speed = 0;
int g_direction = 0;
int g_turn = 0;

void *control_vehicle(void *arg) {
    while (1) {
        usleep(100000); // 100ms delay

        if (g_speed == 0) {
            printf("Vehicle stopped\n");
        } else if (g_speed > 0) {
            printf("Vehicle moving forward\n");
        } else {
            printf("Vehicle moving backward\n");
        }

        if (g_turn == TURN_LEFT) {
            printf("Vehicle turning left\n");
        } else if (g_turn == TURN_RIGHT) {
            printf("Vehicle turning right\n");
        }
    }

    return NULL;
}

int main() {
    pthread_t thread_id;

    printf("Remote Control Vehicle Simulation\n");

    while (1) {
        printf("Enter command (0-9): ");
        scanf("%d", &g_speed);

        if (g_speed == STOP) {
            g_speed = 0;
            g_direction = 0;
            g_turn = 0;
        } else if (g_speed > 0) {
            g_direction = MOVE_FORWARD;
        } else {
            g_direction = MOVE_BACKWARD;
        }

        switch (g_speed) {
            case MOVE_FORWARD:
                printf("Vehicle moving forward\n");
                break;
            case MOVE_BACKWARD:
                printf("Vehicle moving backward\n");
                break;
            case TURN_LEFT:
                printf("Vehicle turning left\n");
                break;
            case TURN_RIGHT:
                printf("Vehicle turning right\n");
                break;
            default:
                printf("Invalid command\n");
        }

        pthread_create(&thread_id, NULL, control_vehicle, NULL);
    }

    return 0;
}