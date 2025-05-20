//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get user’s choice and validate input
int getUserChoice() {
    int choice;
    printf("\nEnter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3) {
        printf("\nInvalid input. Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
        scanf("%d", &choice);
    }
    return choice;
}

int main() {
    // Initialization
    srand(time(NULL)); // Seed the random number generator
    int userScore = 0;
    int compScore = 0;
    int rounds = 0;
    
    // Game Loop
    while (1) {
        // Get user's choice
        int userChoice = getUserChoice();
        // Get computer's choice
        int compChoice = (rand() % 3) + 1;
        // Display choices
        printf("\nYou chose ");
        switch (userChoice) {
            case 1: printf("Rock"); break;
            case 2: printf("Paper"); break;
            case 3: printf("Scissors"); break;
        }
        printf(".\nComputer chose ");
        switch (compChoice) {
            case 1: printf("Rock"); break;
            case 2: printf("Paper"); break;
            case 3: printf("Scissors"); break;
        }

        // Determine winner and update scores
        if (userChoice == compChoice) {
            printf(".\nIt's a tie!");   
        } else if (userChoice == 1 && compChoice == 3 ||
                   userChoice == 2 && compChoice == 1 ||
                   userChoice == 3 && compChoice == 2) {
            printf(".\nYou win!");
            userScore++;
        } else {
            printf(".\nComputer wins.");
            compScore++;
        }
        
        // Display scores
        printf("\nScore: You - %d, Computer - %d\n", userScore, compScore);
        
        // Ask user if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        char playAgain;
        scanf(" %c", &playAgain);
        while (playAgain != 'y' && playAgain != 'n') {
            printf("\nInvalid input. Do you want to play again? (y/n): ");
            scanf(" %c", &playAgain);
        }
        if (playAgain == 'n') {
            break; // Exit the game loop
        } else {
            rounds++;
        }
    }
    
    // Game over
    printf("\nThanks for playing! Final score: You - %d, Computer - %d\n", userScore, compScore);
    if (userScore > compScore) {
        printf("You won the game!\n");
    } else if (userScore < compScore) {
        printf("Computer won the game.\n");
    } else {
        printf("The game ended in a tie.\n");
    }
    printf("Total rounds played: %d\n", rounds);
    
    return 0;
}