//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voterID;
} Voter;

void readCandidates(Candidate candidates[], int numCandidates) {
    printf("Enter the names of the candidates, one at a time:\n");
    for (int i = 0; i < numCandidates; i++) {
        scanf("%s", candidates[i].name);
    }
}

void readVoters(Voter voters[], int numVoters) {
    printf("Enter the names of the voters, one at a time:\n");
    for (int i = 0; i < numVoters; i++) {
        scanf("%s %d", voters[i].name, &voters[i].voterID);
    }
}

int main() {
    int numCandidates, numVoters;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    Candidate candidates[MAX_CANDIDATES];
    readCandidates(candidates, numCandidates);

    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    Voter voters[MAX_VOTERS];
    readVoters(voters, numVoters);

    int votes[MAX_CANDIDATES];
    for (int i = 0; i < numCandidates; i++) {
        for (int j = 0; j < numVoters; j++) {
            if (strcmp(voters[j].name, candidates[i].name) == 0) {
                votes[i]++;
            }
        }
    }

    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, votes[i]);
    }

    return 0;
}