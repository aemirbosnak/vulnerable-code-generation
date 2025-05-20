//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void initializeCandidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }
}

void addVote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate) == 0) {
            candidates[i].votes++;
            return;
        }
    }

    // Candidate not found, error
    printf("Error: Invalid candidate name.\n");
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int winner = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (winner == -1 || candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }

    printf("Winner: %s\n", candidates[winner].name);
}

int main() {
    initializeCandidates();

    // Voting phase
    printf("Enter candidate name: ");
    char candidateName[20];
    scanf("%s", candidateName);
    addVote(candidateName);

    // Repeat for other voters
    printf("Enter candidate name: ");
    scanf("%s", candidateName);
    addVote(candidateName);

    // Results phase
    displayResults();

    return 0;
}