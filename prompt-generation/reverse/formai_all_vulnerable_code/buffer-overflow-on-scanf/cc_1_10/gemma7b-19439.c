//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int candidate_index, int vote_count) {
    candidates[candidate_index].votes += vote_count;
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int i;

    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Register voters
    int num_voters = 10;
    for (i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", candidates[i].name);

        printf("Enter number of votes: ");
        scanf("%d", &candidates[i].votes);

        vote(candidates, i, candidates[i].votes);
    }

    // Print results
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Find winner
    int winner_index = -1;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > candidates[winner_index].votes) {
            winner_index = i;
        }
    }

    printf("The winner is: %s\n", candidates[winner_index].name);

    return 0;
}