//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initialise random number generator

    char directions[4][10] = {"Left", "Right", "Straight", "Backwards"}; // Possible directions
    
    int current_location[2]; // Current location of user
    current_location[0] = rand() % 100; // Randomly assign starting location
    current_location[1] = rand() % 100; 

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Your current location is (%d,%d).\n\n", current_location[0], current_location[1]);

    char destination[30]; // User's chosen destination

    printf("Please enter your desired destination: ");
    scanf("%s", destination);

    printf("\nOk! Let's navigate to %s.\n\n", destination);

    int steps = 0; // Number of steps to reach destination
    int total_distance = 0; // Total distance travelled
    int proximity = 10; // Proximity to destination (in km)

    while (proximity > 0) {

        int direction_num = rand() % 4; // Randomly choose direction
        int distance = rand() % 10 + 1; // Randomly choose distance (between 1 and 10 km)

        int new_location[2]; // Calculate new location based on direction and distance
        switch(direction_num) {
            case 0:
                printf("Step %d: Go left for %d km.\n", steps+1, distance);
                new_location[0] = current_location[0] - distance;
                new_location[1] = current_location[1];
                break;
            case 1:
                printf("Step %d: Go right for %d km.\n", steps+1, distance);
                new_location[0] = current_location[0] + distance;
                new_location[1] = current_location[1];
                break;
            case 2:
                printf("Step %d: Go straight for %d km.\n", steps+1, distance);
                new_location[0] = current_location[0];
                new_location[1] = current_location[1] + distance;
                break;
            case 3:
                printf("Step %d: Go backwards for %d km.\n", steps+1, distance);
                new_location[0] = current_location[0];
                new_location[1] = current_location[1] - distance;
                break;
        }

        current_location[0] = new_location[0]; // Update current location
        current_location[1] = new_location[1];

        int x_diff = abs(current_location[0] - 50); // Calculate proximity to destination (using (50,50) as the destination)
        int y_diff = abs(current_location[1] - 50);
        proximity = x_diff + y_diff;

        printf("Current location: (%d,%d)  Proximity to destination: %d km.\n\n", current_location[0], current_location[1], proximity);

        total_distance += distance; // Increment total distance
        steps++; // Increment steps

        // If user is too far from destination, suggest they use a different mode of transportation

        if (total_distance > 50) {
            printf("You've travelled over 50 km and you're still not close to your destination.\n");
            printf("Maybe try flying instead of driving? Or teleportation?\n");
            break;
        }

    }

    // Print final message and exit program

    printf("Congratulations! You've reached %s in %d steps and %d km travelled.\n", destination, steps, total_distance);
    printf("Thanks for using this GPS Navigation Simulation! Consider taking a scenic route next time.\n");

    return 0;
}