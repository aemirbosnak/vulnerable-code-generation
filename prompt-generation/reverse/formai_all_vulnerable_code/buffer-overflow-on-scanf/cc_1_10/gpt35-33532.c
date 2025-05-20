//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>

// Function to control drone movement
void droneMove(char dir, int speed) {
    printf("Drone moving %c at speed %d\n", dir, speed);
}

// Function to change drone altitude
void droneAltitude(int altitude) {
    printf("Changing drone altitude to %d meters\n", altitude);
}

// Function to take off the drone
void droneTakeoff() {
    printf("Drone is taking off...\n");
    droneAltitude(10);
}

// Function to land the drone
void droneLand() {
    printf("Drone is landing...\n");
    droneAltitude(0);
}

int main() {
    char choice;
    int speed, altitude;

    // Display menu and get user input
    do {
        printf("\n---- Drone Remote Control Panel ----\n");
        printf("1. Move drone (F/B/L/R)\n");
        printf("2. Change altitude\n");
        printf("3. Take off\n");
        printf("4. Land\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Execute corresponding function based on user input
        switch (choice) {
            case '1':
                printf("Enter direction (F/B/L/R): ");
                scanf(" %c", &choice);
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                droneMove(choice, speed);
                break;
            case '2':
                printf("Enter altitude (0-20): ");
                scanf("%d", &altitude);
                droneAltitude(altitude);
                break;
            case '3':
                droneTakeoff();
                break;
            case '4':
                droneLand();
                break;
            case '0':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');

    return 0;
}