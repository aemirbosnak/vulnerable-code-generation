//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_DRONES 10
#define COMMAND_LENGTH 256
#define USER_LENGTH 20

typedef struct {
    int id;
    char name[USER_LENGTH];
    int x, y;
    int isActive;
} Drone;

Drone drones[MAX_DRONES];

void* control_drone(void* arg) {
    Drone* drone = (Drone*) arg;
    char command[COMMAND_LENGTH];

    while (drone->isActive) {
        printf("%s's Drone [%d] - Current Position: (%d, %d)\n", drone->name, drone->id, drone->x, drone->y);
        printf("Enter command for Drone %d (move [x] [y] / status / exit): ", drone->id);
        fgets(command, COMMAND_LENGTH, stdin);

        if (strncmp(command, "move", 4) == 0) {
            int new_x, new_y;
            sscanf(command + 5, "%d %d", &new_x, &new_y);
            drone->x = new_x;
            drone->y = new_y;
            printf("Drone %d moved to (%d, %d)\n", drone->id, drone->x, drone->y);
        } else if (strncmp(command, "status", 6) == 0) {
            printf("Drone %d currently at position (%d, %d)\n", drone->id, drone->x, drone->y);
        } else if (strncmp(command, "exit", 4) == 0) {
            drone->isActive = 0;
            printf("%s's Drone [%d] is shutting down.\n", drone->name, drone->id);
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
    return NULL;
}

int main() {
    int numDrones;
    printf("Enter number of drones to control (1 to %d): ", MAX_DRONES);
    scanf("%d", &numDrones);

    if (numDrones < 1 || numDrones > MAX_DRONES) {
        printf("Invalid number of drones! Exiting.\n");
        return 1;
    }

    pthread_t threads[MAX_DRONES];

    for (int i = 0; i < numDrones; i++) {
        drones[i].id = i + 1;
        printf("Enter name for Drone %d: ", drones[i].id);
        scanf("%s", drones[i].name);
        drones[i].x = 0;
        drones[i].y = 0;
        drones[i].isActive = 1;

        if (pthread_create(&threads[i], NULL, control_drone, (void*)&drones[i]) != 0) {
            fprintf(stderr, "Error creating thread for Drone %d\n", drones[i].id);
            return 1;
        }
    }

    for (int i = 0; i < numDrones; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All drones have been shut down. Exiting program.\n");
    return 0;
}