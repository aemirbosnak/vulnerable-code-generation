//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float latitude, longitude, angle, distance;
    char direction;

    // Ask the user to enter their current location
    printf("Enter your current latitude: ");
    scanf("%f", &latitude);
    printf("Enter your current longitude: ");
    scanf("%f", &longitude);

    // Ask the user to enter the direction and distance they want to travel
    printf("Enter the direction you want to travel (N/E/S/W): ");
    scanf("%c", &direction);
    scanf("%c", &direction);
    printf("Enter the distance you want to travel (in km): ");
    scanf("%f", &distance);

    // Convert the direction to an angle in radians
    switch (direction) {
        case 'N':
            angle = 0;
            break;
        case 'E':
            angle = M_PI / 2;
            break;
        case 'S':
            angle = M_PI;
            break;
        case 'W':
            angle = 3 * M_PI / 2;
            break;
        default:
            printf("Invalid direction\n");
            exit(0);
    }

    // Calculate the new latitude and longitude
    latitude += (distance / 6371) * cos(angle);
    longitude += (distance / 6371) * sin(angle) / cos(latitude);

    // Print out the new location
    printf("Your new location is: %f, %f", latitude, longitude);

    return 0;
}