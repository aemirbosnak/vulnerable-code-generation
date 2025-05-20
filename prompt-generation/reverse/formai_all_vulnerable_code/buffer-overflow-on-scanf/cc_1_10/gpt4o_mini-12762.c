//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Location;

typedef struct {
    Location start;
    Location destination;
} GPSNavigation;

void printGrid(Location current, Location destination) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == current.x && j == current.y) {
                printf("C "); // Current location
            } else if (i == destination.x && j == destination.y) {
                printf("D "); // Destination
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }
}

void calculateRoute(GPSNavigation nav) {
    Location current = nav.start;
    
    printf("Starting navigation from (%d, %d) to (%d, %d)\n", 
            current.x, current.y, nav.destination.x, nav.destination.y);
    
    // Simulate navigation
    while (current.x != nav.destination.x || current.y != nav.destination.y) {
        printGrid(current, nav.destination);
        if (current.x < nav.destination.x) {
            current.x++;
            printf("Moving Down to (%d, %d)\n", current.x, current.y);
        } else if (current.x > nav.destination.x) {
            current.x--;
            printf("Moving Up to (%d, %d)\n", current.x, current.y);
        }
        
        if (current.y < nav.destination.y) {
            current.y++;
            printf("Moving Right to (%d, %d)\n", current.x, current.y);
        } else if (current.y > nav.destination.y) {
            current.y--;
            printf("Moving Left to (%d, %d)\n", current.x, current.y);
        }
    }
    
    printf("You have reached your destination at (%d, %d)!\n", current.x, current.y);
}

int main() {
    GPSNavigation nav;
    
    printf("Welcome to the GPS Navigation Simulator!\n");
    printf("Please enter the starting location (x y): ");
    scanf("%d %d", &nav.start.x, &nav.start.y);

    // Validate starting location
    if (nav.start.x < 0 || nav.start.x >= GRID_SIZE || 
        nav.start.y < 0 || nav.start.y >= GRID_SIZE) {
        printf("Invalid starting location! It should be within grid size.\n");
        return 1;
    }

    printf("Please enter the destination location (x y): ");
    scanf("%d %d", &nav.destination.x, &nav.destination.y);
    
    // Validate destination location
    if (nav.destination.x < 0 || nav.destination.x >= GRID_SIZE || 
        nav.destination.y < 0 || nav.destination.y >= GRID_SIZE) {
        printf("Invalid destination location! It should be within grid size.\n");
        return 1;
    }

    // Check if starting point is the same as destination
    if (nav.start.x == nav.destination.x && nav.start.y == nav.destination.y) {
        printf("You are already at the destination!\n");
        return 0;
    }

    calculateRoute(nav);
    
    return 0;
}