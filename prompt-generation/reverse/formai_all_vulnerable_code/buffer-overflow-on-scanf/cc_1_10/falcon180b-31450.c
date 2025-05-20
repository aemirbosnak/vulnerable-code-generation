//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int voter_id;
    int candidate_id;
} Vote;

void create_candidates(Candidate candidates[MAX_CANDIDATES]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void create_voters(Vote voters[MAX_VOTERS]) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Enter the voter ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].voter_id);
        printf("Enter the candidate ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].candidate_id);
    }
}

void count_votes(Candidate candidates[MAX_CANDIDATES], Vote voters[MAX_VOTERS]) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        candidates[voters[i].candidate_id - 1].votes++;
    }
}

void display_results(Candidate candidates[MAX_CANDIDATES]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Vote voters[MAX_VOTERS];

    create_candidates(candidates);
    create_voters(voters);
    count_votes(candidates, voters);
    display_results(candidates);

    return 0;
}