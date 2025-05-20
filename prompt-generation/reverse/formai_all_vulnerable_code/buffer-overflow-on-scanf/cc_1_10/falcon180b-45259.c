//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct drone {
    char name[20];
    int battery_level;
    int altitude;
    int speed;
    int direction;
} Drone;

void init_drone(Drone* drone) {
    strcpy(drone->name, "My Drone");
    drone->battery_level = 100;
    drone->altitude = 0;
    drone->speed = 0;
    drone->direction = 0;
}

void display_drone_info(Drone* drone) {
    printf("Drone Name: %s\n", drone->name);
    printf("Battery Level: %d%%\n", drone->battery_level);
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Speed: %d m/s\n", drone->speed);
    printf("Direction: %d degrees\n", drone->direction);
}

int main() {
    Drone drone;
    init_drone(&drone);

    while (1) {
        display_drone_info(&drone);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Move Forward\n");
        printf("2. Turn Left\n");
        printf("3. Turn Right\n");
        printf("4. Increase Altitude\n");
        printf("5. Decrease Altitude\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                drone.speed += 5;
                break;
            case 2:
                drone.direction -= 5;
                break;
            case 3:
                drone.direction += 5;
                break;
            case 4:
                drone.altitude += 5;
                break;
            case 5:
                drone.altitude -= 5;
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}