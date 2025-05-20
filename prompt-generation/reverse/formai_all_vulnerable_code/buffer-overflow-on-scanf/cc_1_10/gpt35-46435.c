//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number 
int rollDice() {
    int diceResult = (rand() % 6) + 1;
    return diceResult;
}

int main() {
    srand(time(0)); // Seeding random number generator with current time
    
    int player1Score = 0, player2Score = 0; // Initialize scores for two players
    
    printf("Let's play a game of dice! Player 1 goes first.\n\n");
    
    int playerTurn = 1; // Initialize turn to Player 1
    
    while(player1Score < 50 && player2Score < 50) { // Loop until one player reaches a score of 50 or higher
        
        int turnScore = 0; // Score for the current player turn
        
        printf("Player %d, press enter to roll the dice...", playerTurn);
        getchar(); // Wait for user input
        
        int diceValue = rollDice();
        
        printf("You rolled a %d.\n", diceValue);
        
        if(diceValue == 1) {
            printf("Bad luck! You lose this turn.\n");
        } else {
            turnScore += diceValue; // Add the initial dice value to turn score
            
            char choice;
            printf("Your turn score is %d. Do you want to continue (Y/N)? ", turnScore);
            scanf(" %c", &choice);
            
            while(choice == 'Y') { // Ask player if they want to continue rolling
                int rollValue = rollDice();
                
                printf("You rolled a %d.\n", rollValue);
                
                if(rollValue == 1) {
                    printf("Bad luck! You lose this turn.\n");
                    break;
                } else {
                    turnScore += rollValue; // Add the roll value to turn score
                    
                    if(turnScore >= 20) { // End turn if turn score is 20 or higher
                        printf("Nice roll! You end your turn with a score of %d.\n", turnScore);
                        break;
                    }
                    
                    printf("Your turn score is now %d. Do you want to continue (Y/N)? ", turnScore);
                    scanf(" %c", &choice);
                }
            }
        }
        
        if(playerTurn == 1) { // Update Player 1 score if it was their turn
            player1Score += turnScore;
        } else { // Update Player 2 score if it was their turn
            player2Score += turnScore;
        }
        
        printf("Player 1 score: %d\nPlayer 2 score: %d\n\n", player1Score, player2Score);
        
        // Switch turn to other player
        if(playerTurn == 1) {
            playerTurn = 2;
        } else {
            playerTurn = 1;
        }
    }
    
    // Declare winner based on scores
    if(player1Score >= 50) {
        printf("Player 1 wins with a score of %d!\n", player1Score);
    } else {
        printf("Player 2 wins with a score of %d!\n", player2Score);
    }
    
    return 0;
}