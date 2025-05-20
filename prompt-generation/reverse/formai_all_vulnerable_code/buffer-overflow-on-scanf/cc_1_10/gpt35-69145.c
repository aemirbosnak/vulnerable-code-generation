//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random latitude and longitude
void generateCoordinates(float* lat, float* lon) {
    *lat = ((float)rand() / RAND_MAX) * (90.0 - (-90.0)) + (-90.0);
    *lon = ((float)rand() / RAND_MAX) * (180.0 - (-180.0)) + (-180.0);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    
    float currentLat, currentLon, destinationLat, destinationLon;
    int choice, distance;
    
    // Generate current location
    generateCoordinates(&currentLat, &currentLon);
    
    // Generate destination location
    generateCoordinates(&destinationLat, &destinationLon);
    
    // Print initial position and destination
    printf("Initial position: (%.2f, %.2f)\n", currentLat, currentLon);
    printf("Destination: (%.2f, %.2f)\n", destinationLat, destinationLon);
    
    // Prompt user for navigation options
    printf("Enter 1 to view distance between current location and destination location.\n");
    printf("Enter 2 to generate new destination location.\n");
    printf("Enter 3 to exit navigation simulation.\n");
    
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        // View distance between current location and destination location
        if (choice == 1) {
            distance = (int)(69.1 * sqrt((destinationLat - currentLat) * (destinationLat - currentLat) + (destinationLon - currentLon) * (destinationLon - currentLon)));
            printf("Distance between current location and destination location: %d miles\n", distance);
        }
        
        // Generate new destination location
        else if (choice == 2) {
            generateCoordinates(&destinationLat, &destinationLon);
            printf("New destination: (%.2f, %.2f)\n", destinationLat, destinationLon);
        }
        
        // Exit navigation simulation
        else if (choice == 3) {
            printf("Exiting navigation simulation...\n");
            break;
        }
        
        // Invalid choice
        else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    
    return 0;
}