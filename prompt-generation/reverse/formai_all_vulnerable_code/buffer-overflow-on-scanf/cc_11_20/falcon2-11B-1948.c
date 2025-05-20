//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 5
#define MAX_CANDIDATES 3

int main() {
    char voterName[20];
    char candidateName[20];
    int candidateChoice;

    printf("Welcome to the Electronic Voting System!\n");

    int voters[MAX_VOTERS];
    int numVoters = 0;

    int candidates[MAX_CANDIDATES];
    int numCandidates = 0;

    int maxCandidateIndex = -1;
    int maxVotes = 0;

    // Loop until all voters have voted
    while (numVoters < MAX_VOTERS) {
        printf("Please enter your name: ");
        scanf("%s", voterName);

        printf("Please choose a candidate:\n");
        for (int i = 0; i < numCandidates; i++) {
            printf("%d) %s\n", i + 1, candidates[i]);
        }
        printf("Enter your choice (1-3): ");
        scanf("%d", &candidateChoice);

        if (candidateChoice > -1 && candidateChoice <= numCandidates) {
            voters[numVoters] = candidateChoice;
            numVoters++;
        }
    }

    for (int i = 0; i < numVoters; i++) {
        int winnerIndex = -1;
        int maxVotes = 0;

        for (int j = 0; j < numCandidates; j++) {
            if (candidates[j] == voters[i]) {
                if (candidates[j] > winnerIndex) {
                    winnerIndex = j;
                }
            }
        }

        if (winnerIndex == -1) {
            printf("Tie!\n");
        } else {
            printf("The winner is %s with %d votes.\n", candidates[winnerIndex], voters[i]);
        }

        if (voters[i] > maxVotes) {
            maxVotes = voters[i];
            maxCandidateIndex = winnerIndex;
        }
    }

    printf("The election results are:\n");
    printf("-------------------------\n");
    printf("| Candidate | Votes |\n");
    printf("-------------------------\n");

    for (int i = 0; i < numCandidates; i++) {
        printf("| %s | %d |\n", candidates[i], candidates[i]);
    }

    printf("-------------------------\n");
    printf("| Max Votes | Max Candidate |\n");
    printf("-------------------------\n");

    printf("| %d | %d |\n", maxVotes, maxCandidateIndex);

    printf("-------------------------\n");

    return 0;
}