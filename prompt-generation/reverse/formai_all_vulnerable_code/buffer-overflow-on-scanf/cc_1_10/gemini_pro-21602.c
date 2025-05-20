//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes per candidate
#define MAX_VOTES 100

// Define the structure of a candidate
typedef struct {
    char *name;
    int votes;
} candidate;

// Create an array of candidates
candidate candidates[NUM_CANDIDATES];

// Get the names of the candidates
void get_candidates() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }
}

// Get the votes for the candidates
void get_votes() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Enter the number of votes for candidate %s: ", candidates[i].name);
        scanf("%d", &candidates[i].votes);
    }
}

// Print the results of the election
void print_results() {
    printf("The results of the election are as follows:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Find the winner of the election
candidate *find_winner() {
    candidate *winner = NULL;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (winner == NULL || candidates[i].votes > winner->votes) {
            winner = &candidates[i];
        }
    }
    return winner;
}

// Main function
int main() {
    // Get the names of the candidates
    get_candidates();

    // Get the votes for the candidates
    get_votes();

    // Print the results of the election
    print_results();

    // Find the winner of the election
    candidate *winner = find_winner();

    // Print the name of the winner
    printf("The winner of the election is %s.\n", winner->name);

    return 0;
}