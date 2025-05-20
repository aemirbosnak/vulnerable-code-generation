//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int aileron;
    int elevator;
    int throttle;
    int rudder;
    int arm;
    int disarm;
} remote_control_t;

remote_control_t remote_control = {0, 0, 0, 0, 0, 0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* drone_controller(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int aileron = remote_control.aileron;
        int elevator = remote_control.elevator;
        int throttle = remote_control.throttle;
        int rudder = remote_control.rudder;
        int arm = remote_control.arm;
        int disarm = remote_control.disarm;
        pthread_mutex_unlock(&mutex);

        if (arm && !disarm) {
            printf("Drone is armed\n");
        } else if (disarm && !arm) {
            printf("Drone is disarmed\n");
        } else {
            if (aileron < -100 || aileron > 100 ||
                elevator < -100 || elevator > 100 ||
                throttle < 0 || throttle > 100 ||
                rudder < -100 || rudder > 100) {
                printf("Invalid command received\n");
            } else {
                printf("Drone is flying - Aileron: %d, Elevator: %d, Throttle: %d, Rudder: %d\n", aileron, elevator, throttle, rudder);
                // Send commands to the drone
                // ...
                // ...
                // ...
            }
        }

        usleep(50000);
    }
}

void* remote_controller(void* arg) {
    while (1) {
        char input[100];
        fgets(input, 100, stdin);

        if (strcmp(input, "arm\n") == 0) {
            pthread_mutex_lock(&mutex);
            remote_control.arm = 1;
            remote_control.disarm = 0;
            pthread_mutex_unlock(&mutex);
        } else if (strcmp(input, "disarm\n") == 0) {
            pthread_mutex_lock(&mutex);
            remote_control.arm = 0;
            remote_control.disarm = 1;
            pthread_mutex_unlock(&mutex);
        } else {
            sscanf(input, "%d %d %d %d", &remote_control.aileron, &remote_control.elevator, &remote_control.throttle, &remote_control.rudder);
            pthread_mutex_lock(&mutex);
            remote_control.arm = 0;
            remote_control.disarm = 0;
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main() {
    pthread_t drone_controller_thread;
    pthread_create(&drone_controller_thread, NULL, drone_controller, NULL);

    pthread_t remote_controller_thread;
    pthread_create(&remote_controller_thread, NULL, remote_controller, NULL);

    pthread_join(drone_controller_thread, NULL);
    pthread_join(remote_controller_thread, NULL);

    return 0;
}