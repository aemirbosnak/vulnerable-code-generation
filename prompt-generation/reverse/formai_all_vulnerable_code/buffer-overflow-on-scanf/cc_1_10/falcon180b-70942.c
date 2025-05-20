//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Cyberpunk Drone Remote Control Program

int main() {
    char input[50];
    int choice;

    // Initialize Drone
    printf("INITIALIZING DRONE...\n");
    printf("CONNECTING TO NETWORK...\n");
    printf("SCANNING FOR DRONES...\n");
    printf("DRONE FOUND: X-WING-2021\n");
    printf("CONNECTING TO DRONE...\n");
    printf("CONNECTION ESTABLISHED.\n\n");

    while(1) {
        printf("ENTER COMMAND:\n");
        scanf("%s", input);

        if(strcmp(input, "takeoff") == 0) {
            printf("TAKEOFF INITIATED.\n");
        } else if(strcmp(input, "land") == 0) {
            printf("LANDING INITIATED.\n");
        } else if(strcmp(input, "move") == 0) {
            printf("MOVE DRONE:\n");
            printf("1. FORWARD\n");
            printf("2. BACKWARD\n");
            printf("3. LEFT\n");
            printf("4. RIGHT\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("DRONE MOVING FORWARD.\n");
                    break;
                case 2:
                    printf("DRONE MOVING BACKWARD.\n");
                    break;
                case 3:
                    printf("DRONE MOVING LEFT.\n");
                    break;
                case 4:
                    printf("DRONE MOVING RIGHT.\n");
                    break;
                default:
                    printf("INVALID CHOICE.\n");
            }
        } else if(strcmp(input, "quit") == 0) {
            printf("SHUTTING DOWN DRONE REMOTE CONTROL...\n");
            break;
        } else {
            printf("INVALID COMMAND.\n");
        }
    }

    return 0;
}