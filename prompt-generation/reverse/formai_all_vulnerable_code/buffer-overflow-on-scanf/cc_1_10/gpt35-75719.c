//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to check if the entered candidate ID is valid
bool is_valid_candidate(int id, int num_candidates) {
    return (id >= 1 && id <= num_candidates);
}

int main() {

    int num_voters, num_candidates;

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Dynamic allocation of memory for vote count
    int* vote_count = (int*) calloc(num_candidates, sizeof(int));

    // Loop to take votes from each voter
    for(int i=0; i<num_voters; i++) {
        printf("\nVote for a candidate by entering their ID: ");

        int candidate_id;
        scanf("%d", &candidate_id);

        // Check if the entered candidate ID is valid
        if(is_valid_candidate(candidate_id, num_candidates)) {
            vote_count[candidate_id - 1]++;
        } else {
            printf("Invalid candidate ID. Please enter again.\n");
            i--;        // Decrement i to repeat the current iteration
        }
    }

    // Display the vote count for each candidate
    printf("\nVote Count:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("Candidate %d: %d votes\n", i+1, vote_count[i]);
    }

    // Find the candidate with the maximum vote count
    int max_vote = vote_count[0];
    int max_vote_index = 0;

    for(int i=1; i<num_candidates; i++) {
        if(vote_count[i] > max_vote) {
            max_vote = vote_count[i];
            max_vote_index = i;
        }
    }

    // Display the winner of the election
    printf("\nWinner of the election is Candidate %d with %d votes.\n", max_vote_index+1, max_vote);

    // Free the dynamically allocated memory for vote count
    free(vote_count);

    return 0;
}