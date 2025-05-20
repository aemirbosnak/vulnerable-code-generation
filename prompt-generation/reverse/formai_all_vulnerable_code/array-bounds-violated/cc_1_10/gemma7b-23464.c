//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define map dimensions
#define WIDTH 10
#define HEIGHT 10

// Define GPS coordinates
int current_x = 0;
int current_y = 0;

// Define map array
int map[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Function to simulate GPS navigation
void navigate() {
    // Display current location
    printf("Current position: (%d, %d)\n", current_x, current_y);

    // Get user input
    int direction = rand() % 4;

    // Move in the chosen direction
    switch (direction) {
        case 0:
            current_x++;
            break;
        case 1:
            current_y++;
            break;
        case 2:
            current_x--;
            break;
        case 3:
            current_y--;
            break;
    }

    // Check if the new location is valid
    if (map[current_y][current_x] == 0) {
        // Display error message
        printf("Error: Invalid location!\n");
        // Reset current position
        current_x = current_y = 0;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Simulate navigation for 10 steps
    for (int i = 0; i < 10; i++) {
        navigate();
    }

    return 0;
}