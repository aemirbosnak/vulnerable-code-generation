//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESTINATIONS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    double latitude;
    double longitude;
} Destination;

void inputDestinations(Destination destinations[], int *count) {
    while (*count < MAX_DESTINATIONS) {
        printf("Enter the destination name (or 'exit' to finish): ");
        scanf("%s", destinations[*count].name);
        if (strcmp(destinations[*count].name, "exit") == 0) {
            break;
        }
        printf("Enter latitude: ");
        scanf("%lf", &destinations[*count].latitude);
        printf("Enter longitude: ");
        scanf("%lf", &destinations[*count].longitude);
        (*count)++;
    }
}

void displayDestinations(Destination destinations[], int count) {
    printf("\nList of Destinations:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s | Latitude: %.6lf, Longitude: %.6lf\n", i + 1, destinations[i].name, destinations[i].latitude, destinations[i].longitude);
    }
}

void calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Haversine formula to calculate the distance between two points on the Earth
    const double R = 6371.0; 
    double dLat = (lat2 - lat1) * (3.14159265359 / 180.0);
    double dLon = (lon2 - lon1) * (3.14159265359 / 180.0);
    lat1 = lat1 * (3.14159265359 / 180.0);
    lat2 = lat2 * (3.14159265359 / 180.0);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c; 
    printf("Distance: %.2f km\n", distance);
}

void selectDestination(Destination destinations[], int count) {
    int index1, index2;
    printf("Select the first destination (1-%d): ", count);
    scanf("%d", &index1);
    printf("Select the second destination (1-%d): ", count);
    scanf("%d", &index2);

    if (index1 < 1 || index1 > count || index2 < 1 || index2 > count) {
        printf("Invalid selection. Please try again.\n");
        return;
    }

    printf("\nCalculating distance between %s and %s...\n",
           destinations[index1 - 1].name, destinations[index2 - 1].name);

    calculateDistance(destinations[index1 - 1].latitude,
                      destinations[index1 - 1].longitude,
                      destinations[index2 - 1].latitude,
                      destinations[index2 - 1].longitude);
}

int main() {
    Destination destinations[MAX_DESTINATIONS];
    int count = 0;
    int choice;

    printf("Welcome to the GPS Navigation Simulation!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Destination\n");
        printf("2. Display Destinations\n");
        printf("3. Calculate Distance Between Destinations\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputDestinations(destinations, &count);
                break;
            case 2:
                displayDestinations(destinations, count);
                break;
            case 3:
                selectDestination(destinations, count);
                break;
            case 4:
                printf("Exiting the GPS Navigation Simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}