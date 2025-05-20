//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int i;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Get votes
    printf("Enter vote choice (e.g. a, b, c): ");
    scanf(" %c", &vote_choice);

    // Validate vote
    if (vote_choice >= 'a' && vote_choice <= 'a' + MAX_CANDIDATES - 1) {
        vote(vote_choice);
    } else {
        printf("Invalid vote choice.\n");
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}