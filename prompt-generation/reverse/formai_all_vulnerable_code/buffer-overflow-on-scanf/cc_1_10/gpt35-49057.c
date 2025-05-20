//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#define NUM_THREADS 2

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* movement(void* arg) {
    printf("Vehicle movement initiated.\n");
    int distance = 0;
    int speed = 50; // in km/hr
    while (distance < 500) {
        distance += speed/10; // in meters
        printf("Vehicle moved %d meters.\n", speed/10);
        usleep(1000*1000); // 1 second delay
    }
    printf("Vehicle has reached the destination.\n");
    pthread_exit(NULL);
}

void* remote_control(void* arg) {
    printf("Remote control initiated.\n");
    int choice = 0;
    while (choice != 3) {
        printf("\nSelect an action:\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Exit remote control\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Speed increased by 10km/hr.\n");
                break;
            case 2:
                printf("Speed decreased by 10km/hr.\n");
                break;
            case 3:
                printf("Exiting remote control.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc1, rc2;

    rc1 = pthread_create(&threads[0], NULL, movement, NULL);
    if (rc1) {
        printf("Error: unable to create thread, %d\n", rc1);
        exit(-1);
    }

    rc2 = pthread_create(&threads[1], NULL, remote_control, NULL);
    if (rc2) {
        printf("Error: unable to create thread, %d\n", rc2);
        exit(-1);
    }

    pthread_exit(NULL);
    return 0;
}