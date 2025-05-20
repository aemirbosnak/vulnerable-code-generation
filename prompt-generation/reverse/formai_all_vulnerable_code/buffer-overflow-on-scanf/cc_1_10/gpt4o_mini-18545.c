//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DESTINATIONS 10
#define EARTH_RADIUS 6371 // Radius of the Earth in kilometers

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Function to calculate distance between two GPS coordinates
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

void displayMenu() {
    printf("\n========== GPS Navigation Simulation ==========\n");
    printf("1. Add Destination\n");
    printf("2. View Destinations\n");
    printf("3. Calculate Distance\n");
    printf("4. Exit\n");
    printf("==============================================\n");
    printf("Choose an option (1-4): ");
}

int main() {
    Location destinations[MAX_DESTINATIONS];
    int destinationCount = 0;
    int choice;

    printf("Welcome to the GPS Navigation Simulation!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (destinationCount >= MAX_DESTINATIONS) {
                    printf("Destination limit reached! Please remove one to add another.\n");
                } else {
                    printf("Enter destination name: ");
                    scanf("%s", destinations[destinationCount].name);
                    printf("Enter latitude (in decimal degrees): ");
                    scanf("%lf", &destinations[destinationCount].latitude);
                    printf("Enter longitude (in decimal degrees): ");
                    scanf("%lf", &destinations[destinationCount].longitude);
                    destinationCount++;
                    printf("Destination '%s' added successfully!\n", destinations[destinationCount - 1].name);
                }
                break;
            }
            case 2: {
                printf("\nDestinations List:\n");
                for (int i = 0; i < destinationCount; i++) {
                    printf("%d. %s (%.6f, %.6f)\n", i + 1, destinations[i].name, destinations[i].latitude, destinations[i].longitude);
                }
                break;
            }
            case 3: {
                int dest1, dest2;
                printf("Select two destinations to calculate distance:\n");
                for (int i = 0; i < destinationCount; i++) {
                    printf("%d. %s\n", i + 1, destinations[i].name);
                }
                printf("Select first destination (1-%d): ", destinationCount);
                scanf("%d", &dest1);
                printf("Select second destination (1-%d): ", destinationCount);
                scanf("%d", &dest2);

                if (dest1 < 1 || dest1 > destinationCount || dest2 < 1 || dest2 > destinationCount) {
                    printf("Invalid selection! Please choose valid destinations.\n");
                } else {
                    double distance = calculateDistance(destinations[dest1 - 1].latitude, destinations[dest1 - 1].longitude,
                                                        destinations[dest2 - 1].latitude, destinations[dest2 - 1].longitude);
                    printf("Distance between '%s' and '%s' is: %.2f km\n", 
                           destinations[dest1 - 1].name, 
                           destinations[dest2 - 1].name, 
                           distance);
                }
                break;
            }
            case 4: {
                printf("Thank you for using the GPS Navigation Simulation!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Please select between 1 and 4.\n");
                break;
            }
        }
    }
    return 0;
}