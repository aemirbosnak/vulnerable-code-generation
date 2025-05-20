//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000 // Maximum number of voters
#define MAX_CANDIDATES 10 // Maximum number of candidates

// Function to count the total votes for each candidate
void count_votes(int votes[], int candidate[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        votes[candidate[i]]++;
    }
}

int main() {
    int num_voters, num_candidates;
    int candidate[MAX_VOTERS];
    int votes[MAX_CANDIDATES] = {0};

    // Get the number of voters and candidates from the user
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Get the candidate numbers for each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the candidate number for voter %d (1-%d): ", i+1, num_candidates);
        scanf("%d", &candidate[i]);
        // Validate the candidate number
        if (candidate[i] < 1 || candidate[i] > num_candidates) {
            printf("Invalid candidate number. Please try again.\n");
            i--; // Decrement i so that the same voter can try again
        }
    }

    // Count the total votes for each candidate
    count_votes(votes, candidate, num_voters);

    // Display the results
    printf("Candidate\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d\t\t%d\n", i+1, votes[i]);
    }

    // Determine the winner
    int max_votes = 0, winner = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = i+1;
        }
    }
    printf("The winner is candidate %d with %d votes.\n", winner, max_votes);

    return 0;
}