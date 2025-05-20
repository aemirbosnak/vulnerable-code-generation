//Falcon-180B DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers, numRolls, i, j, k, maxRoll, playerScore[10], rollCount[6] = {0};
    char playerName[10][20];
    float avgScore;

    //initialize random seed
    srand(time(0));

    //get number of players
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    //get player names
    for(i=0; i<numPlayers; i++) {
        printf("Enter player %d name: ", i+1);
        scanf("%s", playerName[i]);
    }

    //get number of rolls
    printf("Enter number of rolls: ");
    scanf("%d", &numRolls);

    //roll dice and calculate scores
    for(i=0; i<numRolls; i++) {
        for(j=0; j<numPlayers; j++) {
            playerScore[j] += rand()%6 + 1;
            rollCount[playerScore[j]%6]++;
        }
    }

    //print scores and roll counts
    printf("\nPlayer Scores:\n");
    for(i=0; i<numPlayers; i++) {
        printf("%s: %d\n", playerName[i], playerScore[i]);
    }

    printf("\nRoll Counts:\n");
    for(i=1; i<=6; i++) {
        printf("%d: %d\n", i, rollCount[i-1]);
    }

    //calculate average score
    avgScore = (float)numRolls / numPlayers;
    printf("\nAverage Score: %.2f\n", avgScore);

    //determine max roll
    maxRoll = 1;
    for(i=0; i<numPlayers; i++) {
        for(j=0; j<6; j++) {
            if(playerScore[i]%6 == j+1 && j+1 > maxRoll) {
                maxRoll = j+1;
            }
        }
    }
    printf("\nMax Roll: %d\n", maxRoll);

    return 0;
}