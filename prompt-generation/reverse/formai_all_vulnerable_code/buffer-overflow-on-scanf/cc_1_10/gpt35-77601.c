//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: expert-level
#include <stdio.h>

struct remoteControl {
    int power; // variable to hold power status
    int pitch; // variable to hold pitch level
    int roll; // variable to hold roll level
    int yaw; // variable to hold yaw level
} drone; // create instance of remoteControl struct, named drone

int main() {
    // init the remote control, drone is off and at zero levels
    drone.power = 0;
    drone.pitch = 0;
    drone.roll = 0;
    drone.yaw = 0;

    // ask user if they want turn on or off the drone
    printf("Do you want to turn on the drone? (1=Yes, 0=No):\n");
    scanf("%d", &drone.power); // get user input and store in drone.power

    // check if the drone is power on or off
    if(drone.power == 1) {
        printf("Drone is powering on...\n");

        // prompt user for pitch level
        printf("Select pitch level (Range -100 to 100):\n");
        scanf("%d", &drone.pitch); // get user input and store in drone.pitch

        // prompt user for roll level
        printf("Select roll level (Range -100 to 100):\n");
        scanf("%d", &drone.roll); // get user input and store in drone.roll

        // prompt user for yaw level
        printf("Select yaw level (Range -100 to 100):\n");
        scanf("%d", &drone.yaw); // get user input and store in drone.yaw

        // send control signals to the drone
        printf("Sending control signals to the drone...\n");

        // print final control signal values
        printf("Control Signals:\n");
        printf("Pitch: %d\n", drone.pitch);
        printf("Roll: %d\n", drone.roll);
        printf("Yaw: %d\n", drone.yaw);
    } else {
        printf("Drone is powered off...\n");
    }

    return 0;
}