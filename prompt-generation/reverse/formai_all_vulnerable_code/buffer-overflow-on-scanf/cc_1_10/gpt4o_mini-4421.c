//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    float altitude; // Altitude in meters
    float positionX; // X position in meters
    float positionY; // Y position in meters
    float positionZ; // Z position in meters
} Drone;

void printStatus(Drone *drone) {
    printf("Drone Status:\n");
    printf("Altitude: %.2f m\n", drone->altitude);
    printf("Position (X, Y, Z): (%.2f, %.2f, %.2f)\n", drone->positionX, drone->positionY, drone->positionZ);
}

void moveUp(Drone *drone) {
    drone->altitude += 1.0;
    printf("Moving Up...\n");
}

void moveDown(Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude -= 1.0;
        printf("Moving Down...\n");
    } else {
        printf("Drone is already at ground level!\n");
    }
}

void moveForward(Drone *drone) {
    drone->positionY += 1.0;
    printf("Moving Forward...\n");
}

void moveBackward(Drone *drone) {
    drone->positionY -= 1.0;
    printf("Moving Backward...\n");
}

void moveLeft(Drone *drone) {
    drone->positionX -= 1.0;
    printf("Moving Left...\n");
}

void moveRight(Drone *drone) {
    drone->positionX += 1.0;
    printf("Moving Right...\n");
}

void hover(Drone *drone) {
    printf("Hovering in place.\n");
}

void showMenu() {
    printf("\nDrone Control Menu:\n");
    printf("1. Move Up\n");
    printf("2. Move Down\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Hover\n");
    printf("8. Exit\n");
}

int main() {
    Drone drone = {0.0, 0.0, 0.0, 0.0}; // Initializing drone at ground level and origin
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveUp(&drone);
                break;
            case 2:
                moveDown(&drone);
                break;
            case 3:
                moveForward(&drone);
                break;
            case 4:
                moveBackward(&drone);
                break;
            case 5:
                moveLeft(&drone);
                break;
            case 6:
                moveRight(&drone);
                break;
            case 7:
                hover(&drone);
                break;
            case 8:
                printf("Exiting the program. Safe flying!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printStatus(&drone);
        usleep(500000); // Adding a delay for better readability
    }

    return 0;
}