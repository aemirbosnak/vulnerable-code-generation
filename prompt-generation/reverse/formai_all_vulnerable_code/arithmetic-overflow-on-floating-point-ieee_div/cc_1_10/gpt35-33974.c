//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random coordinates
void generateCoordinates(int *x, int *y) {
    *x = rand() % 101;
    *y = rand() % 101;
}

// Function to calculate distance between two points
float calculateDistance(int x1, int y1, int x2, int y2) {
    int xDiff = x2 - x1;
    int yDiff = y2 - y1;
    return sqrt((xDiff * xDiff) + (yDiff * yDiff));
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the starting coordinates for the spaceship
    int shipX, shipY;
    generateCoordinates(&shipX, &shipY);
    printf("Your spaceship is starting at (%d, %d)\n", shipX, shipY);
    
    // Generate the location of the nearest planet
    int planetX, planetY;
    generateCoordinates(&planetX, &planetY);
    printf("The nearest planet is located at (%d, %d)\n", planetX, planetY);
    
    // Prompt the user to enter their spaceship's speed
    int speed;
    printf("Enter your spaceship's speed (1-10): ");
    scanf("%d", &speed);
    
    // Calculate the distance to the planet and the time it will take to get there
    float distance = calculateDistance(shipX, shipY, planetX, planetY);
    float time = distance / speed;
    printf("It will take approximately %.2f hours to travel to the planet.\n", time);
    
    // Generate a random encounter with an alien race
    int encounter = rand() % 2;
    if (encounter) {
        printf("You have encountered an alien race!\n");
        // Generate a random outcome for the encounter
        int outcome = rand() % 3;
        switch (outcome) {
            case 0:
                printf("The aliens are friendly and offer to trade with you.\n");
                break;
            case 1:
                printf("The aliens are hostile and attack your spaceship.\n");
                break;
            case 2:
                printf("The aliens are curious and want to study your spaceship.\n");
                break;
        }
    } else {
        printf("You did not encounter any aliens on your journey.\n");
    }
    
    return 0;
}