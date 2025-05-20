//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
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
        {"Carol", 0},
    };

    // Get number of candidates
    int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

    // Initialize votes to 0
    int votes[num_candidates];
    for (int i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }

    // Get number of voters
    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    // Get votes from each voter
    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Enter vote for voter %d: ", i + 1);
        scanf("%d", &vote);

        // Increment vote count for selected candidate
        votes[vote - 1]++;
    }

    // Determine winner
    int winning_candidate = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (votes[i] > votes[winning_candidate]) {
            winning_candidate = i;
        }
    }

    // Print winner
    printf("The winner is: %s\n", candidates[winning_candidate].name);

    return 0;
}