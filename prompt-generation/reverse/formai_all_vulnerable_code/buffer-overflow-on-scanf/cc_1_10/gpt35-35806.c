//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* Define the struct for Drone */
typedef struct Drone {
    int battery;
    int altitude;
    int heading;
    int pitch;
    int roll;
    int yaw;
} Drone;

/* Define the function to initialize the drone */
void initDrone(Drone *drone) {
    drone->battery = 100;
    drone->altitude = 0;
    drone->heading = 0;
    drone->pitch = 0;
    drone->roll = 0;
    drone->yaw = 0;
}

/* Define the function to control the drone */
void controlDrone(Drone *drone, int movement, int speed) {
    switch (movement) {
        case 1: // Move forward
            drone->pitch += speed;
            break;
        case 2: // Move backward
            drone->pitch -= speed;
            break;
        case 3: // Move left
            drone->roll -= speed;
            break;
        case 4: // Move right
            drone->roll += speed;
            break;
        case 5: // Move up
            drone->altitude += speed;
            break;
        case 6: // Move down
            drone->altitude -= speed;
            break;
        case 7: // Turn left
            drone->yaw -= speed;
            break;
        case 8: // Turn right
            drone->yaw += speed;
            break;
        default:
            printf("Invalid movement\n");
            break;
    }
}

/* Define the function to check the status of the drone */
void checkStatus(Drone *drone) {
    printf("Battery: %d\n", drone->battery);
    printf("Altitude: %d\n", drone->altitude);
    printf("Heading: %d\n", drone->heading);
    printf("Pitch: %d\n", drone->pitch);
    printf("Roll: %d\n", drone->roll);
    printf("Yaw: %d\n", drone->yaw);
}

/* main function */
int main() {
    Drone drone;
    initDrone(&drone);
    int movement, speed;

    printf("Welcome to Drone Remote Control System!\n");

    while (1) {
        printf("Choose movement:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Move left\n");
        printf("4. Move right\n");
        printf("5. Move up\n");
        printf("6. Move down\n");
        printf("7. Turn left\n");
        printf("8. Turn right\n");
        printf("9. Check status\n");
        printf("0. Exit\n");
        scanf("%d", &movement);

        if (movement == 9) {
            checkStatus(&drone);
            continue;
        } else if (movement == 0) {
            break;
        }

        printf("Enter speed (1-10):\n");
        scanf("%d", &speed);

        controlDrone(&drone, movement, speed);
        drone.battery -= 10;
        if (drone.battery <= 0) {
            printf("Drone out of battery! Landing...\n");
            drone.battery = 0;
            drone.altitude = 0;
            drone.heading = 0;
            drone.pitch = 0;
            drone.roll = 0;
            drone.yaw = 0;
        }
    }

    printf("Goodbye!\n");
    return 0;
}