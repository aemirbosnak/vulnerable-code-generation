//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTE_LENGTH 100

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote;
} Voter;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int voteCount;
} Candidate;

int main() {
    int numCandidates, numVoters;
    scanf("%d %d", &numCandidates, &numVoters);

    Candidate *candidates = (Candidate *)malloc(sizeof(Candidate) * numCandidates);
    Voter *voters = (Voter *)malloc(sizeof(Voter) * numVoters);

    for (int i = 0; i < numCandidates; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].voteCount = 0;
    }

    for (int i = 0; i < numVoters; i++) {
        scanf("%s", voters[i].name);
        scanf("%d", &voters[i].vote);
    }

    for (int i = 0; i < numVoters; i++) {
        int candidateIndex = 0;
        while (candidateIndex < numCandidates) {
            if (strcmp(voters[i].name, candidates[candidateIndex].name) == 0) {
                candidates[candidateIndex].voteCount++;
                break;
            }
            candidateIndex++;
        }
    }

    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].voteCount);
    }

    return 0;
}