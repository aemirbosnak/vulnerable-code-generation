//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numCandidates, i, j;

    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    char** candidateList = (char**) malloc(numCandidates * sizeof(char*)); // Allocate memory for candidate names
    int* votes = (int*) calloc(numCandidates, sizeof(int)); // Allocate memory for votes, initialize to 0

    for (i = 0; i < numCandidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        candidateList[i] = (char*) malloc(100 * sizeof(char)); // Allocate memory for candidate name
        scanf("%s", candidateList[i]);
    }

    printf("Voting begins!\n");

    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    for (i = 0; i < numVoters; i++) {
        printf("Voter %d, please select your candidate by entering the corresponding number:\n", i+1);
        for (j = 0; j < numCandidates; j++) {
            printf("%d: %s\n", j+1, candidateList[j]);
        }
        int candidateIndex;
        scanf("%d", &candidateIndex);
        if (candidateIndex >= 1 && candidateIndex <= numCandidates) { // Validate input
            votes[candidateIndex-1]++;
            printf("Your vote has been recorded for %s\n", candidateList[candidateIndex-1]);
        } else {
            printf("Invalid input, please try again\n");
            i--;
        }
    }

    printf("Voting is now closed!\n");

    int maxVotes = -1;
    int winnerIndex = -1;
    int numWinners = 0;
    for (i = 0; i < numCandidates; i++) {
        printf("%s got %d votes\n", candidateList[i], votes[i]);
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
            numWinners = 1;
        } else if (votes[i] == maxVotes) {
            numWinners++;
        }
    }

    if (numWinners == 1) {
        printf("%s wins with %d votes!\n", candidateList[winnerIndex], maxVotes);
    } else {
        printf("There is a tie between the following candidates:\n");
        for (i = 0; i < numCandidates; i++) {
            if (votes[i] == maxVotes) {
                printf("%s\n", candidateList[i]);
            }
        }
    }

    // Free allocated memory
    for (i = 0; i < numCandidates; i++) {
        free(candidateList[i]);
    }
    free(candidateList);
    free(votes);

    return 0;
}