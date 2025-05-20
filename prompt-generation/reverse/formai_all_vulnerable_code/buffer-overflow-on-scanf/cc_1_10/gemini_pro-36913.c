//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024

typedef struct {
    double latitude;
    double longitude;
    char description[MAX_STRING_LENGTH];
} Location;

// Function to generate a random location
Location generate_random_location() {
    Location location;
    location.latitude = (double)rand() / RAND_MAX * 180 - 90;
    location.longitude = (double)rand() / RAND_MAX * 360 - 180;
    sprintf(location.description, "You are now in a surreal landscape, where the laws of physics and logic do not apply.");
    return location;
}

// Function to print a location
void print_location(Location location) {
    printf("Latitude: %.6f\n", location.latitude);
    printf("Longitude: %.6f\n", location.longitude);
    printf("Description: %s\n", location.description);
}

// Main function
int main() {
    srand(time(NULL));

    // Generate a random starting location
    Location current_location = generate_random_location();

    // Print the starting location
    print_location(current_location);

    // Simulate GPS navigation
    while (1) {
        // Get user input
        char input[MAX_STRING_LENGTH];
        printf("Enter a direction (N, S, E, W, Q to quit): ");
        scanf("%s", input);

        // Quit if the user enters Q
        if (strcmp(input, "Q") == 0) {
            break;
        }

        // Update the current location based on the user input
        switch (input[0]) {
            case 'N':
                current_location.latitude += 1;
                break;
            case 'S':
                current_location.latitude -= 1;
                break;
            case 'E':
                current_location.longitude += 1;
                break;
            case 'W':
                current_location.longitude -= 1;
                break;
        }

        // Generate a new description for the current location
        sprintf(current_location.description, "You are now in a surreal landscape, where the laws of physics and logic do not apply. The sky is a kaleidoscope of colors, and the ground is a patchwork of melting clocks.");

        // Print the updated location
        print_location(current_location);
    }

    return 0;
}