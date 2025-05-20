//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char *name;
    int votes;
} candidate;

int main() {
    // Initialize the list of candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0}
    };
    int num_candidates = sizeof(candidates) / sizeof(candidate);

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes from each voter
    for (int i = 0; i < num_voters; i++) {
        // Get the voter's name
        char name[100];
        printf("Enter your name: ");
        scanf("%s", name);

        // Get the voter's vote
        int vote;
        printf("Enter your vote (0 for Alice, 1 for Bob, 2 for Carol): ");
        scanf("%d", &vote);

        // Increment the vote count for the corresponding candidate
        candidates[vote].votes++;
    }

    // Find the winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print the winner
    printf("The winner is %s with %d votes.\n", candidates[winner_index].name, max_votes);

    return 0;
}