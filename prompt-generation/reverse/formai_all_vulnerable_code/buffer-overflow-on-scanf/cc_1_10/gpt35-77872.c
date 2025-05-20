//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
bool stop = false;

void* rc_vehicle(void* arg) {
    srand(time(NULL));
    int left_motor, right_motor;
    while(!stop) {
        pthread_mutex_lock(&lock);
        left_motor = rand() % 11 - 5;
        right_motor = rand() % 11 - 5;
        printf("Left Motor: %d, Right Motor: %d\n", left_motor, right_motor);
        pthread_mutex_unlock(&lock);
        usleep(500000);
    }
    return NULL;
}

void* remote_control(void* arg) {
    char input;
    while(!stop) {
        printf("Enter W, A, S, or D to control the vehicle, or X to stop: ");
        scanf(" %c", &input);
        switch(input) {
            case 'w':
            case 'W':
                printf("Moving forward.\n");
                break;
            case 'a':
            case 'A':
                printf("Turning left.\n");
                break;
            case 's':
            case 'S':
                printf("Moving backward.\n");
                break;
            case 'd':
            case 'D':
                printf("Turning right.\n");
                break;
            case 'x':
            case 'X':
                printf("Stopping vehicle.\n");
                pthread_mutex_lock(&lock);
                stop = true;
                pthread_mutex_unlock(&lock);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
        usleep(500000);
    }
    return NULL;
}

int main() {
    pthread_t vehicle, control;
    pthread_create(&vehicle, NULL, rc_vehicle, NULL);
    pthread_create(&control, NULL, remote_control, NULL);
    pthread_join(vehicle, NULL);
    pthread_join(control, NULL);
    return 0;
}