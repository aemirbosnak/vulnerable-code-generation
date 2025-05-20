//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].id = num_candidates + 1;
    num_candidates++;
}

void add_voter(char* name) {
    strcpy(voters[num_voters].name, name);
    voters[num_voters].id = num_voters + 1;
    num_voters++;
}

int main() {
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    add_voter("Dave");
    add_voter("Eve");

    int i, j;
    for (i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("\n");

    for (i = 0; i < num_voters; i++) {
        printf("Voter %d: %s\n", i + 1, voters[i].name);
        printf("Vote for candidate: ");
        scanf("%d", &j);
        if (j >= 1 && j <= num_candidates) {
            printf("Vote cast for candidate %d: %s\n", j, candidates[j - 1].name);
        } else {
            printf("Invalid vote.\n");
        }
    }

    return 0;
}