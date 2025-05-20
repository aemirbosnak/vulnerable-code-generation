//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare candidates based on votes
int compare_candidates(const void *a, const void *b) {
    candidate *c1 = (candidate *)a;
    candidate *c2 = (candidate *)b;
    return c2->votes - c1->votes;
}

// Main function to conduct the election
int main() {
    // Initialize candidates
    candidate candidates[] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Bob Smith", 0},
        {"Alice Johnson", 0},
    };

    int num_candidates = sizeof(candidates) / sizeof(candidate);

    // Get number of voters
    int num_voters;
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    // Get votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Enter vote (0-%d): ", num_candidates - 1);
        scanf("%d", &vote);

        candidates[vote].votes++;
    }

    // Sort candidates based on votes
    qsort(candidates, num_candidates, sizeof(candidate), compare_candidates);

    // Print election results
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    if (candidates[0].votes == candidates[1].votes) {
        printf("Tie between %s and %s\n", candidates[0].name, candidates[1].name);
    } else {
        printf("Winner: %s with %d votes\n", candidates[0].name, candidates[0].votes);
    }

    return 0;
}