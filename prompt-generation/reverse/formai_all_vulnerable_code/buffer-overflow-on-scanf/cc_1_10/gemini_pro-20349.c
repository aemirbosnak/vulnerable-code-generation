//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
    int votes;
} Candidate;

Candidate candidates[] = {
    {1, "John Smith", 0},
    {2, "Jane Doe", 0},
    {3, "Bob Jones", 0},
};

int numCandidates = sizeof(candidates) / sizeof(Candidate);

int main() {
    int votes[numCandidates];
    int totalVotes = 0;

    printf("Welcome to the Electronic Voting System!\n");
    printf("----------------------------------------\n");
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    printf("\nPlease cast your votes:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: ", candidates[i].id);
        scanf("%d", &votes[i]);
        totalVotes += votes[i];
    }

    printf("\nResults:\n");
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = votes[i];
        printf("%d. %s: %d votes (%.2f%%)\n", candidates[i].id, candidates[i].name, votes[i], (float)votes[i] / totalVotes * 100);
    }

    // Find the winner
    int maxVotes = 0;
    Candidate *winner = NULL;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winner = &candidates[i];
        }
    }

    printf("\nThe winner is: %s (%d votes)\n", winner->name, winner->votes);

    return 0;
}