//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
// Shape-shifting Electronic Voting System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate names
char candidates[][50] = {
    "Alice",
    "Bob",
    "Carol",
    "Dave",
    "Eve"
};

// Number of candidates
int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

// Main function
int main() {
    // Initialize variables
    int votes[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        votes[i] = 0;
    }
    int numVoters;

    // Get number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    printf("\n");

    // Get votes
    for (int i = 0; i < numVoters; i++) {
        int index;
        printf("Vote for (0-%d): ", numCandidates - 1);
        scanf("%d", &index);
        printf("\n");
        if (index >= 0 && index < numCandidates) {
            votes[index]++;
        } else {
            printf("Invalid vote.\n");
        }
    }

    // Display results
    printf("Voting results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }
    printf("\n");

    // Find winner
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    // Display winner
    if (winnerIndex != -1) {
        printf("The winner is %s with %d votes.\n", candidates[winnerIndex], maxVotes);
    } else {
        printf("There was a tie.\n");
    }

    return 0;
}