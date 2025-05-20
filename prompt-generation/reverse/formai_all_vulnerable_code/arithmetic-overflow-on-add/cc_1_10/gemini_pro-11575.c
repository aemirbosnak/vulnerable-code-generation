//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Candidate structure
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Main function
int main() {
    // Initialize the candidates
    candidate candidates[5] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    // Initialize the voting system
    int num_candidates = 5;
    int num_voters = 100;
    int votes[num_candidates];
    int valid_votes = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the votes
    for (int i = 0; i < num_voters; i++) {
        int candidate_index = rand() % num_candidates;
        votes[candidate_index]++;
        valid_votes++;
    }

    // Print the results
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %.2f%%\n", candidates[i].name, (float)candidates[i].votes / valid_votes * 100);
    }

    // Find the winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winner_index].name);

    return 0;
}