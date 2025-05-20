//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int vote;
} candidate;

int main() {
    int num_candidates, num_voters, i, j;
    candidate candidates[100];
    int votes[100];

    // Read the number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Read the candidate names
    printf("Enter the candidate names:\n");
    for (i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i].name);
        candidates[i].vote = 0;
    }

    // Read the votes
    printf("Enter the votes:\n");
    for (i = 0; i < num_voters; i++) {
        scanf("%d", &votes[i]);
    }

    // Count the votes
    for (i = 0; i < num_voters; i++) {
        candidates[votes[i] - 1].vote++;
    }

    // Find the winner
    int max_votes = 0;
    int winner = -1;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].vote > max_votes) {
            max_votes = candidates[i].vote;
            winner = i;
        }
    }

    // Print the winner
    if (winner == -1) {
        printf("There is no winner.\n");
    } else {
        printf("The winner is %s with %d votes.\n", candidates[winner].name, candidates[winner].vote);
    }

    return 0;
}