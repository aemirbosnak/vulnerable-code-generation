//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LOCATIONS 100
#define NAME_LENGTH 50

// Location structure
typedef struct {
    char name[NAME_LENGTH];
    double latitude;
    double longitude;
} Location;

// Function declarations
void addLocation(Location *locations, int *locationCount);
void listLocations(Location *locations, int locationCount);
void calculateDistance(Location loc1, Location loc2);
double toRadians(double degree);
double haversineDistance(double lat1, double lon1, double lat2, double lon2);

int main() {
    Location locations[MAX_LOCATIONS];
    int locationCount = 0;
    int choice;
  
    do {
        printf("\nGPS Navigation Simulation Menu:\n");
        printf("1. Add Location\n");
        printf("2. List Locations\n");
        printf("3. Calculate Distance Between Locations\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer

        switch (choice) {
            case 1:
                addLocation(locations, &locationCount);
                break;
            case 2:
                listLocations(locations, locationCount);
                break;
            case 3: {
                char name1[NAME_LENGTH];
                char name2[NAME_LENGTH];
                printf("Enter first location name: ");
                fgets(name1, NAME_LENGTH, stdin);
                name1[strcspn(name1, "\n")] = 0;  // Remove newline

                printf("Enter second location name: ");
                fgets(name2, NAME_LENGTH, stdin);
                name2[strcspn(name2, "\n")] = 0;  // Remove newline

                Location loc1, loc2;
                int found1 = 0, found2 = 0;
                for (int i = 0; i < locationCount; i++) {
                    if (strcmp(locations[i].name, name1) == 0) {
                        loc1 = locations[i];
                        found1 = 1;
                    }
                    if (strcmp(locations[i].name, name2) == 0) {
                        loc2 = locations[i];
                        found2 = 1;
                    }
                }
                if (found1 && found2) {
                    calculateDistance(loc1, loc2);
                } else {
                    printf("One or both locations not found!\n");
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addLocation(Location *locations, int *locationCount) {
    if (*locationCount >= MAX_LOCATIONS) {
        printf("Location limit reached. Cannot add more locations.\n");
        return;
    }

    printf("Enter location name: ");
    fgets(locations[*locationCount].name, NAME_LENGTH, stdin);
    locations[*locationCount].name[strcspn(locations[*locationCount].name, "\n")] = 0;  // Remove newline

    printf("Enter latitude: ");
    scanf("%lf", &locations[*locationCount].latitude);
    printf("Enter longitude: ");
    scanf("%lf", &locations[*locationCount].longitude);
    getchar();  // Clear newline character from buffer

    (*locationCount)++;
    printf("Location added successfully!\n");
}

void listLocations(Location *locations, int locationCount) {
    if (locationCount == 0) {
        printf("No locations available.\n");
        return;
    }

    printf("\nList of Locations:\n");
    for (int i = 0; i < locationCount; i++) {
        printf("%d: %s (Lat: %.6lf, Long: %.6lf)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

void calculateDistance(Location loc1, Location loc2) {
    double distance = haversineDistance(loc1.latitude, loc1.longitude, loc2.latitude, loc2.longitude);
    printf("Distance between %s and %s: %.2f km\n", loc1.name, loc2.name, distance);
}

double toRadians(double degree) {
    return degree * (M_PI / 180);
}

double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double earthRadiusKm = 6371.0;

    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(toRadians(lat1)) * cos(toRadians(lat2)) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadiusKm * c;  // returns the distance in kilometers
}