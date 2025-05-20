//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CANDIDATES 4

typedef struct {
    int id;
    char name[101];
    int votes;
} Candidate;

Candidate candidates[CANDIDATES];

void vote(int candidateId) {
    if (candidateId < 0 || candidateId >= CANDIDATES) {
        printf("Invalid candidate ID\n");
    } else {
        candidates[candidateId].votes++;
    }
}

void printResults() {
    int winnerId = -1;
    int maxVotes = 0;
    for (int i = 0; i < CANDIDATES; i++) {
        if (candidates[i].votes > maxVotes) {
            winnerId = i;
            maxVotes = candidates[i].votes;
        }
    }
    if (winnerId == -1) {
        printf("No winner\n");
    } else {
        printf("The winner is %s with %d votes\n", candidates[winnerId].name, candidates[winnerId].votes);
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < CANDIDATES; i++) {
        candidates[i].id = i;
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) {
        int candidateId = rand() % CANDIDATES;
        vote(candidateId);
    }

    printResults();

    return 0;
}