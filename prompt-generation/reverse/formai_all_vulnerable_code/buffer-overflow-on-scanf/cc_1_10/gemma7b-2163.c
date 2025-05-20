//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

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
    int i, num_votes, candidate_choice;
    char candidate_name[20];

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Get number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);

    // Vote for candidate
    for (i = 0; i < num_votes; i++) {
        printf("Enter the candidate's name: ");
        scanf("%s", candidate_name);

        vote(candidate_name);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find winner
    Candidate winner = candidates[0];
    for (i = 1; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    // Announce winner
    printf("The winner is: %s\n", winner.name);

    return 0;
}