//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define global variables
int x = 0;
int y = 0;
int dest_x = 0;
int dest_y = 0;
int distance = 0;

// Define a function to calculate distance between current location and destination
int calcDistance() {
    // Use Pythagorean Theorem to calculate distance
    distance = sqrt(pow(dest_x-x, 2) + pow(dest_y-y, 2));
    return distance;
}

int main() {
    printf("Welcome to GPS Navigation! Let's set your destination!\n");

    // Set destination coordinates
    printf("Enter the X-coordinate of your destination: ");
    scanf("%d", &dest_x);

    printf("Enter the Y-coordinate of your destination: ");
    scanf("%d", &dest_y);

    printf("Great! Your destination is (%d,%d)\n", dest_x, dest_y);

    // Loop until destination is reached
    while(distance > 0) {
        printf("\nWe are currently at (%d,%d)\n", x, y);

        // Calculate remaining distance
        distance = calcDistance();

        // Determine next move
        if(dest_x > x && dest_y > y) {
            printf("Take a step to the right and up!\n");
            x++;
            y++;
        }
        else if(dest_x > x && dest_y < y) {
            printf("Take a step to the right and down!\n");
            x++;
            y--;
        }
        else if(dest_x < x && dest_y > y) {
            printf("Take a step to the left and up!\n");
            x--;
            y++;
        }
        else if(dest_x < x && dest_y < y) {
            printf("Take a step to the left and down!\n");
            x--;
            y--;
        }
        else if(dest_x > x) {
            printf("Take a step to the right!\n");
            x++;
        }
        else if(dest_x < x) {
            printf("Take a step to the left!\n");
            x--;
        }
        else if(dest_y > y) {
            printf("Take a step up!\n");
            y++;
        }
        else if(dest_y < y) {
            printf("Take a step down!\n");
            y--;
        }
        else {
            printf("\nYou have arrived! Enjoy your destination!\n");
            break;
        }

        // Recalculate remaining distance
        distance = calcDistance();
    }

    return 0;
}