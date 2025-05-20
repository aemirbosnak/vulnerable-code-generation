//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 10

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[50];
    int vote[MAX_CANDIDATES];
} Voter;

void read_candidates(Candidate* candidates) {
    int i, j;
    char name[50];

    printf("Enter the number of candidates: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        printf("Enter the name of candidate %d: ", j + 1);
        scanf("%s", name);

        strcpy(candidates[j].name, name);
    }
}

void read_voters(Voter* voters) {
    int i, j;
    char name[50];

    printf("Enter the number of voters: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        printf("Enter the name of voter %d: ", j + 1);
        scanf("%s", name);

        strcpy(voters[j].name, name);
    }
}

void vote(Voter* voter, Candidate* candidates) {
    int i, choice;

    printf("Voter: %s\n", voter->name);

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %s\n", i + 1, candidates[i].name);
    }

    printf("Enter your choices (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &choice);

    voter->vote[choice - 1] = 1;
}

void count_votes(Voter* voters, Candidate* candidates) {
    int i, j, k;

    for (i = 0; i < MAX_VOTERS; i++) {
        for (j = 0; j < MAX_CANDIDATES; j++) {
            if (voters[i].vote[j]) {
                candidates[j].votes[i]++;
            }
        }
    }
}

void print_results(Candidate* candidates) {
    int i, j;

    printf("\nResults:\n");

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %s\n", i + 1, candidates[i].name);

        for (j = 0; j < MAX_VOTERS; j++) {
            printf("Voter %d: %d\n", j + 1, candidates[i].votes[j]);
        }
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    read_candidates(candidates);
    read_voters(voters);

    int i;

    for (i = 0; i < MAX_VOTERS; i++) {
        vote(voters + i, candidates);
    }

    count_votes(voters, candidates);
    print_results(candidates);

    return 0;
}