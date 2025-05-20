//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int votes;
} Candidate;

int main() {
    // Initialize the candidates
    Candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Dave", 0},
        {"Eve", 0},
    };

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the votes from each voter
    for (int i = 0; i < num_voters; i++) {
        // Get the voter's name
        char voter_name[32];
        printf("Enter your name: ");
        scanf("%s", voter_name);

        // Get the voter's vote
        char vote[32];
        printf("Enter your vote: ");
        scanf("%s", vote);

        // Find the candidate that the voter voted for
        int candidate_index = -1;
        for (int j = 0; j < 5; j++) {
            if (strcmp(candidates[j].name, vote) == 0) {
                candidate_index = j;
                break;
            }
        }

        // If the voter voted for a valid candidate, increment their vote count
        if (candidate_index != -1) {
            candidates[candidate_index].votes++;
        }
    }

    // Print the results of the election
    printf("The results of the election are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner of the election
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < 5; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print the winner of the election
    printf("The winner of the election is: %s\n", candidates[winner_index].name);

    return 0;
}