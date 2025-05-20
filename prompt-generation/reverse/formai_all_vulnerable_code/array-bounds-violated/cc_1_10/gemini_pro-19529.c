//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    // Initialize the candidates
    Candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0}
    };
    const int num_candidates = sizeof(candidates) / sizeof(Candidate);

    // Get the number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allocate memory for the votes
    int* votes = malloc(num_voters * sizeof(int));

    // Get the votes
    printf("Enter the votes:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d: ", i + 1);
        scanf("%d", &votes[i]);
    }

    // Count the votes
    for (int i = 0; i < num_voters; i++) {
        candidates[votes[i]].votes++;
    }

    // Find the winner
    int winning_index;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winning_index].votes) {
            winning_index = i;
        }
    }

    // Print the winner
    printf("The winner is %s with %d votes.\n", candidates[winning_index].name, candidates[winning_index].votes);

    // Free the memory
    free(votes);

    return 0;
}