//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>

struct RemoteControlVehicle { // defining our struct
    int speed; // speed of the vehicle
    int direction; // direction of the vehicle
};

int main() {
    struct RemoteControlVehicle rc_vehicle1 = {0, 0}; // creating our first remote control vehicle and initializing its values to 0

    printf("Welcome to the Remote Control Vehicle Simulation Program!\n");

    while(1) { // a continuous loop
        printf("Choose an action to perform:\n");
        printf("1. Increase Speed\n");
        printf("2. Decrease Speed\n");
        printf("3. Change Direction\n");
        printf("4. Exit the Program\n");

        int action; // declaring our user's selected action variable
        scanf("%d", &action); // getting user's selected action

        switch(action) { // using a switch statement to perform the user's selected action
            case 1:
                rc_vehicle1.speed += 10;
                printf("Vehicle Speed Increased to: %d\n", rc_vehicle1.speed);
                break;
            case 2:
                rc_vehicle1.speed -= 10;
                printf("Vehicle Speed Decreased to: %d\n", rc_vehicle1.speed);
                break;
            case 3:
                printf("Choose a direction to set:\n");
                printf("1. Forward\n");
                printf("2. Reverse\n");
                int dir; // declaring our user's selected direction variable
                scanf("%d", &dir); // getting user's selected direction
                if (dir == 1) {
                    rc_vehicle1.direction = 1; // setting the direction to forward
                    printf("Vehicle Direction Set to: Forward\n");
                } else {
                    rc_vehicle1.direction = -1; // setting the direction to reverse
                    printf("Vehicle Direction Set to: Reverse\n");
                }
                break;
            case 4:
                printf("Thank you for using the Remote Control Vehicle Simulation Program!\n");
                return 0;
            default:
                printf("Invalid Action Selected. Please Try Again.\n");
        }

        // printing the current state of the vehicle
        printf("Current Vehicle State:\n");
        printf("     Speed: %d\n", rc_vehicle1.speed);
        if (rc_vehicle1.direction == 1) {
            printf("     Direction: Forward\n");
        } else if (rc_vehicle1.direction == -1) {
            printf("     Direction: Reverse\n");
        } else {
            printf("     Direction: None\n");
        }
    }

    return 0;
}