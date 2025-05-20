//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define VOTE_LENGTH 10

typedef struct {
    char name[VOTE_LENGTH];
    int vote[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[VOTE_LENGTH];
    int votes;
} Candidate;

void read_candidates(Candidate* candidates, int num_candidates) {
    printf("Enter the names of the candidates (up to %d):\n", num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        scanf(" %s", candidates[i].name);
    }
}

void read_voters(Voter* voters, int num_voters) {
    printf("Enter the names of the voters (up to %d):\n", num_voters);
    for (int i = 0; i < num_voters; i++) {
        scanf(" %s", voters[i].name);
    }
}

void read_votes(Voter* voters, int num_voters) {
    printf("Enter the votes for each candidate (up to %d):\n", num_voters);
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            scanf(" %d", &voters[i].vote[j]);
        }
    }
}

void count_votes(Candidate* candidates, Voter* voters, int num_candidates, int num_voters) {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            if (voters[i].vote[j] == 1) {
                candidates[j].votes++;
            }
        }
    }
}

void print_results(Candidate* candidates, int num_candidates) {
    printf("The results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates:");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters:");
    scanf("%d", &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    read_candidates(candidates, num_candidates);
    read_voters(voters, num_voters);
    read_votes(voters, num_voters);

    count_votes(candidates, voters, num_candidates, num_voters);
    print_results(candidates, num_candidates);

    return 0;
}