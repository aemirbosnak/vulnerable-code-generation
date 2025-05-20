//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int vote_count;
} candidate_t;

int main() {
    int num_voters, num_candidates;
    int votes[MAX_VOTERS][MAX_CANDIDATES] = {0};
    candidate_t candidates[MAX_CANDIDATES];
    
    // Get input from user
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    // Get candidate names from user
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }
    
    // Get votes from users
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, enter your votes (candidate numbers separated by spaces): ", i + 1);
        
        // Get votes and record them in the array
        for (int j = 0; j < num_candidates; j++) {
            int candidate_num;
            scanf("%d", &candidate_num);
            votes[i][j] = candidate_num;
        }
    }
    
    // Count votes
    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < num_candidates; j++) {
            int candidate_num = votes[i][j];
            candidates[candidate_num - 1].vote_count++;
        }
    }
    
    // Find the winner
    candidate_t winner = candidates[0];
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].vote_count > winner.vote_count) {
            winner = candidates[i];
        } else if (candidates[i].vote_count == winner.vote_count) {
            printf("There is a tie between candidates %s and %s\n", winner.name, candidates[i].name);
        }
    }
    
    // Print results
    printf("Winner: %s\n", winner.name);
    printf("Vote count:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].vote_count);
    }
    
    return 0;
}