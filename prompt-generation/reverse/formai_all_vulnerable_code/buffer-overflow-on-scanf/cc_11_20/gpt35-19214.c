//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main() {
    int numVoters, numCandidates, i, j, k, vote;
    int candidateTally[MAX_CANDIDATES] = {0};
    int voterList[MAX_VOTERS][MAX_CANDIDATES];

    printf("Welcome to the Electronic Voting System\n");

    // Inputting the number of voters and candidates
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Inputting the preferences of each voter
    for (i = 0; i < numVoters; i++) {
        printf("\nVoter %d\n", i+1);

        for (j = 0; j < numCandidates; j++) {
            printf("Enter the preference for candidate %d (1-%d): ", j+1, numCandidates);
            scanf("%d", &vote);

            if (vote < 1 || vote > numCandidates) {
                printf("Invalid preference value. Please enter a valid preference (1-%d): ", numCandidates);
                scanf("%d", &vote);
            }

            voterList[i][j] = vote;
        }
    }

    // Tallying the votes
    for (i = 0; i < numVoters; i++) {
        for (j = 0; j < numCandidates; j++) {
            int candidateIndex = voterList[i][j] - 1;

            if (candidateTally[candidateIndex] == -1) {
                continue;
            } else {
                candidateTally[candidateIndex]++;
                break;
            }
        }
    }

    // Finding the winner
    int winnerIndex = -1;

    for (i = 0; i < numCandidates; i++) {
        int maxVotes = -1;

        for (j = 0; j < numCandidates; j++) {
            if (candidateTally[j] == -1) {
                continue;
            }

            if (candidateTally[j] > maxVotes) {
                maxVotes = candidateTally[j];
                winnerIndex = j;
            }
        }

        if (maxVotes > (numVoters/2)) {
            break;
        } else {
            candidateTally[winnerIndex] = -1;
        }
    }

    // Outputting the winner
    printf("\nThe winner is candidate %d!", winnerIndex+1);

    return 0;
}