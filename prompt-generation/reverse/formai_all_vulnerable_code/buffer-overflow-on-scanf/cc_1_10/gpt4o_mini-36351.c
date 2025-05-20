//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define EARTH_RADIUS 6371.0 // Earth's radius in kilometers
#define MAX_POINTS 100

typedef struct {
    double latitude;
    double longitude;
    char name[100];
} Location;

void clearScreen() {
    printf("\033[H\033[J");
}

double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

double calculateDistance(Location a, Location b) {
    double lat1 = toRadians(a.latitude);
    double lat2 = toRadians(b.latitude);
    double dLat = toRadians(b.latitude - a.latitude);
    double dLon = toRadians(b.longitude - a.longitude);
    
    double a_value = sin(dLat / 2) * sin(dLat / 2) +
                     cos(lat1) * cos(lat2) * 
                     sin(dLon / 2) * sin(dLon / 2);
    
    double c = 2 * atan2(sqrt(a_value), sqrt(1 - a_value));
    return EARTH_RADIUS * c;
}

void printMenu() {
    printf("====================================\n");
    printf("          GPS Navigation            \n");
    printf("====================================\n");
    printf("1. Add new location\n");
    printf("2. Calculate distance\n");
    printf("3. Show all locations\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addLocation(Location *locations, int *count) {
    if (*count >= MAX_POINTS) {
        printf("Location limit reached! Unable to add more locations.\n");
        return;
    }

    printf("Enter name for the location: ");
    scanf("%s", locations[*count].name);
    printf("Enter latitude: ");
    scanf("%lf", &locations[*count].latitude);
    printf("Enter longitude: ");
    scanf("%lf", &locations[*count].longitude);

    (*count)++;
    printf("Location added successfully!\n");
}

void calculateDistanceBetweenLocations(Location *locations, int count) {
    int index1, index2;

    printf("Choose the first location index (0 to %d): ", count - 1);
    scanf("%d", &index1);
    printf("Choose the second location index (0 to %d): ", count - 1);
    scanf("%d", &index2);

    if (index1 >= 0 && index1 < count && index2 >= 0 && index2 < count) {
        double distance = calculateDistance(locations[index1], locations[index2]);
        printf("Distance between '%s' and '%s': %.2f Km\n",
               locations[index1].name, locations[index2].name, distance);
    } else {
        printf("Invalid indices chosen. Please try again!\n");
    }
}

void showAllLocations(Location *locations, int count) {
    printf("Listing all stored locations:\n");
    for (int i = 0; i < count; ++i) {
        printf("Index %d: %s - Latitude: %.6f, Longitude: %.6f\n",
               i, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

int main() {
    Location locations[MAX_POINTS];
    int locationCount = 0;
    int choice;

    while (1) {
        clearScreen();
        printMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Error reading input!\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                addLocation(locations, &locationCount);
                break;
            case 2:
                calculateDistanceBetweenLocations(locations, locationCount);
                break;
            case 3:
                showAllLocations(locations, locationCount);
                break;
            case 4:
                printf("Exiting GPS Navigation. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(2); // Wait before clearing the screen
    }

    return 0;
}