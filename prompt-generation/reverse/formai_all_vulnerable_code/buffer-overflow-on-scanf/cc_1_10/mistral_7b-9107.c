//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
int voters[MAX_VOTERS][2]; // [voter_id, candidate_id]
int num_voters = 0;

void register_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int voter_id, int candidate_id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    voters[num_voters][0] = voter_id;
    voters[num_voters][1] = candidate_id;
    num_voters++;

    candidates[candidate_id].votes++;
}

void print_results() {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void recursive_vote(int voter_id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        print_results();
        return;
    }

    printf("Voter %d is voting...\n", voter_id);
    int candidate_id;
    scanf("%d", &candidate_id);

    vote(voter_id, candidate_id);

    recursive_vote(voter_id + 1);
}

int main() {
    char candidate_name[50];

    printf("Registering candidates...\n");
    scanf("%s", candidate_name);
    while (strcmp(candidate_name, "END") != 0) {
        register_candidate(candidate_name);
        scanf("%s", candidate_name);
    }

    printf("Voting process...\n");
    recursive_vote(1);

    print_results();

    return 0;
}