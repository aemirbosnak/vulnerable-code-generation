//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 5

typedef struct {
    char name[50];
    int votes[MAX_VOTES_PER_VOTER];
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

void read_candidates(Candidate* candidates, int num_candidates) {
    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
    }
}

void read_voters(Voter* voters, int num_voters) {
    printf("Enter the names of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    read_candidates(candidates, num_candidates);

    Voter voters[MAX_VOTERS];
    read_voters(voters, num_voters);

    int num_votes = 0;
    for (int i = 0; i < num_voters; i++) {
        printf("\nEnter the votes for %s:\n", voters[i].name);
        for (int j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            scanf("%d", &voters[i].votes[j]);
            num_votes++;
        }
    }

    int winner_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        int candidate_votes = 0;
        for (int j = 0; j < num_votes; j++) {
            if (voters[j].votes[j] == i) {
                candidate_votes++;
            }
        }
        if (candidate_votes > winner_votes) {
            winner_votes = candidate_votes;
        }
    }

    printf("\nThe winner of the election is %s with %d votes!\n", candidates[winner_votes - 1].name, winner_votes);

    return 0;
}