//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a range
int generateRandom(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to print the opening dialogue
void openingDialogue() {
    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("You are an astronaut on a mission to explore the unknown depths of space.\n");
    printf("Your ship has landed on an uncharted planet.\n");
}

// Function to implement the game
void playGame() {
    int choice, fuel = 100, distance = 0, randFuel, randDistance;
    
    printf("You have 100 units of fuel to start your journey.\n");
    printf("Your goal is to explore as much of this planet as possible.\n");
    
    while (fuel > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore the surroundings\n");
        printf("2. Refuel your ship\n");
        printf("3. Quit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                randFuel = generateRandom(5, 20);
                randDistance = generateRandom(10, 50);
                printf("\nYou explore the surroundings and gather resources.\n");
                printf("You gained %d units of fuel and travelled %d units of distance.\n", randFuel, randDistance);
                fuel -= randFuel;
                distance += randDistance;
                break;
            case 2:
                printf("\nYou refuel your ship.\n");
                fuel = 100;
                break;
            case 3:
                printf("\nThanks for playing. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
        
        if (distance >= 500) {
            printf("\nCongratulations! You have explored the planet and discovered valuable resources.\n");
            printf("Thanks for playing. Goodbye!\n");
            exit(0);
        }
        
        if (fuel <= 0) {
            printf("\nYou have run out of fuel. Game over.\n");
            exit(0);
        }
    }
}

// Function to print the closing dialogue
void closingDialogue() {
    printf("\nThanks for playing Procedural Space Adventure!\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    openingDialogue();  // Print the opening dialogue
    playGame();         // Play the game
    closingDialogue();  // Print the closing dialogue
    return 0;           // Exit the program
}