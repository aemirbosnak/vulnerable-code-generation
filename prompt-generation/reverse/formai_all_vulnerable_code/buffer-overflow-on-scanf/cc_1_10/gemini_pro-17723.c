//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    // Initialize the candidates
    Candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0}
    };

    // Get the number of voters
    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Get the votes
    for (int i = 0; i < numVoters; i++) {
        char vote[20];
        printf("Enter your vote: ");
        scanf("%s", vote);

        // Find the candidate with the matching name
        for (int j = 0; j < 3; j++) {
            if (strcmp(vote, candidates[j].name) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }

    // Find the winner
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winnerIndex].name);

    return 0;
}