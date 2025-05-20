//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int candidate_index;
} Voter;

void read_candidates(Candidate* candidates, int num_candidates) {
    printf("Enter the names of the candidates (up to %d):\n", num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }
}

void read_voters(Voter* voters, int num_voters) {
    printf("Enter the names of the voters (up to %d):\n", num_voters);
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }
}

int main() {
    int num_candidates;
    printf("Enter the number of candidates (up to %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];
    read_candidates(candidates, num_candidates);

    int num_voters;
    printf("Enter the number of voters (up to %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    Voter voters[num_voters];
    read_voters(voters, num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s has voted for candidate %s.\n", voters[i].name, candidates[voters[i].candidate_index].name);
        candidates[voters[i].candidate_index].votes++;
    }

    printf("The winner is %s with %d votes!\n", candidates[0].name, candidates[0].votes);

    return 0;
}