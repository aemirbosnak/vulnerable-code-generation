//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 50

// Define a structure to represent a location
typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Location;

// Function to display the available locations
void display_locations(Location locations[], int count) {
    printf("Available locations:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s [Lat: %.2f, Long: %.2f]\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

// Function to calculate the distance (dummy function for simulation)
float calculate_distance(Location loc1, Location loc2) {
    // A simple distance calculation formula for simulation
    return ((loc1.latitude - loc2.latitude) * (loc1.latitude - loc2.latitude) + 
            (loc1.longitude - loc2.longitude) * (loc1.longitude - loc2.longitude));
}

// Function to display navigation instruction
void navigate(Location locations[], int startIndex, int endIndex) {
    printf("Navigating from %s to %s...\n", locations[startIndex].name, locations[endIndex].name);
    float distance = calculate_distance(locations[startIndex], locations[endIndex]);
    printf("Estimated distance: %.2f (units)\n", distance);
    printf("Follow the path to reach your destination.\n");
    printf("You have arrived at your destination: %s\n", locations[endIndex].name);
}

int main() {
    Location locations[MAX_LOCATIONS];
    int locationCount = 0;

    // Adding some predefined locations
    strcpy(locations[locationCount].name, "Home");
    locations[locationCount].latitude = 37.7749;
    locations[locationCount].longitude = -122.4194;
    locationCount++;

    strcpy(locations[locationCount].name, "Office");
    locations[locationCount].latitude = 37.7849;
    locations[locationCount].longitude = -122.4094;
    locationCount++;

    strcpy(locations[locationCount].name, "Park");
    locations[locationCount].latitude = 37.7649;
    locations[locationCount].longitude = -122.4294;
    locationCount++;

    strcpy(locations[locationCount].name, "Supermarket");
    locations[locationCount].latitude = 37.7549;
    locations[locationCount].longitude = -122.4394;
    locationCount++;

    int startIndex, endIndex;

    while (1) {
        display_locations(locations, locationCount);
        
        printf("Enter the number of the starting location (0 to exit): ");
        scanf("%d", &startIndex);
        
        if (startIndex == 0) break;

        printf("Enter the number of the destination location: ");
        scanf("%d", &endIndex);

        // Decrementing by one to match array indices as we're using 1-based index in user input
        startIndex--;
        endIndex--;

        if (startIndex < 0 || startIndex >= locationCount || endIndex < 0 || endIndex >= locationCount) {
            printf("Invalid location selection. Please try again.\n");
            continue;
        }

        navigate(locations, startIndex, endIndex);
    }

    printf("Thank you for using the GPS Navigation Simulator!\n");
    return 0;
}