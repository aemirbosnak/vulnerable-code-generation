//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to hold drone data
typedef struct Drone {
    int x;
    int y;
    int z;
    int speed;
} Drone;

// Function to move drone in x axis
void moveX(Drone* drone, int distance) {
    drone->x += distance;
}

// Function to move drone in y axis
void moveY(Drone* drone, int distance) {
    drone->y += distance;
}

// Function to move drone in z axis
void moveZ(Drone* drone, int distance) {
    drone->z += distance;
}

// Function to set drone speed
void setSpeed(Drone* drone, int speed) {
    drone->speed = speed;
}

// Function to print drone data
void printData(Drone drone) {
    printf("Drone position: (%d, %d, %d)\n", drone.x, drone.y, drone.z);
    printf("Drone speed: %d\n", drone.speed);
}

int main() {
    // Create drone object
    Drone drone = {.x = 0, .y = 0, .z = 0, .speed = 10};

    int choice = 0;
    int distance = 0;

    // Main loop
    while (1) {
        // Print menu and get user input
        printf("\nEnter your choice:\n");
        printf("1. Move drone in x axis\n");
        printf("2. Move drone in y axis\n");
        printf("3. Move drone in z axis\n");
        printf("4. Set drone speed\n");
        printf("5. Print drone data\n");
        printf("6. Exit program\n");
        scanf("%d", &choice);

        // Process user input
        switch(choice) {
            case 1:
                printf("Enter distance to move in x axis: ");
                scanf("%d", &distance);
                moveX(&drone, distance);
                break;
            case 2:
                printf("Enter distance to move in y axis: ");
                scanf("%d", &distance);
                moveY(&drone, distance);
                break;
            case 3:
                printf("Enter distance to move in z axis: ");
                scanf("%d", &distance);
                moveZ(&drone, distance);
                break;
            case 4:
                printf("Enter speed of drone: ");
                scanf("%d", &distance);
                setSpeed(&drone, distance);
                break;
            case 5:
                printData(drone);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}