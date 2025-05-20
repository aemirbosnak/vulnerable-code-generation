//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include <stdio.h>

int main() {
    // Define initial GPS coordinates
    float currentLat = 37.7749;
    float currentLong = -122.4194;
    
    // Define destination GPS coordinates
    float destLat = 40.7128;
    float destLong = -74.0060;
    
    // Calculate distance to destination
    float distance = 69.5 * sqrt(pow((destLat - currentLat), 2) + pow((destLong - currentLong), 2));
    
    // Display distance to user
    printf("Distance to destination: %f miles\n", distance);
    
    // Simulate movement towards destination
    while (currentLat != destLat || currentLong != destLong) {
        // Determine direction to move in
        float latDiff = destLat - currentLat;
        float longDiff = destLong - currentLong;
        float newX, newY;
        
        if (latDiff > 0) {
            newX = currentLat + 0.001;
        } else if (latDiff < 0) {
            newX = currentLat - 0.001;
        } else {
            newX = currentLat;
        }
        
        if (longDiff > 0) {
            newY = currentLong + 0.001;
        } else if (longDiff < 0) {
            newY = currentLong - 0.001;
        } else {
            newY = currentLong;
        }
        
        // Update current GPS coordinates
        currentLat = newX;
        currentLong = newY;
        
        // Display updated coordinates to user
        printf("Current location: %f, %f\n", currentLat, currentLong);
    }
    
    // Arrived at destination
    printf("You have arrived at your destination!\n");
    
    return 0;
}