//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int num_candidates, votes[100];
    char candidate_names[100][100];

    // Prompt the user for the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Prompt the user for the candidate names
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name %d: ", i + 1);
        scanf("%s", candidate_names[i]);
    }

    // Prompt the user for the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_candidates);

    // Initialize the vote count for each candidate
    for (int i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }

    // Simulate the voting process
    for (int i = 0; i < num_candidates; i++) {
        printf("\nVotes for %s:\n", candidate_names[i]);
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j + 1, candidate_names[j]);
        }
        printf("%d. None of the above\n", num_candidates);
        printf("Enter your vote: ");
        scanf("%d", &votes[i]);
    }

    // Determine the winner
    int max_votes = 0;
    int winner = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = i;
        }
    }

    // Display the results
    printf("\nThe winner is %s with %d votes!\n", candidate_names[winner], max_votes);
}