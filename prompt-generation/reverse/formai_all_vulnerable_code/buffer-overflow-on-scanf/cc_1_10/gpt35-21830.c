//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int main() {
    int num_voters, num_candidates, i, j, k; 
    int votes[MAX_VOTERS][MAX_CANDIDATES];
    int winner = -1, max_votes = -1;
    bool has_winner = false;

    // Get input from user
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Initialize vote matrix
    for (i = 0; i < num_voters; i++) {
        printf("Enter the votes for voter %d:\n", i + 1);
        for (j = 0; j < num_candidates; j++) {
            printf("Candidate %d: ", j + 1);
            scanf("%d", &votes[i][j]);
        }
    }

    // Count votes
    for (i = 0; i < num_candidates; i++) {
        int count = 0;
        for (j = 0; j < num_voters; j++) {
            if (votes[j][i] == 1) {
                count++;
            }
        }
        if (count > max_votes) {
            max_votes = count;
            winner = i;
        }
    }

    // Check for winner
    if (max_votes > num_voters / 2) {
        has_winner = true;
        printf("Candidate %d is the winner!\n", winner + 1);
    } else {
        printf("No candidate has a majority.\n");
    }

    return 0;
}