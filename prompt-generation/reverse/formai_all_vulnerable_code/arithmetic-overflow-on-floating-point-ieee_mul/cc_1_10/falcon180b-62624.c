//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate distance in kilometers between two GPS coordinates
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371 * c; // Earth's radius in kilometers
}

int main() {
    double lat1, lon1, lat2, lon2;
    double distance;
    int choice;
    char input[100];

    // Prompt user to enter starting GPS coordinates
    printf("Enter starting GPS coordinates (latitude,longitude): ");
    scanf("%s", input);
    sscanf(input, "%lf,%lf", &lat1, &lon1);

    // Loop until user chooses to exit
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Enter destination GPS coordinates\n");
        printf("2. Calculate distance between current and destination\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Prompt user to enter destination GPS coordinates
                printf("Enter destination GPS coordinates (latitude,longitude): ");
                scanf("%s", input);
                sscanf(input, "%lf,%lf", &lat2, &lon2);
                break;
            case 2:
                // Calculate distance between current and destination coordinates
                distance = calculateDistance(lat1, lon1, lat2, lon2);
                printf("The distance between the current location and the destination is %.2lf kilometers.\n", distance);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}