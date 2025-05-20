//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 100

// Structure to represent a location
typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

// Function prototype
void displayMenu();
void addLocation(Location *locations, int *count);
void displayLocations(const Location *locations, int count);
void findRoute(const Location *locations, int count);
double calculateDistance(double lat1, double lon1, double lat2, double lon2);

int main() {
    Location locations[MAX_LOCATIONS];
    int locationCount = 0;
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addLocation(locations, &locationCount);
                break;
            case 2:
                displayLocations(locations, locationCount);
                break;
            case 3:
                findRoute(locations, locationCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n----- GPS Navigation Simulation -----\n");
    printf("1. Add Location\n");
    printf("2. Display Locations\n");
    printf("3. Find Route\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
}

void addLocation(Location *locations, int *count) {
    if (*count >= MAX_LOCATIONS) {
        printf("Location limit reached! Cannot add more locations.\n");
        return;
    }

    printf("Enter location name: ");
    scanf("%s", locations[*count].name);
    printf("Enter latitude: ");
    scanf("%lf", &locations[*count].latitude);
    printf("Enter longitude: ");
    scanf("%lf", &locations[*count].longitude);
    
    (*count)++;
    printf("Location added successfully!\n");
}

void displayLocations(const Location *locations, int count) {
    if (count == 0) {
        printf("No locations available.\n");
        return;
    }
    
    printf("\nList of Locations:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Lat: %.6lf, Lon: %.6lf)\n", i + 1, locations[i].name,
               locations[i].latitude, locations[i].longitude);
    }
}

void findRoute(const Location *locations, int count) {
    if (count < 2) {
        printf("At least two locations are required to find a route.\n");
        return;
    }

    int startIndex, endIndex;
    printf("Select starting location index (1 to %d): ", count);
    scanf("%d", &startIndex);
    printf("Select destination location index (1 to %d): ", count);
    scanf("%d", &endIndex);
    
    if (startIndex < 1 || startIndex > count || endIndex < 1 || endIndex > count || startIndex == endIndex) {
        printf("Invalid location indexes. Please try again.\n");
        return;
    }

    startIndex--;
    endIndex--;
    
    double distance = calculateDistance(locations[startIndex].latitude, locations[startIndex].longitude,
                                         locations[endIndex].latitude, locations[endIndex].longitude);
    printf("Route from %s to %s: Distance = %.2f km\n", locations[startIndex].name, locations[endIndex].name, distance);
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Radius of Earth in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) * 
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}