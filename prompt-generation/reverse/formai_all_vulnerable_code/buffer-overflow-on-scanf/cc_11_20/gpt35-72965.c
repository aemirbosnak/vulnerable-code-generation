//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10

int main() {
    int drones[MAX_DRONES] = {0};
    int drone_id, option, i;

    printf("Welcome to C Drone Remote Control Program!\n");

    while (1) {
        printf("\nAvailable Drones:\n");

        for (i = 0; i < MAX_DRONES; i++) {
            if (drones[i] == 0) {
                printf("[%d] - Available\n", i);
            } else {
                printf("[%d] - In Use (by user %d)\n", i, drones[i]);
            }
        }

        printf("\nEnter an option:\n");
        printf("[1] - Request Drone\n");
        printf("[2] - Release Drone\n");
        printf("[3] - Quit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter Drone ID to Request:\n");
                scanf("%d", &drone_id);

                if (drone_id < 0 || drone_id >= MAX_DRONES) {
                    printf("\nInvalid Drone ID.\n");
                } else if (drones[drone_id] != 0) {
                    printf("\nDrone is already in use. Please select another one.\n");
                } else {
                    printf("\nDrone %d has been allocated for your use.\n", drone_id);
                    drones[drone_id] = 1; // set drone to "in use"
                }
                break;
            case 2:
                printf("\nEnter Drone ID to Release:\n");
                scanf("%d", &drone_id);

                if (drone_id < 0 || drone_id >= MAX_DRONES) {
                    printf("\nInvalid Drone ID.\n");
                } else if (drones[drone_id] == 0) {
                    printf("\nDrone is already available. Please select another one to release.\n");
                } else {
                    printf("\nDrone %d has been released successfully.\n", drone_id);
                    drones[drone_id] = 0; // set drone to "available"
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}