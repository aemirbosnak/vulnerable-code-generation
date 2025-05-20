//FormAI DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MOVEMENT_THREADS 5 // Number of robot movement threads
#define X_MIN 0 // Lower limit of x-coordinate
#define X_MAX 100 // Upper limit of x-coordinate
#define Y_MIN 0 // Lower limit of y-coordinate
#define Y_MAX 100 // Upper limit of y-coordinate

pthread_barrier_t barrier; // Barrier for synchronizing threads
pthread_mutex_t mutex; // Mutex for accessing shared variables

int x_coordinate = 50; // Initial x-coordinate of the robot
int y_coordinate = 50; // Initial y-coordinate of the robot
bool is_stopped = false; // Flag to indicate if the robot is stopped

void *move_up(void *args) {
    while (true) {
        pthread_barrier_wait(&barrier);
        if (is_stopped) {
            break;
        }
        pthread_mutex_lock(&mutex);
        if (y_coordinate == Y_MAX) {
            printf("Robot cannot move up further\n");
        } else {
            y_coordinate++;
            printf("Robot moved up. New coordinates: (%d, %d)\n", x_coordinate, y_coordinate);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *move_down(void *args) {
    while (true) {
        pthread_barrier_wait(&barrier);
        if (is_stopped) {
            break;
        }
        pthread_mutex_lock(&mutex);
        if (y_coordinate == Y_MIN) {
            printf("Robot cannot move down further\n");
        } else {
            y_coordinate--;
            printf("Robot moved down. New coordinates: (%d, %d)\n", x_coordinate, y_coordinate);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *move_left(void *args) {
    while (true) {
        pthread_barrier_wait(&barrier);
        if (is_stopped) {
            break;
        }
        pthread_mutex_lock(&mutex);
        if (x_coordinate == X_MIN) {
            printf("Robot cannot move left further\n");
        } else {
            x_coordinate--;
            printf("Robot moved left. New coordinates: (%d, %d)\n", x_coordinate, y_coordinate);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *move_right(void *args) {
    while (true) {
        pthread_barrier_wait(&barrier);
        if (is_stopped) {
            break;
        }
        pthread_mutex_lock(&mutex);
        if (x_coordinate == X_MAX) {
            printf("Robot cannot move right further\n");
        } else {
            x_coordinate++;
            printf("Robot moved right. New coordinates: (%d, %d)\n", x_coordinate, y_coordinate);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *stop_robot(void *args) {
    char input[50];
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "stop") == 0) {
            is_stopped = true;
            pthread_barrier_wait(&barrier); // Unblock all movement threads
            break;
        } else {
            printf("Invalid command. Enter 'stop' to stop the robot\n");
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t movement_thread[MOVEMENT_THREADS];
    pthread_t stop_thread;
    pthread_barrier_init(&barrier, NULL, MOVEMENT_THREADS + 1); // Initialize barrier with number of threads plus the stop thread
    pthread_mutex_init(&mutex, NULL); // Initialize mutex
    int thread_ids[MOVEMENT_THREADS];

    // Create movement threads
    for (int i = 0; i < MOVEMENT_THREADS; i++) {
        thread_ids[i] = i;
        if (i == 0) {
            pthread_create(&movement_thread[i], NULL, move_up, (void *)&thread_ids[i]);
        } else if (i == 1) {
            pthread_create(&movement_thread[i], NULL, move_down, (void *)&thread_ids[i]);
        } else if (i == 2) {
            pthread_create(&movement_thread[i], NULL, move_left, (void *)&thread_ids[i]);
        } else if (i == 3) {
            pthread_create(&movement_thread[i], NULL, move_right, (void *)&thread_ids[i]);
        }
    }

    // Create stop thread
    pthread_create(&stop_thread, NULL, stop_robot, NULL);

    // Wait for all threads to complete
    for (int i = 0; i < MOVEMENT_THREADS; i++) {
        pthread_join(movement_thread[i], NULL);
    }
    pthread_join(stop_thread, NULL);

    // Destroy barrier and mutex
    pthread_barrier_destroy(&barrier);
    pthread_mutex_destroy(&mutex);

    return 0;
}