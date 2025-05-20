//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    float x;
    float y;
    float z;
} Position;

typedef struct {
    Position pos;
    int batteryLevel;
} Drone;

void initializeDrone(Drone *drone) {
    drone->pos.x = 0;
    drone->pos.y = 0;
    drone->pos.z = 0;
    drone->batteryLevel = 100; // Initial battery level
}

void displayMenu() {
    printf("\nDrone Control Menu:\n");
    printf("1. Move Up\n");
    printf("2. Move Down\n");
    printf("3. Move Left\n");
    printf("4. Move Right\n");
    printf("5. Move Forward\n");
    printf("6. Move Backward\n");
    printf("7. Check Drone Status\n");
    printf("8. Exit\n");
    printf("Choose an option (1-8): ");
}

void moveDrone(Drone *drone, float xChange, float yChange, float zChange) {
    if (drone->batteryLevel > 0) {
        drone->pos.x += xChange;
        drone->pos.y += yChange;
        drone->pos.z += zChange;
        drone->batteryLevel -= 5; // Decrease battery level with each move

        if (drone->batteryLevel < 0) {
            drone->batteryLevel = 0; // Prevent negative battery level
        }
    } else {
        printf("Battery depleted! Please recharge.\n");
    }
}

void checkStatus(Drone *drone) {
    printf("\nDrone Status:\n");
    printf("Position: (%.2f, %.2f, %.2f)\n", drone->pos.x, drone->pos.y, drone->pos.z);
    printf("Battery Level: %d%%\n", drone->batteryLevel);
}

void rechargeBattery(Drone *drone) {
    drone->batteryLevel = 100;
    printf("Drone battery fully recharged!\n");
}

int main() {
    Drone myDrone;
    initializeDrone(&myDrone);
    
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveDrone(&myDrone, 0, 0, 1);
                break;
            case 2:
                moveDrone(&myDrone, 0, 0, -1);
                break;
            case 3:
                moveDrone(&myDrone, -1, 0, 0);
                break;
            case 4:
                moveDrone(&myDrone, 1, 0, 0);
                break;
            case 5:
                moveDrone(&myDrone, 0, 1, 0);
                break;
            case 6:
                moveDrone(&myDrone, 0, -1, 0);
                break;
            case 7:
                checkStatus(&myDrone);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 8.\n");
                break;
        }
        sleep(1); // pause for a second before displaying menu again
    }

    return 0;
}