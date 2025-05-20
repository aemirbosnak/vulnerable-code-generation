//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ROBOTS 5

int robots[NUM_ROBOTS];
int directions[NUM_ROBOTS];
int speeds[NUM_ROBOTS];
int thread_ids[NUM_THREADS];

void *robot_movement(void *arg) {
    int id = *(int *) arg;
    int robot = robots[id];
    int direction = directions[id];
    int speed = speeds[id];

    while (1) {
        if (robot == 0) {
            direction = -direction;
            speed = speed * 2;
        } else if (robot == 1) {
            direction = -direction;
            speed = speed / 2;
        } else if (robot == 2) {
            direction = -direction;
            speed = speed * 3;
        } else if (robot == 3) {
            direction = -direction;
            speed = speed / 3;
        } else if (robot == 4) {
            direction = -direction;
            speed = speed * 4;
        }

        printf("Robot %d is moving in direction %d with speed %d\n", id, direction, speed);
        fflush(stdout);
        usleep(200000);

        if (robot == 0) {
            robot = 1;
        } else if (robot == 1) {
            robot = 2;
        } else if (robot == 2) {
            robot = 3;
        } else if (robot == 3) {
            robot = 4;
        } else {
            robot = 0;
        }

        direction = -direction;
        speed = speed / 2;
    }

    return NULL;
}

int main() {
    int i;

    for (i = 0; i < NUM_ROBOTS; i++) {
        robots[i] = 0;
        directions[i] = 1;
        speeds[i] = 1;
    }

    pthread_t thread_id[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, robot_movement, (void *) i);
        printf("Thread %d created\n", i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
        printf("Thread %d exited\n", i);
    }

    return 0;
}