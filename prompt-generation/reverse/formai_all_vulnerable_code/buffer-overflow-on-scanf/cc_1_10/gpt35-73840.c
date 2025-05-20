//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the GPS structure
typedef struct GPSCoordinates {
    double latitude;
    double longitude;
} GPSCoordinates;

int main() {
    // Store the initial coordinates
    GPSCoordinates currentLocation = {37.7749, -122.4194};
    
    // Print a welcome message
    printf("Welcome to the GPS Navigation Simulation Program!\n");
    printf("Your current location is: (%lf, %lf)\n\n", currentLocation.latitude, currentLocation.longitude);
    
    // Prompt the user for the desired destination
    printf("Please enter the coordinates of your desired destination: \n");
    
    // Get the latitude and longitude from the user
    double latitude;
    double longitude;
    printf("Latitude: ");
    scanf("%lf", &latitude);
    printf("Longitude: ");
    scanf("%lf", &longitude);
    
    printf("\nCalculating route to (%lf, %lf)...\n\n", latitude, longitude);
    
    // Simulate the GPS navigation
    bool arrived = false;
    int steps = 0;
    while(!arrived) {
        // Update the current location
        currentLocation.latitude += (latitude - currentLocation.latitude)/10;
        currentLocation.longitude += (longitude - currentLocation.longitude)/10;
        
        // Print the current location
        printf("Step %d: (%lf, %lf)\n", steps, currentLocation.latitude, currentLocation.longitude);
        
        // Check if the location has been reached
        if(currentLocation.latitude == latitude && currentLocation.longitude == longitude) {
            arrived = true;
            printf("\nYou have arrived at your destination!\n");
        }
        
        // Increment the step count
        steps++;
    }
    
    return 0;
}