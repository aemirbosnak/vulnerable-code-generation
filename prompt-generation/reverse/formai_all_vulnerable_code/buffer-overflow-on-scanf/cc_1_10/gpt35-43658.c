//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

/* Define some constants */
#define DRONE_SPEED 50
#define MAX_HEIGHT 300
#define MIN_HEIGHT 0

/* Drone structure definition */
typedef struct drone_t {
    int altitude;
    int x_position;
    int y_position;
    int speed;
    int battery_life;
} Drone;

/* Function to display drone status */
void display_status(Drone drone) {
    printf("Drone Status: \n");
    printf("  Altitude: %d meters\n", drone.altitude);
    printf("  X-Position: %d meters\n", drone.x_position);
    printf("  Y-Position: %d meters\n", drone.y_position);
    printf("  Speed: %d km/h\n", drone.speed);
    printf("  Battery Life: %d %%\n", drone.battery_life);
}

/* Main function */
int main() {
    /* Initialize drone */
    Drone drone = {0, 0, 0, DRONE_SPEED, 100};

    /* Display initial drone status */
    display_status(drone);

    /* Loop for controlling drone */
    int user_input;
    while (1) {
        printf("\n--------------------------\n");
        printf("Enter 1 to move North\n");
        printf("Enter 2 to move East\n");
        printf("Enter 3 to move South\n");
        printf("Enter 4 to move West\n");
        printf("Enter 5 to ascend\n");
        printf("Enter 6 to descend\n");
        printf("Enter 7 to display status\n");
        printf("Enter 8 to exit\n");

        /* Get user input */
        scanf("%d", &user_input);

        /* Process user input */
        switch (user_input) {
            case 1:
                if (drone.y_position < MAX_HEIGHT) {
                    drone.y_position += 10;
                    drone.battery_life -= 1;
                } else {
                    printf("Drone cannot move further North\n");
                }
                break;
            case 2:
                if (drone.x_position < MAX_HEIGHT) {
                    drone.x_position += 10;
                    drone.battery_life -= 1;
                } else {
                    printf("Drone cannot move further East\n");
                }
                break;
            case 3:
                if (drone.y_position > MIN_HEIGHT) {
                    drone.y_position -= 10;
                    drone.battery_life -= 1;
                } else {
                    printf("Drone cannot move further South\n");
                }
                break;
            case 4:
                if (drone.x_position > MIN_HEIGHT) {
                    drone.x_position -= 10;
                    drone.battery_life -= 1;
                } else {
                    printf("Drone cannot move further West\n");
                }
                break;
            case 5:
                if (drone.altitude < MAX_HEIGHT) {
                    drone.altitude += 10;
                    drone.speed = DRONE_SPEED * 2;
                    drone.battery_life -= 2;
                } else {
                    printf("Drone cannot ascend further\n");
                }
                break;
            case 6:
                if (drone.altitude > MIN_HEIGHT) {
                    drone.altitude -= 10;
                    drone.speed = DRONE_SPEED;
                    drone.battery_life -= 1;
                } else {
                    printf("Drone cannot descend further\n");
                }
                break;
            case 7:
                display_status(drone);
                break;
            case 8:
                printf("Exiting Drone Remote Control Program...\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }

        /* Check battery life */
        if (drone.battery_life <= 0) {
            printf("Drone is out of battery life. Exiting program...\n");
            exit(0);
        }
    }

    return 0;
}