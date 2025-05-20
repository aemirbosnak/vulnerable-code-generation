//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct Candidate {
    char* name;
    int votes;
};

int main() {
    // Initialize the voting system
    struct Candidate candidates[5] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"David", 0},
        {"Eve", 0}
    };
    int numCandidates = sizeof(candidates) / sizeof(struct Candidate);

    // Welcome the user
    printf("Welcome to the Virtual Voting System!\n");
    printf("---------------------------------------\n");

    // Start the voting loop
    while (1) {
        // Display the candidate list
        printf("\nCandidates:\n");
        for (int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }

        // Get the user's vote
        int vote;
        printf("\nPlease enter the number of the candidate you wish to vote for (or 0 to exit): ");
        scanf("%d", &vote);

        // Check if the user entered a valid vote
        if (vote < 0 || vote > numCandidates) {
            printf("Invalid vote. Please enter a valid number (1-%d).\n", numCandidates);
            continue;
        }

        // If the user voted, increment the corresponding candidate's vote count
        if (vote > 0) {
            candidates[vote - 1].votes++;
            printf("Vote successfully cast for %s!\n", candidates[vote - 1].name);
        }

        // Check if the user exited the voting system
        if (vote == 0) {
            break;
        }
    }

    // Display the election results
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    // Announce the winner
    if (winnerIndex >= 0) {
        printf("\nCongratulations to the winner: %s!\n", candidates[winnerIndex].name);
    } else {
        printf("\nThere was no clear winner. Please rerun the election.\n");
    }

    return 0;
}