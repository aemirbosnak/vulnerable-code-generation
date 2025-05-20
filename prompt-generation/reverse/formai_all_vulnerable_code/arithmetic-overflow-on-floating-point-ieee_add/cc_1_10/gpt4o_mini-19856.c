//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT 100

typedef struct {
    float altitude;
    float speed;
    float latitude;
    float longitude;
} DroneStatus;

// Function prototypes
void displayMenu();
DroneStatus initializeDrone();
void takeOff(DroneStatus *drone);
void land(DroneStatus *drone);
void fly(DroneStatus *drone, float newAltitude, float newSpeed);
void getStatus(DroneStatus drone);
void changePosition(DroneStatus *drone, float deltaLat, float deltaLong);
void displayStatus(DroneStatus drone);

int main() {
    DroneStatus drone = initializeDrone();
    char input[MAX_INPUT];

    while (1) {
        displayMenu();
        printf("Enter a command: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "1") == 0) {
            takeOff(&drone);
        } else if (strcmp(input, "2") == 0) {
            land(&drone);
        } else if (strcmp(input, "3") == 0) {
            float newAltitude, newSpeed;
            printf("Enter new altitude: ");
            scanf("%f", &newAltitude);
            printf("Enter new speed: ");
            scanf("%f", &newSpeed);
            fly(&drone, newAltitude, newSpeed);
            getchar(); // Clear input buffer
        } else if (strcmp(input, "4") == 0) {
            getStatus(drone);
        } else if (strcmp(input, "5") == 0) {
            float deltaLat, deltaLong;
            printf("Enter change in latitude: ");
            scanf("%f", &deltaLat);
            printf("Enter change in longitude: ");
            scanf("%f", &deltaLong);
            changePosition(&drone, deltaLat, deltaLong);
            getchar(); // Clear input buffer
        } else if (strcmp(input, "q") == 0) {
            printf("Shutting down drone controller. Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Drone Remote Control Menu ===\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Fly to Altitude and Speed\n");
    printf("4. Get Status\n");
    printf("5. Change Position\n");
    printf("q. Quit\n");
}

DroneStatus initializeDrone() {
    DroneStatus drone;
    drone.altitude = 0.0;
    drone.speed = 0.0;
    drone.latitude = 0.0;
    drone.longitude = 0.0;
    printf("Drone initialized.\n");
    return drone;
}

void takeOff(DroneStatus *drone) {
    if (drone->altitude > 0) {
        printf("Drone is already in the air.\n");
    } else {
        drone->altitude = 100.0; // Default take off altitude
        drone->speed = 10.0; // Default cruising speed
        printf("Drone taking off to altitude: %.2f meters.\n", drone->altitude);
    }
}

void land(DroneStatus *drone) {
    if (drone->altitude <= 0) {
        printf("Drone is already on the ground.\n");
    } else {
        drone->altitude = 0.0;
        drone->speed = 0.0;
        printf("Drone landing. Now at altitude: %.2f meters.\n", drone->altitude);
    }
}

void fly(DroneStatus *drone, float newAltitude, float newSpeed) {
    if (newAltitude < 0) {
        printf("Invalid altitude. Cannot fly below ground level.\n");
        return;
    }
    drone->altitude = newAltitude;
    drone->speed = newSpeed;
    printf("Drone flying at altitude: %.2f meters with speed: %.2f m/s.\n", drone->altitude, drone->speed);
}

void getStatus(DroneStatus drone) {
    printf("\n--- Current Drone Status ---\n");
    printf("Altitude: %.2f meters\n", drone.altitude);
    printf("Speed: %.2f m/s\n", drone.speed);
    printf("Latitude: %.2f\n", drone.latitude);
    printf("Longitude: %.2f\n", drone.longitude);
}

void changePosition(DroneStatus *drone, float deltaLat, float deltaLong) {
    drone->latitude += deltaLat;
    drone->longitude += deltaLong;
    printf("Drone position changed to Latitude: %.2f, Longitude: %.2f\n", drone->latitude, drone->longitude);
}