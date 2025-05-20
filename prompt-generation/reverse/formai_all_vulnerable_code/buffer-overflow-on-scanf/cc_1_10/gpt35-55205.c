//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that randomly generates a planet
int generatePlanet() {
    int planet = rand() % 4; // Generate a number between 0 and 3
    switch (planet) {
        case 0:
            printf("You have landed on a rocky planet.\n");
            break;
        case 1:
            printf("You have landed on a desert planet.\n");
            break;
        case 2:
            printf("You have landed on an ice planet.\n");
            break;
        case 3:
            printf("You have landed on a lush planet.\n");
            break;
    }
    return planet;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the initial planet
    int currentPlanet = generatePlanet();
    
    // Add a variable to keep track of the number of jumps
    int jumpCount = 0;
    
    // Loop until the player reaches the lush planet
    while (currentPlanet != 3) {
        printf("You have completed %d jumps.\n", jumpCount);
        printf("Enter '1' to make a jump, or '0' to quit.\n");
        int choice;
        scanf("%d", &choice);
        
        // Make sure the player enters a valid choice
        while (choice != 0 && choice != 1) {
            printf("Invalid input, please try again.\n");
            scanf("%d", &choice);
        }
        
        if (choice == 0) {
            printf("You have quit the game.\n");
            break;
        }
        
        // Increment the jump count
        jumpCount++;
        
        // Generate a new planet
        currentPlanet = generatePlanet();
        
        // Add a shape shifting mechanic
        int shape = rand() % 3; // Generate a number between 0 and 2
        switch (shape) {
            case 0:
                printf("You have shifted into a humanoid shape.\n");
                break;
            case 1:
                printf("You have shifted into a quadruped shape.\n");
                break;
            case 2:
                printf("You have shifted into a winged shape.\n");
                break;
        }
    }
    
    // Check if the player won or quit
    if (currentPlanet == 3) {
        printf("Congratulations! You have reached the lush planet.\n");
        printf("It took you %d jumps to get there.\n", jumpCount);
    }
    
    return 0;
}