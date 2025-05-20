//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    int num_candidates, num_voters, i, j, vote;
    struct Candidate *candidates;
    char voter_name[50];

    printf("Welcome to the Electronic Voting System\n");

    // Get number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allocate memory for candidates
    candidates = (struct Candidate*) malloc(num_candidates * sizeof(struct Candidate));

    // Get candidate names
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to zero
    }

    // Get voter name and vote
    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voter_name);
        printf("Please vote for one of the following candidates:\n");
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        printf("Enter your vote: ");
        scanf("%d", &vote);

        // Update candidate vote count
        candidates[vote-1].votes++;
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Free memory
    free(candidates);

    return 0;
}