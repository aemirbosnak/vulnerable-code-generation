//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include <stdio.h>

int main() {
    float latitude, longitude;
    printf("Welcome to GPS Navigation Simulation Program\n\n");
    printf("Enter your current location:\n");
    printf("Latitude (in decimal degrees): ");
    scanf("%f", &latitude);
    printf("Longitude (in decimal degrees): ");
    scanf("%f", &longitude);

    printf("\n\nChoose a destination:\n");
    printf("1. Empire State Building (40.748817, -73.985428)\n");
    printf("2. Golden Gate Bridge (37.8199286, -122.4782551)\n");
    printf("3. Tower of London (51.508112, -0.075949)\n");
    printf("Enter your choice (1-3): ");

    int choice;
    scanf("%d", &choice);

    float dest_latitude, dest_longitude;
    switch(choice) {
        case 1:
            dest_latitude = 40.748817;
            dest_longitude = -73.985428;
            printf("\nEmpire State Building selected as destination.\n");
            break;
        case 2:
            dest_latitude = 37.8199286;
            dest_longitude = -122.4782551;
            printf("\nGolden Gate Bridge selected as destination.\n");
            break;
        case 3:
            dest_latitude = 51.508112;
            dest_longitude = -0.075949;
            printf("\nTower of London selected as destination.\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            return 0;
    }

    printf("\nCalculating route from (%.6f, %.6f) to (%.6f, %.6f)...\n", latitude, longitude, dest_latitude, dest_longitude);

    // fake route calculation
    printf("\nRoute found!\n");
    printf("Distance:  3535.2 km\n");
    printf("Time:  34 hours and 25 minutes\n");

    printf("\nStarting navigation:\n");
    printf("Make a left turn in 100 meters.\n");
    printf("Continue straight for 2 kilometers.\n");
    printf("Make a right turn in 500 meters.\n");
    printf("Continue straight for 5 kilometers.\n");
    printf("Make a left turn in 300 meters.\n");
    printf("Continue straight for 3 kilometers.\n");

    printf("\nArrived at destination (%.6f, %.6f)!\n\n", dest_latitude, dest_longitude);

    return 0;
}