//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define PI 3.14159265

typedef struct {
    double x; // x coordinate of the remote vehicle
    double y; // y coordinate of the remote vehicle
    double angle; // current angle of the remote vehicle
    double speed; // current speed of the remote vehicle
} RemoteVehicle;

void updateRemoteVehicle(RemoteVehicle* rv) {
    // update the position of the remote vehicle based on its angle and speed
    rv->x += rv->speed * cos(rv->angle * PI / 180.0);
    rv->y += rv->speed * sin(rv->angle * PI / 180.0);
}

int main(void) {
    RemoteVehicle rv = {0.0, 0.0, 0.0, 0.0};

    printf("Welcome to the Remote Control Vehicle Simulation!\n\n");

    // prompt the user for inputs
    printf("Please enter the initial X coordinate of the remote vehicle: ");
    scanf("%lf", &rv.x);

    printf("Please enter the initial Y coordinate of the remote vehicle: ");
    scanf("%lf", &rv.y);

    printf("Please enter the initial angle of the remote vehicle (in degrees): ");
    scanf("%lf", &rv.angle);

    printf("Please enter the initial speed of the remote vehicle: ");
    scanf("%lf", &rv.speed);

    printf("\nThe remote vehicle has been initialized at (%.2lf, %.2lf) with angle %.2lf and speed %.2lf.\n\n",
           rv.x, rv.y, rv.angle, rv.speed);

    // main simulation loop
    while (1) {
        // update the position of the remote vehicle based on its angle and speed
        updateRemoteVehicle(&rv);

        // prompt the user for inputs
        char command;
        printf("Current position: (%.2lf, %.2lf), angle: %.2lf, speed: %.2lf\n",
               rv.x, rv.y, rv.angle, rv.speed);
        printf("Enter a command (F=forward, B=backward, L=turn left, R=turn right, Q=quit): ");
        scanf(" %c", &command);

        // process the command
        switch (command) {
            case 'F':
                rv.speed += 0.1;
                break;
            case 'B':
                rv.speed -= 0.1;
                break;
            case 'L':
                rv.angle -= 5.0;
                break;
            case 'R':
                rv.angle += 5.0;
                break;
            case 'Q':
                printf("Exiting remote vehicle simulation...\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
    }

    return 0;
}