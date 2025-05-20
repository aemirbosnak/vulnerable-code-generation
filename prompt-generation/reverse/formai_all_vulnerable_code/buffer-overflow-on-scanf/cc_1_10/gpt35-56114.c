//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to check if the player wants to continue the game
int gameContinue()
{
    char option;
    printf("\nDo you wish to continue? (Y/N) ");
    scanf("%c", &option);
    if (option == 'Y' || option == 'y') {
        return 1;
    }
    return 0;
}

// Function for the main game
void playGame()
{
    int score = 0; // initialize the score variable
    srand(time(NULL)); // set the seed for random number generation
    printf("\nWelcome to the Space Adventure!\n");
    printf("Your mission is to explore the unknown galaxies and collect as many points as possible.\n");
    printf("You will encounter different challenges and obstacles along the way, so be prepared!\n\n");
    
    // Game loop
    while (1) {
        int random = rand() % 5 + 1; // generate a random number between 1 and 5
        printf("You have entered galaxy number %d\n", random);
        
        // Random events in each galaxy
        if (random == 1) {
            printf("You have encountered a black hole! All your previous scores will be lost.\n");
            score = 0;
        }
        else if (random == 2) {
            printf("You have discovered a new planet! You gain 10 points.\n");
            score += 10;
        }
        else if (random == 3) {
            printf("You have found an abandoned spaceship. You gain 5 points.\n");
            score += 5;
        }
        else if (random == 4) {
            printf("You are attacked by alien spaceships. You lose 5 points.\n");
            score -= 5;
        }
        else {
            printf("You have entered a space debris field. You have to navigate carefully. No points gained or lost.\n");
        }
        
        printf("Your current score is %d\n", score);
        if (score < 0) { // check if the score is negative
            printf("Game over! You have lost all your points.\n");
            break;
        }
        
        if (!gameContinue()) { // check if the player wants to continue the game
            printf("Final score: %d\n", score);
            break;
        }
    }
}

// Main function
int main()
{
    char option;
    printf("Welcome to the Space Adventure!\n");
    printf("Do you wish to start playing? (Y/N) ");
    scanf("%c", &option);
    if (option == 'Y' || option == 'y') {
        playGame();
    }
    else {
        printf("Thank you for visiting. Goodbye!\n");
    }
    return 0;
}