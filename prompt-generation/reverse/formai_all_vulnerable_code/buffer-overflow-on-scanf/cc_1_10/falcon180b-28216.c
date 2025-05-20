//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 500
#define MAX_VOTE_LENGTH 20

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote;
} Voter;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} Candidate;

void read_candidates(Candidate candidates[]) {
    int i = 0;
    while (i < MAX_CANDIDATES && scanf("%s %d", candidates[i].name, &candidates[i].votes) == 2) {
        i++;
    }
}

void read_voters(Voter voters[]) {
    int i = 0;
    while (i < MAX_VOTERS && scanf("%s %d", voters[i].name, &voters[i].vote) == 2) {
        i++;
    }
}

int count_votes(Candidate candidates[], Voter voters[], int num_voters) {
    int i, j;
    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < MAX_CANDIDATES; j++) {
            if (strcmp(candidates[j].name, voters[i].name) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }
    return 0;
}

void print_results(Candidate candidates[], int num_candidates) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates, num_voters;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    read_candidates(candidates);

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    read_voters(voters);

    count_votes(candidates, voters, num_voters);

    printf("\nElection results:\n");
    print_results(candidates, num_candidates);

    return 0;
}