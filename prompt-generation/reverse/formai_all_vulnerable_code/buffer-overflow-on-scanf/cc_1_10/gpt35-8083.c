//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

int main() {
    int numVoters, numCandidates;
    int votes[MAX_VOTERS][MAX_CANDIDATES];
    int candidateTotals[MAX_CANDIDATES] = {0};

    printf("Welcome to the Electronic Voting System!\n");
    printf("How many voters are there? (max: %d)\n", MAX_VOTERS);
    scanf("%d", &numVoters);

    printf("How many candidates are there? (max: %d)\n", MAX_CANDIDATES);
    scanf("%d", &numCandidates);

    printf("Enter vote for each voter (by candidate index, starting from 0):\n");
    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d: ", i+1);
        for (int j = 0; j < numCandidates; j++) {
            scanf("%d", &votes[i][j]);
        }
    }

    bool tie = false;
    int maxVotes = 0;
    int winnerIndex = 0;

    for (int j = 0; j < numCandidates; j++) {
        for (int i = 0; i < numVoters; i++) {
            if (votes[i][j] == 1) {
                candidateTotals[j]++;
            }
        }
    }

    printf("Results:\n");
    for (int j = 0; j < numCandidates; j++) {
        printf("Candidate %d: %d votes\n", j+1, candidateTotals[j]);
        if (candidateTotals[j] > maxVotes) {
            maxVotes = candidateTotals[j];
            winnerIndex = j;
            tie = false;
        } else if (candidateTotals[j] == maxVotes) {
            tie = true;
        }
    }

    if (!tie) {
        printf("Candidate %d is the winner!\n", winnerIndex+1);
    } else {
        printf("The election resulted in a tie!\n");
    }

    return 0;
}