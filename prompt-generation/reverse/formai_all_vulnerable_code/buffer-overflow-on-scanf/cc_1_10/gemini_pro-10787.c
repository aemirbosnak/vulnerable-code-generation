//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Our virtual car, represented by a GPS receiver
typedef struct {
    double latitude;
    double longitude;
} GPS;

// A simple command line parser
int parse_command(char *command, GPS *car) {
    if (strcmp(command, "north") == 0) {
        car->latitude++;
    } else if (strcmp(command, "south") == 0) {
        car->latitude--;
    } else if (strcmp(command, "east") == 0) {
        car->longitude++;
    } else if (strcmp(command, "west") == 0) {
        car->longitude--;
    } else {
        return 0; // Invalid command
    }
    return 1;
}

// Print the current location of the car
void print_location(GPS car) {
    printf("Your current location: %.6f, %.6f\n", car.latitude, car.longitude);
}

int main() {
    GPS car = {0.0, 0.0}; // Start at the origin

    // Initialize the random number generator
    srand(time(NULL));

    while (1) {
        // Get the next command from the user
        char command[100];
        printf("Enter a command (north, south, east, west, quit): ");
        scanf("%s", command);

        // Parse the command and update the car's position
        if (!parse_command(command, &car)) {
            printf("Invalid command!\n");
            continue;
        }

        // Simulate GPS inaccuracies by adding some random noise
        car.latitude += (rand() / (RAND_MAX + 1.0)) * 0.01;
        car.longitude += (rand() / (RAND_MAX + 1.0)) * 0.01;

        // Print the current location of the car
        print_location(car);

        // Check if the car has reached its destination
        if (car.latitude == 1.0 && car.longitude == 0.0) {
            printf("You have reached your destination!\n");
            break;
        }
    }

    return 0;
}