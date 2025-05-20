//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define possible drone actions
#define TAKE_OFF 0
#define LAND 1
#define GO_UP 2
#define GO_DOWN 3
#define GO_LEFT 4
#define GO_RIGHT 5

// Define drone state variables
int altitude = 0;
int x_position = 0;
int y_position = 0;
int landed = 1;

// Dummy function to simulate drone movement
void move(int x, int y, int z) {
    printf("Drone moved to position x=%d,y=%d,z=%d.\n", x, y, z);
}

// Thread function to handle drone movement
void *flight_controller(void *arg) {
    int action;
    while(1) {
        // Wait for instruction
        printf("Waiting for instruction...\n");
        scanf("%d", &action);
        
        // Take appropriate action
        if(action == TAKE_OFF) {
            if(landed) {
                move(0, 0, 10);
                altitude = 10;
                landed = 0;
            } else {
                printf("Drone is already in the air.\n");
            }
        } else if(action == LAND) {
            if(!landed) {
                move(0, 0, -altitude);
                altitude = 0;
                landed = 1;
            } else {
                printf("Drone is already on the ground.\n");
            }
        } else if(action == GO_UP) {
            if(!landed) {
                move(x_position, y_position, altitude + 10);
                altitude += 10;
            } else {
                printf("Drone can't move while landed.\n");
            }
        } else if(action == GO_DOWN) {
            if(!landed) {
                move(x_position, y_position, altitude - 10);
                altitude -= 10;
            } else {
                printf("Drone can't move while landed.\n");
            }
        } else if(action == GO_LEFT) {
            if(!landed) {
                move(x_position - 10, y_position, altitude);
                x_position -= 10;
            } else {
                printf("Drone can't move while landed.\n");
            }
        } else if(action == GO_RIGHT) {
            if(!landed) {
                move(x_position + 10, y_position, altitude);
                x_position += 10;
            } else {
                printf("Drone can't move while landed.\n");
            }
        } else {
            printf("Invalid action.\n");
        }
        
        // Wait before next action
        usleep(500000);
    }
}

// Main function to start flight controller thread
int main() {
    pthread_t thread_id;
    int status;
    status = pthread_create(&thread_id, NULL, flight_controller, NULL);
    if(status != 0) {
        printf("Failed to start flight controller thread.\n");
        exit(EXIT_FAILURE);
    }
    while(1) {
        printf("Drone remote control program running...\n");
        sleep(1);
    }
    return 0;
}