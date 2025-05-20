//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>

// Structure to hold the current position of the user
struct Position {
    int x;
    int y;
};

int main() {
    // Set the starting position
    struct Position current = {0, 0};
    
    // Create a map of the kingdom
    int map[10][10] = {
        // 0 represents a safe area, 1 represents a dangerous area
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    // Loop through the map until the user reaches the destination
    int destinationReached = 0;
    while(!destinationReached) {
        printf("Current position: (%d, %d)\n", current.x, current.y);
        
        // Check if the user is in a dangerous area
        if(map[current.x][current.y] == 1) {
            printf("*WARNING* You are in a dangerous area! Use caution.\n");
        }
        
        // Prompt the user for their desired direction
        char direction;
        printf("Enter your desired direction (N, S, E, W): ");
        scanf(" %c", &direction);
        
        // Update the user's position based on their direction
        if(direction == 'N') {
            if(current.x == 0) {
                printf("*ERROR* You cannot go any further north.\n");
            } else {
                current.x--;
            }
        } else if(direction == 'S') {
            if(current.x == 9) {
                printf("*ERROR* You cannot go any further south.\n");
            } else {
                current.x++;
            }
        } else if(direction == 'E') {
            if(current.y == 9) {
                printf("*ERROR* You cannot go any further east.\n");
            } else {
                current.y++;
            }
        } else if(direction == 'W') {
            if(current.y == 0) {
                printf("*ERROR* You cannot go any further west.\n");
            } else {
                current.y--;
            }
        } else {
            printf("*ERROR* Invalid direction.\n");
        }
        
        // Check if the user has reached the destination
        if(current.x == 9 && current.y == 9) {
            printf("Congratulations! You have reached your destination!\n");
            destinationReached = 1;
        }
    }
    
    return 0;
}