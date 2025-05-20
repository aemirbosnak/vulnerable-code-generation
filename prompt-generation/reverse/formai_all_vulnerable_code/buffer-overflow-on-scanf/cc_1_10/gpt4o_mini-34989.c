//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LOCATIONS 50
#define MAX_NAME_LENGTH 100
#define PI 3.14159265358979323846

// Structure to define a location with coordinates and a name
typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

// Function prototypes
void displayMenu();
void addLocation(Location locations[], int *locationCount);
void displayLocations(const Location locations[], int locationCount);
void navigate(const Location locations[], int locationCount);
double calculateDistance(double lat1, double lon1, double lat2, double lon2);

int main() {
    Location locations[MAX_LOCATIONS];
    int locationCount = 0;
    int choice;

    printf("Welcome to the Artistic GPS Navigation Simulation!\n");

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addLocation(locations, &locationCount);
                break;
            case 2:
                displayLocations(locations, locationCount);
                break;
            case 3:
                navigate(locations, locationCount);
                break;
            case 4:
                printf("Exiting the program. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Add a Location\n");
    printf("2. Display Locations\n");
    printf("3. Navigate\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addLocation(Location locations[], int *locationCount) {
    if (*locationCount >= MAX_LOCATIONS) {
        printf("Maximum number of locations reached.\n");
        return;
    }

    printf("Enter location name: ");
    scanf("%s", locations[*locationCount].name);
    printf("Enter latitude: ");
    scanf("%lf", &locations[*locationCount].latitude);
    printf("Enter longitude: ");
    scanf("%lf", &locations[*locationCount].longitude);
    
    (*locationCount)++;
    printf("Location '%s' added successfully!\n", locations[*locationCount - 1].name);
}

void displayLocations(const Location locations[], int locationCount) {
    printf("\n--- Locations ---\n");
    for (int i = 0; i < locationCount; i++) {
        printf("%d. %s (Lat: %.6f, Lon: %.6f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

void navigate(const Location locations[], int locationCount) {
    int startIndex, endIndex;
    
    printf("Choose a starting location (1 to %d): ", locationCount);
    scanf("%d", &startIndex);
    
    printf("Choose a destination location (1 to %d): ", locationCount);
    scanf("%d", &endIndex);
    
    if (startIndex < 1 || startIndex > locationCount || endIndex < 1 || endIndex > locationCount) {
        printf("Invalid location selection.\n");
        return;
    }

    double distance = calculateDistance(locations[startIndex - 1].latitude, locations[startIndex - 1].longitude,
                                        locations[endIndex - 1].latitude, locations[endIndex - 1].longitude);
    printf("Navigating from %s to %s...\n", locations[startIndex - 1].name, locations[endIndex - 1].name);
    printf("Distance: %.2f km\n", distance);
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Convert degrees to radians
    lat1 = lat1 * PI / 180.0;
    lon1 = lon1 * PI / 180.0;
    lat2 = lat2 * PI / 180.0;
    lon2 = lon2 * PI / 180.0;

    // Haversine formula
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double radius = 6371; // Radius of Earth in kilometers
    return radius * c;
}