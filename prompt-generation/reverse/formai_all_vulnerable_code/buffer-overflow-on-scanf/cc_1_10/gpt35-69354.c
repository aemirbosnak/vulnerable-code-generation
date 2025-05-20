//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include <stdio.h>

int main() {
    // Variables
    int throttle = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int arm = 0;
    int disarm = 0;
    int emergency = 0;
    int flight_mode = 0;

    // Start of program
    printf("Welcome to the C Drone Remote Control!\n");

    // Getting initial input from user
    printf("\nPlease enter the throttle value (0-100): ");
    scanf("%d", &throttle);
    printf("Please enter the pitch value (-50 to 50): ");
    scanf("%d", &pitch);
    printf("Please enter the roll value (-50 to 50): ");
    scanf("%d", &roll);
    printf("Please enter the yaw value (-50 to 50): ");
    scanf("%d", &yaw);

    // Checking for arm, disarm and emergency button presses
    printf("\nPress A to arm, D to disarm and E for emergency:\n");
    char button;
    scanf(" %c", &button);
    if (button == 'A') {
        arm = 1;
    } else if (button == 'D') {
        disarm = 1;
    } else if (button == 'E') {
        emergency = 1;
    }

    // Checking for flight mode selection
    printf("\nPlease select the flight mode:\n 1. Stabilize  2. Altitude Hold  3. Loiter\n");
    scanf("%d", &flight_mode);

    // Displaying the input received from user
    printf("\nThrottle: %d\nPitch: %d\nRoll: %d\nYaw: %d\n", throttle, pitch, roll, yaw);
    if (arm) {
        printf("Arm button was pressed.\n");
    } else if (disarm) {
        printf("Disarm button was pressed.\n");
    } else if (emergency) {
        printf("Emergency button was pressed.\n");
    }
    printf("Flight mode selected: %d\n", flight_mode);

    // End of program
    printf("\nThank you for using C Drone Remote Control!\n");
    return 0;
}