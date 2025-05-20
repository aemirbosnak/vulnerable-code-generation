//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()

int main() {
    int playerScore = 0;
    int computerScore = 0;
    srand(time(0));  // seed for rand() function
    
    printf("Welcome to the Rock-Paper-Scissors game!\n");
    printf("Enter '0' for Rock, '1' for Paper, or '2' for Scissors.\n");
    
    for (int i=1; i<=5; i++) {
        int playerChoice, computerChoice;
        
        printf("\nRound %d - ", i);
        
        // get player's choice
        printf("Your turn: ");
        scanf("%d", &playerChoice);
        if (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice. Try again.\n");
            i--;
            continue;
        }
        
        // get computer's choice
        computerChoice = rand() % 3;
        switch (computerChoice) {
            case 0:
                printf("Computer's turn: Rock\n");
                break;
            case 1:
                printf("Computer's turn: Paper\n");
                break;
            case 2:
                printf("Computer's turn: Scissors\n");
                break;
        }
        
        // determine the winner of the round
        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        }
        else if (playerChoice == 0 && computerChoice == 2 ||
                 playerChoice == 1 && computerChoice == 0 ||
                 playerChoice == 2 && computerChoice == 1) {
            printf("You win!\n");
            playerScore++;
        }
        else {
            printf("Computer wins!\n");
            computerScore++;
        }
    }
    
    // determine the winner of the game
    printf("\nGame over!\n\n");
    if (playerScore > computerScore) {
        printf("Congratualations! You win the game by %d-%d.\n", playerScore, computerScore);
    }
    else if (playerScore < computerScore) {
        printf("Sorry! Computer wins the game by %d-%d.\n", computerScore, playerScore);
    }
    else {
        printf("It's a tie game by %d-%d.\n", playerScore, computerScore);
    }
    
    return 0;
}