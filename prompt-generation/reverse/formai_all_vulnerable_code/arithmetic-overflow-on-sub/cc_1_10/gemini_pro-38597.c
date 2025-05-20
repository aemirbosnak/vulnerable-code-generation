//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Main function
int main() {
    // Declare variables
    int num_candidates, num_voters;
    candidate *candidates;
    int *votes;

    // Get number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allocate memory for candidates and votes arrays
    candidates = (candidate *)malloc(num_candidates * sizeof(candidate));
    votes = (int *)malloc(num_candidates * sizeof(int));

    // Get candidate names
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        int candidate_index;
        printf("Enter the candidate number you want to vote for (1-%d): ", num_candidates);
        scanf("%d", &candidate_index);
        votes[candidate_index - 1]++;
    }

    // Find the winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner_index = i;
        }
    }

    // Print the winner
    printf("The winner is %s with %d votes.\n", candidates[winner_index].name, max_votes);

    // Free memory
    free(candidates);
    free(votes);

    return 0;
}