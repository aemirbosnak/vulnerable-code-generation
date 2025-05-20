//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>

int main() {
    // declare car variables
    int speed = 0;
    int direction = 0;
    int batteryLife = 100;
    int distanceTraveled = 0;

    // display welcome message
    printf("Welcome to the Remote Control Vehicle Simulation Program!\n");

    // prompt user for input
    printf("Please enter the speed of the car (1-10): ");
    scanf("%d", &speed);
    printf("Please enter the direction of the car (0-360): ");
    scanf("%d", &direction);

    // display car status
    printf("\n--------------\n");
    printf("CAR STATUS\n");
    printf("--------------\n");
    printf("Speed: %d\n", speed);
    printf("Direction: %d\n", direction);
    printf("Battery Life: %d%%\n", batteryLife);
    printf("Distance Traveled: %d meters\n", distanceTraveled);

    // simulate car movement
    for (int i = 0; i < 10; i++) {
        distanceTraveled += speed;
        batteryLife -= 10;

        // randomize change in direction
        int randomDirectionChange = rand() % 20 - 10;
        direction += randomDirectionChange;

        // keep direction within 0-360 range
        if (direction < 0) {
            direction += 360;
        } else if (direction > 360) {
            direction -= 360;
        }

        // display updated status
        printf("\n--------------\n");
        printf("CAR STATUS\n");
        printf("--------------\n");
        printf("Speed: %d\n", speed);
        printf("Direction: %d\n", direction);
        printf("Battery Life: %d%%\n", batteryLife);
        printf("Distance Traveled: %d meters\n", distanceTraveled);

        // check if battery life is drained
        if (batteryLife <= 0) {
            printf("\nBattery life drained. Remote control vehicle has stopped.\n");
            break;
        }

        // simulate pause in movement
        sleep(1);
    }

    return 0;
}