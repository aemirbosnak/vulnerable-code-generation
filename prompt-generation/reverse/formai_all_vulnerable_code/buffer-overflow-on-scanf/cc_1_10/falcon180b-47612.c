//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates, numVoters, i, j, choice, candidateId;
    char name[MAX_NAME_LENGTH];

    // Initialize candidates
    numCandidates = 0;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    for (i = 0; i < numCandidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Initialize voters
    numVoters = 0;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);
    for (i = 0; i < numVoters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        voters[i].id = i + 1;
    }

    // Vote
    printf("Voting begins...\n");
    for (i = 0; i < numVoters; i++) {
        printf("Voter %d is voting...\n", voters[i].id);
        for (j = 0; j < numCandidates; j++) {
            printf("Candidate %d: %s\n", j + 1, candidates[j].name);
        }
        printf("Enter candidate ID: ");
        scanf("%d", &candidateId);
        if (candidateId >= 1 && candidateId <= numCandidates) {
            candidates[candidateId - 1].votes++;
        } else {
            printf("Invalid candidate ID.\n");
        }
    }

    // Display results
    printf("\nElection results:\n");
    for (i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}