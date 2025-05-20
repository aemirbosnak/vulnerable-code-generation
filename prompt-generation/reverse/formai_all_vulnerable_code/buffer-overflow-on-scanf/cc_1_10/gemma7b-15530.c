//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char *candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate) == 0) {
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

    printf("Enter the name of the voter: ");
    char voterName[20];
    scanf("%s", voterName);

    vote(voterName);

    int winnerVotes = candidates[0].votes;
    for (int i = 1; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winnerVotes) {
            winnerVotes = candidates[i].votes;
        }
    }

    printf("The winner is: %s", candidates[0].name);
    printf("\nThe total number of votes is: %d", winnerVotes);

    return 0;
}