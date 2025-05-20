//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_candidates = 3;
    int num_voters = 10;
    int votes[num_voters][num_candidates];

    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            votes[i][j] = 0;
        }
    }

    int total_votes = num_voters;

    while (total_votes > 0) {
        int voter_id;
        scanf("%d", &voter_id);

        for (int j = 0; j < num_candidates; j++) {
            printf("Enter your vote for candidate %d: ", j + 1);
            int vote;
            scanf("%d", &vote);

            if (vote < num_candidates && vote >= 0) {
                votes[voter_id - 1][vote]++;
                total_votes--;
            } else {
                printf("Invalid vote. Please try again.\n");
                total_votes--;
            }
        }
    }

    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_candidates; j++) {
            if (votes[i][j] > votes[i][j + 1]) {
                int temp = votes[i][j];
                votes[i][j] = votes[i][j + 1];
                votes[i][j + 1] = temp;
            }
        }
    }

    int winner_id = 0;
    int max_votes = votes[0][0];
    for (int i = 1; i < num_candidates; i++) {
        if (votes[i][0] > max_votes) {
            max_votes = votes[i][0];
            winner_id = i;
        }
    }

    printf("Election Results:\n");
    printf("-------------------\n");
    printf("Total Voters: %d\n", total_votes);
    printf("-------------------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: %d votes (%3.2f%%)\n", i + 1, votes[i][0], 100.0 * votes[i][0] / total_votes);
    }
    printf("-------------------\n");
    printf("Winner: Candidate %d\n", winner_id + 1);

    return 0;
}