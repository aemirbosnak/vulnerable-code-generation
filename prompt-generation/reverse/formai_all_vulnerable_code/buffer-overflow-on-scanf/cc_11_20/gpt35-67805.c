//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// implementation of the puzzle game
int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("You must navigate through a series of challenges to determine the probability of an alien invasion on Earth.\n");
    printf("Each challenge will result in a percentage increase or decrease in the overall probability.\n");
    
    srand(time(0)); // seed the random number generator
    
    // initialize starting probability
    float prob = 50.0f;
    printf("Starting probability: %.2f%%\n", prob);
    
    // start the game loop
    bool gameOver = false;
    while (!gameOver) {
        printf("\n");
        printf("Choose a challenge:\n");
        printf("1. Decrypt alien transmission (+10%)\n");
        printf("2. Defeat alien probe (-5%)\n");
        printf("3. Make peace with alien ambassador (+20%)\n");
        printf("4. Research new weapon (-15%)\n");
        printf("5. Random event\n");
        printf("6. Quit\n");
        
        int choice;
        scanf("%d", &choice); // get user input
        
        switch (choice) {
            case 1:
                printf("You successfully decrypt an alien transmission. Probability +10%%.\n");
                prob += 10.0f;
                break;
            case 2:
                printf("You successfully defeat an alien probe. Probability -5%%.\n");
                prob -= 5.0f;
                break;
            case 3:
                printf("You make peace with an alien ambassador. Probability +20%%.\n");
                prob += 20.0f;
                break;
            case 4:
                printf("You research a new weapon. Probability -15%%.\n");
                prob -= 15.0f;
                break;
            case 5:
                printf("A random event occurs...\n");
                int randNum = rand() % 4 + 1; // generate random number between 1 and 4
                switch (randNum) {
                    case 1:
                        printf("A meteor strike damages your research facility. Probability -10%%.\n");
                        prob -= 10.0f;
                        break;
                    case 2:
                        printf("A breakthrough in quantum computing allows you to predict the alien's next move. Probability +5%%.\n");
                        prob += 5.0f;
                        break;
                    case 3:
                        printf("An alien spy infiltrates your base. Probability -25%%.\n");
                        prob -= 25.0f;
                        break;
                    case 4:
                        printf("You discover a new energy source. Probability +15%%.\n");
                        prob += 15.0f;
                        break;
                }
                break;
            case 6:
                printf("Thanks for playing!\n");
                printf("Final probability: %.2f%%\n", prob);
                gameOver = true;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
        // check if probability is outside of range [0, 100]
        if (prob < 0.0f) {
            prob = 0.0f;
        } else if (prob > 100.0f) {
            prob = 100.0f;
        }
        
        printf("Current probability: %.2f%%\n", prob);
    }
    
    return 0;
}