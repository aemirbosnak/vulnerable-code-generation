//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>

/* Define constants for the maximum limits of various properties */
#define MAX_SPEED 200
#define MAX_TURNING_ANGLE 45
#define MAX_FUEL 100
#define FUEL_CONSUMPTION_RATE 10

int main() {
    /* Declare and initialize variables for the properties of the remote control vehicle */
    int speed = 0;
    int turningAngle = 0;
    int fuelLevel = MAX_FUEL;

    /* Loop until the user decides to exit */
    while (1) {
        printf("Remote Control Vehicle Simulation\n");
        printf("------------------------------\n");
        printf("Speed: %d\n", speed);
        printf("Turning Angle: %d\n", turningAngle);
        printf("Fuel Level: %d\n", fuelLevel);
        printf("------------------------------\n");
        printf("Enter command (s=Speed, t=Turning Angle, e=Exit): ");

        /* Get user input for the desired action */
        char input;
        scanf(" %c", &input);

        /* Process user input */
        switch (input) {
            case 's':
                printf("Enter speed (0-%d): ", MAX_SPEED);
                scanf("%d", &speed);
                speed = (speed < 0) ? 0 : speed;
                speed = (speed > MAX_SPEED) ? MAX_SPEED : speed;
                break;
            case 't':
                printf("Enter turning angle (-%d to %d): ", MAX_TURNING_ANGLE, MAX_TURNING_ANGLE);
                scanf("%d", &turningAngle);
                turningAngle = (turningAngle < -MAX_TURNING_ANGLE) ? -MAX_TURNING_ANGLE : turningAngle;
                turningAngle = (turningAngle > MAX_TURNING_ANGLE) ? MAX_TURNING_ANGLE : turningAngle;
                break;
            case 'e':
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }

        /* Simulate movement based on current speed and turning angle */
        int distance = speed / 10;
        int fuelConsumed = distance * FUEL_CONSUMPTION_RATE;
        fuelLevel = (fuelLevel < fuelConsumed) ? 0 : fuelLevel - fuelConsumed;

        /* Print the distance travelled and remaining fuel level */
        printf("Travelling %d metres...\n", distance);
        printf("Fuel consumed: %d litres\n", fuelConsumed);
        printf("Fuel level: %d\n", fuelLevel);
    }

    return 0;
}