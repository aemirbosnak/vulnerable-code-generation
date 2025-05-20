//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
// Sample code snippet for initiating the game

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLAYERS 4 // maximum number of players allowed
#define MIN_POINTS 100 // minimum number of points required to win

int main(){
    struct player {
        char organism[20];
        int points;
    } players[MAX_PLAYERS];

    int numOfPlayers, i;

    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Enter the number of players (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &numOfPlayers);

    if(numOfPlayers > MAX_PLAYERS){
        printf("Sorry, the maximum number of players allowed is %d.\n", MAX_PLAYERS);
        return 0;
    }

    printf("\n");

    // get organism choice and assign points
    for(i = 0; i < numOfPlayers; i++){
        printf("Player %d, choose your organism: ", i + 1);

        // code for getting organism choice goes here

        players[i].points = 50 + rand() % 50; // assign random point value between 50 and 100
    }

    // code for sequencing process goes here

    // determine winner and display results
    bool tie = false; // flag to check for tie
    int maxPoints = 0, winner;

    printf("\nFinal results:\n");

    for(i = 0; i < numOfPlayers; i++){
        printf("Player %d - %s: %d points\n", i + 1, players[i].organism, players[i].points);
        
        if(players[i].points > maxPoints){
            maxPoints = players[i].points;
            winner = i;
            tie = false;
        }
        else if(players[i].points == maxPoints){
            tie = true;
        }
    }

    if(tie){
        printf("\nIt's a tie!\n");
    }
    else if(players[winner].points >= MIN_POINTS){
        printf("\nPlayer %d (%s) is the winner!\n", winner + 1, players[winner].organism);
    }
    else {
        printf("\nNo player has reached the minimum required points to win (%d).\n", MIN_POINTS);
    }

    return 0;
}