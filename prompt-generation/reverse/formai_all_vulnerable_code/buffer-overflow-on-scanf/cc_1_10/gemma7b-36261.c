//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int numCandidates) {
    char voteChoice;
    printf("Please enter your vote choice (a-e): ");
    scanf(" %c", &voteChoice);

    switch (voteChoice) {
        case 'a':
            candidates[0].votes++;
            break;
        case 'b':
            candidates[1].votes++;
            break;
        case 'c':
            candidates[2].votes++;
            break;
        case 'd':
            candidates[3].votes++;
            break;
        case 'e':
            candidates[4].votes++;
            break;
        default:
            printf("Invalid vote choice.\n");
            break;
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Bill Smith", 0},
        {"Mary Johnson", 0},
        {"Bob Green", 0}
    };

    int numCandidates = MAX_CANDIDATES;

    vote(candidates, numCandidates);

    printf("Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}