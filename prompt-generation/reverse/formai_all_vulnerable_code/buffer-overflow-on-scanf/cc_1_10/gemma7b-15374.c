//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate) == 0) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    // Initialize candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get votes
    char vote_choice;
    printf("Please vote for a candidate: ");
    scanf("%c", &vote_choice);

    // Vote
    vote(vote_choice);

    // Print results
    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Winner
    Candidate winner = candidates[0];
    for (int i = 1; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    printf("The winner is: %s\n", winner.name);

    return 0;
}