//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == candidate) {
            candidates[i].votes++;
        }
    }
}

int main() {
    int i, vote_count, candidate_count = 0;

    // Create candidates
    candidates[0].name[0] = 'A';
    candidates[0].votes = 0;
    candidates[1].name[0] = 'B';
    candidates[1].votes = 0;
    candidates[2].name[0] = 'C';
    candidates[2].votes = 0;
    candidates[3].name[0] = 'D';
    candidates[3].votes = 0;
    candidates[4].name[0] = 'E';
    candidates[4].votes = 0;

    // Get the number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &vote_count);

    // Vote for a candidate
    for (i = 0; i < vote_count; i++) {
        printf("Enter the candidate's name: ");
        char candidate_name[50];
        scanf("%s", candidate_name);

        vote(candidate_name[0]);
    }

    // Print the results
    printf("\nThe results of the election:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    Candidate winner = candidates[0];
    for (i = 1; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    // Announce the winner
    printf("\nThe winner of the election is: %s.\n", winner.name);

    return 0;
}