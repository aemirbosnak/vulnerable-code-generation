//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(Candidate *candidate) {
    candidate->votes++;
}

int main() {
    int i, j, votes, candidate_num;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Get number of votes
    printf("Enter the number of votes: ");
    scanf("%d", &votes);

    // Vote for a candidate
    for (i = 0; i < votes; i++) {
        printf("Enter the candidate number: ");
        scanf("%d", &candidate_num);

        // Validate candidate number
        if (candidate_num < 1 || candidate_num > MAX_CANDIDATES) {
            printf("Invalid candidate number.\n");
            continue;
        }

        // Vote for the candidate
        vote(&candidates[candidate_num - 1]);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    Candidate winner = candidates[0];
    for (i = 1; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    // Print the winner
    printf("The winner is: %s\n", winner.name);

    return 0;
}