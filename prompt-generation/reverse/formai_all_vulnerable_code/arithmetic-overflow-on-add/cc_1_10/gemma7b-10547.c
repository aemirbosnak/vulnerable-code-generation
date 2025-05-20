//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(Candidate *candidate) {
    candidate->votes++;
}

int main() {
    int i, vote_count, candidate_count = 0;
    char vote;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get candidate information
    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    for (i = 0; i < candidate_count; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    // Get votes
    printf("Enter your vote: ");
    scanf("%c", &vote);

    // Validate vote
    if (vote < 'a' || vote > 'a' + candidate_count) {
        printf("Invalid vote.\n");
    } else {
        vote_count = candidates[vote - 'a'].votes;
        vote_count++;
        candidates[vote - 'a'].votes = vote_count;

        // Print results
        printf("Results:\n");
        for (i = 0; i < candidate_count; i++) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }

        // Print winner
        printf("Winner: %s\n", candidates[0].name);
    }

    return 0;
}