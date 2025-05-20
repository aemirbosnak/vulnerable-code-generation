//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>

// Define a struct for each candidate
typedef struct candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];

    // Get candidate information from the user
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].id = i+1;
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get votes from each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, enter your vote (enter the candidate ID): ", i+1);
        int candidate_id;
        scanf("%d", &candidate_id);

        // Increment vote for the selected candidate
        for (int j = 0; j < num_candidates; j++) {
            if (candidates[j].id == candidate_id) {
                candidates[j].votes++;
            }
        }
    }

    // Print the results
    printf("\nElection Results\n");
    printf("----------------\n");
    printf("Candidate\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }

    // Calculate the winner
    int max_votes = 0;
    int winner_index = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("\nWinner: %s\n", candidates[winner_index].name);

    return 0;
}