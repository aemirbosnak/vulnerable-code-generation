//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 10
#define MAX_VOTE_LENGTH 50

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote_count;
} Candidate;

void init_candidates(Candidate* candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        strcpy(candidates[i].name, "");
        candidates[i].vote_count = 0;
    }
}

void init_voters(Voter* voters, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            voters[i].votes[j] = 0;
        }
    }
}

int compare_candidates(const void* a, const void* b) {
    Candidate* c1 = (Candidate*)a;
    Candidate* c2 = (Candidate*)b;
    if (c1->vote_count > c2->vote_count) {
        return -1;
    } else if (c1->vote_count < c2->vote_count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_candidates, num_voters;
    scanf("%d %d", &num_candidates, &num_voters);

    Candidate* candidates = (Candidate*)malloc(num_candidates * sizeof(Candidate));
    init_candidates(candidates, num_candidates);

    Voter* voters = (Voter*)malloc(num_voters * sizeof(Voter));
    init_voters(voters, num_voters);

    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            scanf("%d", &voters[i].votes[j]);
        }
    }

    qsort(candidates, num_candidates, sizeof(Candidate), compare_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("%s %d\n", candidates[i].name, candidates[i].vote_count);
    }

    return 0;
}