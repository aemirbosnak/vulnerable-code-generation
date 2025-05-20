//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

void init_candidates() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", i + 1);
    }
}

void print_candidates() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void vote(int candidate_index) {
    candidates[candidate_index - 1].votes++;
}

int main() {
    srand(time(NULL));
    init_candidates();

    int num_voters = rand() % MAX_VOTERS + 1;
    printf("Number of voters: %d\n", num_voters);

    int i;
    for (i = 0; i < num_voters; i++) {
        int candidate_index = rand() % MAX_CANDIDATES;
        vote(candidate_index);
        printf("Voter %d voted for %s\n", i + 1, candidates[candidate_index - 1].name);
    }

    print_candidates();

    return 0;
}