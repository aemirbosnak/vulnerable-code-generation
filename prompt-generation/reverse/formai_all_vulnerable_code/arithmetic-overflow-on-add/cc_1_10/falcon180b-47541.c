//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTE_LENGTH 100

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} candidate;

typedef struct {
    int num_candidates;
    candidate candidates[MAX_CANDIDATES];
} ballot;

int main() {
    ballot ballot;
    int i, j, k;

    // Initialize ballot
    ballot.num_candidates = 0;

    // Add candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (i == 0) {
            strcpy(ballot.candidates[i].name, "Candidate 1");
        } else {
            sprintf(ballot.candidates[i].name, "Candidate %d", i + 1);
        }
        ballot.candidates[i].votes = 0;
    }

    // Add votes
    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Enter vote for voter %d:\n", i + 1);
        scanf("%s", ballot.candidates[0].name);
        for (j = 1; j < ballot.num_candidates; j++) {
            scanf("%s", ballot.candidates[j].name);
        }
        for (j = 0; j < ballot.num_candidates; j++) {
            ballot.candidates[j].votes++;
        }
    }

    // Print results
    printf("Election results:\n");
    for (i = 0; i < ballot.num_candidates; i++) {
        printf("%s: %d votes\n", ballot.candidates[i].name, ballot.candidates[i].votes);
    }

    return 0;
}