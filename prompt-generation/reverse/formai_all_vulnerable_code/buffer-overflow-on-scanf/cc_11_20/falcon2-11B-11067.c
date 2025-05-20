//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a list of candidates
    char* candidates[] = {"Candidate A", "Candidate B", "Candidate C"};
    int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

    // Getting the number of votes to cast
    int num_votes;
    printf("Enter the number of votes to cast: ");
    scanf("%d", &num_votes);

    // Creating a list of votes
    int votes[num_votes][num_candidates];
    for (int i = 0; i < num_votes; i++) {
        for (int j = 0; j < num_candidates; j++) {
            votes[i][j] = 0;
        }
    }

    // Casting votes
    printf("Enter your votes (separated by spaces): ");
    fgets(votes[0], num_candidates, stdin);
    for (int i = 0; i < num_votes; i++) {
        for (int j = 0; j < num_candidates; j++) {
            if (votes[i][j] == '\n') {
                votes[i][j] = 0;
            } else {
                printf("Invalid vote. Please enter a valid vote (separated by spaces): ");
                fgets(votes[i], num_candidates, stdin);
            }
        }
    }

    // Counting the votes
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += votes[0][i];
    }

    // Determining the winner
    int winner_index = 0;
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[0][i] > max_votes) {
            winner_index = i;
            max_votes = votes[0][i];
        }
    }

    // Printing the results
    printf("Total votes cast: %d\n", total_votes);
    printf("Winner: ");
    for (int i = 0; i < num_candidates; i++) {
        if (i == winner_index) {
            printf("%s ", candidates[i]);
        }
    }
    printf("\n");

    return 0;
}