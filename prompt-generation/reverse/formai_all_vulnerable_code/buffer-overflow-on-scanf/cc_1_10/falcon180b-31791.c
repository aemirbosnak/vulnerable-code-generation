//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 1

typedef struct {
    char name[50];
    int votes[MAX_VOTES_PER_VOTER];
} Candidate;

typedef struct {
    char name[50];
    int vote;
} Voter;

void print_candidates(Candidate candidates[], int num_candidates) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes[0]);
    }
}

void print_voters(Voter voters[], int num_voters) {
    int i;
    for (i = 0; i < num_voters; i++) {
        printf("%s voted for %s\n", voters[i].name, voters[i].vote + 1);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    char name[50];

    printf("Enter the names of the candidates (up to %d):\n", MAX_CANDIDATES - 1);
    while (scanf("%s", name)!= EOF) {
        strcpy(candidates[num_candidates].name, name);
        num_candidates++;
    }

    Voter voters[MAX_VOTERS];
    int num_voters = 0;
    char voter_name[50];

    printf("Enter the names of the voters (up to %d):\n", MAX_VOTERS - 1);
    while (scanf("%s", voter_name)!= EOF) {
        strcpy(voters[num_voters].name, voter_name);
        num_voters++;
    }

    printf("Enter the votes for each candidate (up to %d):\n", MAX_VOTES_PER_VOTER - 1);
    int i, j;
    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            scanf("%d", &voters[i].vote);
            candidates[voters[i].vote].votes[0]++;
        }
    }

    print_candidates(candidates, num_candidates);
    print_voters(voters, num_voters);

    return 0;
}