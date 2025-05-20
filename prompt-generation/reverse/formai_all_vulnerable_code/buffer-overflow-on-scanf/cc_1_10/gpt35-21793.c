//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //Seed the random number generator
    srand(time(NULL));
    
    int numPlayers = 0;
    int numDice = 0;
    int playerScores[10];
    int i, j, k;
    
    //Prompt the user for the number of players
    printf("How many players are playing? ");
    scanf("%d", &numPlayers);
    
    //Prompt the user for the number of dice per player
    printf("How many dice per player? ");
    scanf("%d", &numDice);
    
    //Roll the dice for each player
    for(i = 0; i < numPlayers; i++) {
        int score = 0;
        printf("Player %d's rolls: ", i+1);
        for(j = 0; j < numDice; j++) {
            int roll = rand() % 6 + 1;
            score += roll;
            printf("%d ", roll);
        }
        playerScores[i] = score;
        printf("\nPlayer %d's score is: %d\n", i+1, score);
    }
    
    //Find the winner
    int winner = 0;
    int highScore = playerScores[0];
    for(k = 1; k < numPlayers; k++) {
        if(playerScores[k] > highScore) {
            highScore = playerScores[k];
            winner = k;
        }
    }
    
    //Print the winner
    printf("\nPlayer %d wins with a score of %d!\n", winner+1, highScore);
    
    return 0;
}