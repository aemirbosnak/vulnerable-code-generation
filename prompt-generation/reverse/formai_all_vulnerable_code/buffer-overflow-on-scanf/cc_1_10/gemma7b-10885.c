//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == candidate) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0;
    }

    char voteChoice;
    printf("Enter the vote choice (e.g. a, b, c, ...): ");
    scanf("%c", &voteChoice);

    vote(voteChoice);

    int winnerIndex = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > candidates[winnerIndex].votes) {
            winnerIndex = i;
        }
    }

    printf("The winner is: %s", candidates[winnerIndex].name);

    return 0;
}