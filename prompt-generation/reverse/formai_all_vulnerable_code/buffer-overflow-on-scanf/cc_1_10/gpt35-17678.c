//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3   // Number of threads used for the distributed system

/* struct for storing drone information */
typedef struct {
    int drone_id;
    float current_latitude;
    float current_longitude;
    char status[20];
} drone;

/* global variables */
int current_drone_id = 0;
drone drones[100];   // Array of drone structs

/* Function prototypes */
void *command_center(void *arg);
void *drone_controller(void *arg);
void update_drone_status(int drone_id, char *new_status);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;

    // Create the command center thread
    rc = pthread_create(&threads[0], NULL, command_center, NULL);
    if (rc) {
        printf("Error: Unable to create command center thread\n");
        exit(-1);
    }

    // Create multiple drone controller threads
    for (i = 1; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, drone_controller, (void *) (long) i);
        if (rc) {
            printf("Error: Unable to create drone controller thread %d\n", i);
            exit(-1);
        }
    }

    // Join all threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Exit program
    pthread_exit(NULL);
}

/* Thread function for the command center */
void *command_center(void *arg) {
    while(1) {
        int menu_choice;
        int selected_drone_id;
        char new_status[20];

        printf("==========================\n");
        printf("1. List all drones\n");
        printf("2. Select a drone\n");
        printf("3. Exit program\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                printf("Drone List:\n");
                printf("ID \tlatitude \tlongitude \tstatus\n");
                for (int i = 0; i < current_drone_id; i++) {
                    printf("%d \t%f \t%f \t%s\n", drones[i].drone_id, 
                        drones[i].current_latitude, drones[i].current_longitude, drones[i].status);
                }
                break;

            case 2:
                printf("Enter drone ID: ");
                scanf("%d", &selected_drone_id);
                if (selected_drone_id < 1 || selected_drone_id > current_drone_id) {
                    printf("Invalid selection\n");
                    break;
                }
                printf("Enter new status for drone %d: ", selected_drone_id);
                scanf("%s", new_status);
                update_drone_status(selected_drone_id, new_status);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid selection\n");
        }
    }
}

/* Thread function for a drone controller */
void *drone_controller(void *arg) {
    int drone_id = (int) (long) arg;
    float latitude = 0, longitude = 0;

    // Set initial drone position and status
    drones[drone_id - 1].drone_id = drone_id;
    drones[drone_id - 1].current_latitude = latitude;
    drones[drone_id - 1].current_longitude = longitude;
    sprintf(drones[drone_id - 1].status, "Idle");

    while(1) {
        // Simulate drone movements
        latitude += (float) rand() / (float) (RAND_MAX/0.0001);
        longitude += (float) rand() / (float) (RAND_MAX/0.0001);

        // Update drone position and status
        drones[drone_id - 1].current_latitude = latitude;
        drones[drone_id - 1].current_longitude = longitude;
        sleep(1);

        // Set drone status to idle or busy randomly
        if (rand() % 2 == 0) {
            sprintf(drones[drone_id - 1].status, "Idle");
        } else {
            sprintf(drones[drone_id - 1].status, "Busy");
        }
    }
}

/* Helper function for updating drone status */
void update_drone_status(int drone_id, char *new_status) {
    strncpy(drones[drone_id - 1].status, new_status, sizeof(drones[drone_id - 1].status));
    printf("Drone %d status updated to %s\n", drone_id, drones[drone_id - 1].status);
}