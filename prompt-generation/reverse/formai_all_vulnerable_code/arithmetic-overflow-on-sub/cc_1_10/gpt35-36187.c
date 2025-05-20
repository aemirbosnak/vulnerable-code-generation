//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //set the seed for random number generator

    int numPlayers;
    printf("Welcome to the C Table Game!\nHow many players? ");
    scanf("%d", &numPlayers);

    int scores[numPlayers]; //create an array to hold player scores
    for(int i=0; i<numPlayers; i++) {
        scores[i] = 0; //initialize all scores to 0
    }

    int currentPlayer = 0; //variable to track whose turn it is
    int round = 1; //variable to track which round it is

    printf("\nLet's begin!\n\n");

    while(round <= 5) { //play 5 rounds of the game
        printf("Round %d:\n", round);
        printf("Player %d's turn:\n", currentPlayer+1);

        int roll1 = rand() % 6 + 1; //generate random number between 1 and 6
        int roll2 = rand() % 6 + 1;
        int total = roll1 + roll2;

        printf("You rolled a %d and a %d for a total of %d\n", roll1, roll2, total);

        if(total % 2 == 0) { //if the total is even
            printf("Congratulations, that's an even number!\n");
            scores[currentPlayer] += total; //add the total to player's score
        } else {
            printf("That's an odd number. Sorry, no points for this round.\n");
        }

        printf("Player %d's score is now %d\n", currentPlayer+1, scores[currentPlayer]);

        if(currentPlayer == numPlayers-1) { //if the current player is the last player
            currentPlayer = 0; //move to the first player for the next round
            round++; //increment round count
        } else {
            currentPlayer++; //move to the next player
        }

        printf("\n");
    }

    printf("Game over! Final scores:\n");
    for(int i=0; i<numPlayers; i++) {
        printf("Player %d: %d\n", i+1, scores[i]); //print each player's final score
    }

    return 0;
}