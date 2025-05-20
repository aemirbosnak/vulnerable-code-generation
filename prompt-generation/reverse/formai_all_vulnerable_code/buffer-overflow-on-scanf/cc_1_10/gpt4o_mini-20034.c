//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    float altitude; // Drone altitude in meters
    float latitude; // Drone latitude (for simplicity, treated as x-coordinate)
    float longitude; // Drone longitude (for simplicity, treated as y-coordinate)
} Drone;

void initializeDrone(Drone* drone) {
    drone->altitude = 0.0;
    drone->latitude = 0.0;
    drone->longitude = 0.0;
    printf("The drone is peacefully initialized at a serene location.\n");
}

void ascend(Drone* drone) {
    drone->altitude += 1.0; // Ascend 1 meter
    printf("The drone ascends gracefully to an altitude of %.2f meters.\n", drone->altitude);
}

void descend(Drone* drone) {
    if (drone->altitude > 0.0) {
        drone->altitude -= 1.0; // Descend 1 meter
        printf("The drone descends gently to an altitude of %.2f meters.\n", drone->altitude);
    } else {
        printf("The drone is already at ground level. It cannot descend further.\n");
    }
}

void moveLeft(Drone* drone) {
    drone->longitude -= 1.0; // Move left
    printf("The drone glides smoothly to the left, now at longitude: %.2f.\n", drone->longitude);
}

void moveRight(Drone* drone) {
    drone->longitude += 1.0; // Move right
    printf("The drone glides effortlessly to the right, now at longitude: %.2f.\n", drone->longitude);
}

void land(Drone* drone) {
    if (drone->altitude > 0.0) {
        drone->altitude = 0.0; // Land the drone
        printf("The drone lands softly on the ground, now at an altitude of %.2f meters.\n", drone->altitude);
    } else {
        printf("The drone is already on the ground.\n");
    }
}

void showMenu() {
    printf("\n=== Peaceful Drone Control Menu ===\n");
    printf("1. Ascend\n");
    printf("2. Descend\n");
    printf("3. Move Left\n");
    printf("4. Move Right\n");
    printf("5. Land\n");
    printf("6. Exit\n");
    printf("Please choose an option (1-6): ");
}

int main() {
    Drone myDrone;
    initializeDrone(&myDrone);
    
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ascend(&myDrone);
                break;
            case 2:
                descend(&myDrone);
                break;
            case 3:
                moveLeft(&myDrone);
                break;
            case 4:
                moveRight(&myDrone);
                break;
            case 5:
                land(&myDrone);
                break;
            case 6:
                printf("Thank you for flying with us. Wishing you peace and tranquility!\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 6.\n");
        }
        sleep(1); // Give a moment of tranquility
    } while (choice != 6);
    
    return 0;
}