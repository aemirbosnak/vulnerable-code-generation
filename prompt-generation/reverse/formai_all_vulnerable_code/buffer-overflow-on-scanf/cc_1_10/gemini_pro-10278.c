//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Candidate struct
typedef struct {
    char *name;
    int votes;
} Candidate;

// Main function
int main() {
    // Initialize candidates
    Candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0}
    };
    
    // Get number of voters
    int num_voters;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get votes
    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Enter your vote (1 for Alice, 2 for Bob, 3 for Charlie): ");
        scanf("%d", &vote);

        // Increment votes for the selected candidate
        candidates[vote - 1].votes++;
    }

    // Display results
    printf("Election Results:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < 3; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Display the winner
    printf("The winner is: %s!\n", candidates[winner_index].name);
    
    return 0;
}