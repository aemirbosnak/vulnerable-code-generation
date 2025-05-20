//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Alan Touring
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CANDIDATES_NUM 5   // Number of candidates in the election
#define VOTER_NUM 100      // Number of voters

// The candidate structure
typedef struct {
    int id;
    char name[50];
    int votes;
} candidate_t;

int main() {
    candidate_t candidates[CANDIDATES_NUM];  // Declare an array of candidates
    int i, j;

    // Initialize the candidates
    for (i = 0; i < CANDIDATES_NUM; i++) {
        candidates[i].id = i + 1;
        printf("Enter Candidate %d Name: ", candidates[i].id);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Simulate the voting process
    for (i = 0; i < VOTER_NUM; i++) {
        int vote;
        printf("\nVoter %d:\n", i + 1);
        printf("Enter your choice (1-%d): ", CANDIDATES_NUM);
        scanf("%d", &vote);

        // Validate the vote
        if (vote < 1 || vote > CANDIDATES_NUM) {
            printf("Invalid choice. Please try again.\n");
            i--;
            continue;
        }

        // Increment the candidate's vote count
        candidates[vote - 1].votes++;
    }

    // Display the election results
    printf("\nElection Results:\n");
    printf("===================\n");
    for (i = 0; i < CANDIDATES_NUM; i++) {
        printf("%d. %s: %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    int winner_index = 0;
    for (i = 1; i < CANDIDATES_NUM; i++) {
        if (candidates[i].votes > candidates[winner_index].votes) {
            winner_index = i;
        }
    }

    // Display the winner
    printf("\nThe winner is: %s with %d votes!\n", candidates[winner_index].name, candidates[winner_index].votes);

    return 0;
}