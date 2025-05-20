//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    int voter_id;
    int voted;
};

void init_candidates(struct candidate candidates[MAX_CANDIDATES]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }
}

void init_voters(struct voter voters[MAX_VOTERS]) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        voters[i].voter_id = i + 1;
        voters[i].voted = 0;
    }
}

void print_candidates(struct candidate candidates[MAX_CANDIDATES]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    init_candidates(candidates);

    struct voter voters[MAX_VOTERS];
    init_voters(voters);

    int num_candidates, num_voters;
    scanf("%d %d", &num_candidates, &num_voters);

    int i, j;
    for (i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }

    for (i = 0; i < num_voters; i++) {
        int candidate_id;
        scanf("%d", &candidate_id);
        candidates[candidate_id - 1].votes++;
        voters[i].voted = 1;
    }

    print_candidates(candidates);

    return 0;
}