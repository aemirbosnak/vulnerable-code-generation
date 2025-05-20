//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

//function to calculate maximum value index from an array
int maxValueIndex(int arr[], int size) {
    int maxVal = arr[0], maxIndex = 0;
    for(int i=1; i<size; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

//function to play the game for the player with id "playerId"
void playGame(int playerId, int numPlayers, int numPiles, int piles[]) {
    int maxVal, maxIndex, stonesTaken, totalStonesLeft = 0;
    //calculate initial total stones count
    for(int i=0; i<numPiles; i++) {
        totalStonesLeft += piles[i];
    }
    printf("Total stones left: %d\n", totalStonesLeft);
    //continue game till there are stones left
    while(totalStonesLeft > 0) {
        //calculate maximum value index from piles[]
        maxIndex = maxValueIndex(piles, numPiles);
        maxVal = piles[maxIndex];
        //if player with playerId is the one with maxVal from the current pile, then take all stones from that pile.
        if(maxIndex/(numPiles/numPlayers) == playerId) {
            printf("Player %d takes %d stones from pile %d\n", playerId, maxVal, maxIndex%(numPiles/numPlayers));
            stonesTaken = maxVal;
        }
        else {
            stonesTaken = rand()%(maxVal/2)+1;
            printf("Player %d takes %d stones from pile %d\n", playerId, stonesTaken, maxIndex%(numPiles/numPlayers));
        }
        piles[maxIndex] -= stonesTaken;
        totalStonesLeft -= stonesTaken;
        //print current status of piles after current move
        printf("Current piles status: ");
        for(int i=0; i<numPiles; i++) {
            printf("%d ", piles[i]);
        }
        printf("\n");
        //if only one player has stones, declare winner and end game
        if(totalStonesLeft == 0) {
            printf("Player %d wins!\n", playerId);
            return;
        }
    }
}

int main() {
    int numPlayers, numPiles, *piles;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    printf("Enter number of piles: ");
    scanf("%d", &numPiles);
    piles = (int*) malloc(numPiles*sizeof(int));
    //initialize piles randomly
    for(int i=0; i<numPiles; i++) {
        piles[i] = rand()%20 + 5;
    }
    //print initial status of piles
    printf("Initial piles status: ");
    for(int i=0; i<numPiles; i++) {
        printf("%d ", piles[i]);
    }
    printf("\n");
    //play game for each player
    for(int i=0; i<numPlayers; i++) {
        printf("*** Player %d's turn ***\n", i);
        playGame(i, numPlayers, numPiles, piles);
    }
    free(piles);
    return 0;
}