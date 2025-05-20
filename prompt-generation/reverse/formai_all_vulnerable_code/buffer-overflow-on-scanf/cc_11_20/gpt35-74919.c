//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: artistic
#include <stdio.h>

int main() {
    // Initializing variables
    int battery_level = 100;
    int distance_from_home = 0;
    int altitude = 0;
    int speed = 0;
    int direction_x = 0;
    int direction_y = 0;

    // Displaying welcome message
    printf("Welcome to C Drone Remote Control System!\n");

    // Loop to accept user inputs and operate the drone
    while (1) {
        // Displaying menu options
        printf("\nMenu:\n");
        printf("1. Check battery level\n");
        printf("2. Check distance from home\n");
        printf("3. Check altitude\n");
        printf("4. Check speed\n");
        printf("5. Change direction\n");
        printf("6. Land drone\n");
        printf("Enter your choice: ");

        // Accepting user input
        int choice;
        scanf("%d", &choice);

        // Performing action based on user choice
        switch(choice) {
            case 1:
                printf("Battery level: %d%%\n", battery_level);
                break;
            case 2:
                printf("Distance from home: %d meters\n", distance_from_home);
                break;
            case 3:
                printf("Altitude: %d meters\n", altitude);
                break;
            case 4:
                printf("Speed: %d km/h\n", speed);
                break;
            case 5:
                // Accepting user input for direction
                printf("Enter direction in x-axis: ");
                scanf("%d", &direction_x);
                printf("Enter direction in y-axis: ");
                scanf("%d", &direction_y);

                // Checking if direction is valid
                if (direction_x < -1 || direction_x > 1 || direction_y < -1 || direction_y > 1) {
                    printf("Invalid direction\n");
                    break;
                }

                // Moving the drone in the given direction
                distance_from_home += speed;
                altitude += 10;
                speed += 10;
                printf("Drone moved %d meters away from home in (x, y) direction (%d, %d)\n", speed, direction_x, direction_y);
                break;
            case 6:
                printf("Landing drone...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}