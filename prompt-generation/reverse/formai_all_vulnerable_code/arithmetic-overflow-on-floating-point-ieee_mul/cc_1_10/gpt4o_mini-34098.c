//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265
#define EARTH_RADIUS 6371  // Earth's radius in kilometers

typedef struct {
    double latitude;
    double longitude;
} Coordinates;

void displayMenu() {
    printf("\n=== GPS Navigation System ===\n");
    printf("1. Input Current Location\n");
    printf("2. Input Destination\n");
    printf("3. Calculate Distance\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option (1-4): ");
}

double toRadians(double degree) {
    return degree * (PI / 180);
}

double calculateDistance(Coordinates start, Coordinates end) {
    double lat1 = toRadians(start.latitude);
    double lon1 = toRadians(start.longitude);
    double lat2 = toRadians(end.latitude);
    double lon2 = toRadians(end.longitude);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) + 
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;  // Distance in kilometers
}

void getCurrentLocation(Coordinates *current) {
    printf("Enter your current latitude: ");
    scanf("%lf", &current->latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &current->longitude);
}

void getDestination(Coordinates *destination) {
    printf("Enter destination latitude: ");
    scanf("%lf", &destination->latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination->longitude);
}

int main() {
    Coordinates currentLocation, destinationLocation;
    int choice;
    int exitFlag = 0;

    while (!exitFlag) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                getCurrentLocation(&currentLocation);
                printf("Current location set to: %.6f, %.6f\n", 
                        currentLocation.latitude, currentLocation.longitude);
                break;
            case 2:
                getDestination(&destinationLocation);
                printf("Destination set to: %.6f, %.6f\n", 
                        destinationLocation.latitude, destinationLocation.longitude);
                break;
            case 3:
                if (currentLocation.latitude != 0 && currentLocation.longitude != 0 && 
                    destinationLocation.latitude != 0 && destinationLocation.longitude != 0) {
                    double distance = calculateDistance(currentLocation, destinationLocation);
                    printf("Distance to destination: %.2f kilometers\n", distance);
                } else {
                    printf("Please set both current location and destination first.\n");
                }
                break;
            case 4:
                exitFlag = 1;
                printf("Exiting... Thank you for using the GPS Navigation System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}