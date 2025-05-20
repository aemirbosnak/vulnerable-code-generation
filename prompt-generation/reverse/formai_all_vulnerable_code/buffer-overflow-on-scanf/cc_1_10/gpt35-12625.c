//FormAI DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers;
    int maxNum = 100;
    int winningNum;
    int guesses[maxNum];
    int numGuesses = 0;
    int winnerIndex = -1;
    int i, j;
    
    srand(time(0));
    printf("Welcome to the guessing game! Please enter the number of players: ");
    scanf("%d", &numPlayers);
    
    // Generate the winning number for all players to guess
    winningNum = rand() % maxNum + 1;
    
    // Get each player's guess and store it in the guesses array
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d, please enter your guess: ", i+1);
        scanf("%d", &guesses[i]);
        numGuesses++;
    }
    
    // Determine the winner
    for (i = 0; i < numPlayers; i++) {
        if (guesses[i] == winningNum) {
            winnerIndex = i;
            break;
        }
        else if (guesses[i] > winningNum) {
            printf("Player %d's guess is too high.\n", i+1);
        }
        else {
            printf("Player %d's guess is too low.\n", i+1);
        }
    }
    
    // Print the winner and their winning guess
    printf("The winning number was %d.\n", winningNum);
    if (winnerIndex != -1) {
        printf("Player %d wins with a guess of %d!\n", winnerIndex+1, guesses[winnerIndex]);
    }
    else {
        printf("No one guessed the correct number.\n");
    }
    
    return 0;
}