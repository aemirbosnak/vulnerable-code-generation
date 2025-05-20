//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 1

typedef struct {
    char name[50];
    int votes;
} candidate_t;

typedef struct {
    int num_candidates;
    candidate_t candidates[MAX_CANDIDATES];
} ballot_t;

void print_candidate(candidate_t c) {
    printf("%s: %d votes\n", c.name, c.votes);
}

void print_ballot(ballot_t b) {
    printf("Ballot:\n");
    for (int i = 0; i < b.num_candidates; i++) {
        print_candidate(b.candidates[i]);
    }
}

int main() {
    // Initialize candidates
    candidate_t candidates[MAX_CANDIDATES];
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        strcpy(candidates[i].name, "Candidate ");
        candidates[i].name[strlen(candidates[i].name) - 1] = 'A' + i;
        candidates[i].votes = 0;
    }

    // Add some votes
    ballot_t ballot;
    ballot.num_candidates = MAX_CANDIDATES;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        ballot.candidates[i].votes++;
    }

    // Print the results
    print_ballot(ballot);

    return 0;
}