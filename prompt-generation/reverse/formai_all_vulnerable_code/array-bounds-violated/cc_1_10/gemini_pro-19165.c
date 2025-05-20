//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate information
typedef struct candidate {
    char name[100];
    int votes;
} candidate;

// Array to store candidates
candidate candidates[10];

// Function to initialize candidates
void initialize_candidates() {
    strcpy(candidates[0].name, "John Doe");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Jane Smith");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Mark Jones");
    candidates[2].votes = 0;
    // ...
}

// Function to vote for a candidate
void vote(int candidate_index) {
    candidates[candidate_index].votes++;
}

// Function to get the winner
candidate* get_winner() {
    candidate* winner = &candidates[0];
    for (int i = 1; i < 10; i++) {
        if (candidates[i].votes > winner->votes) {
            winner = &candidates[i];
        }
    }
    return winner;
}

// Main function
int main() {
    // Initialize candidates
    initialize_candidates();

    // Get user input
    printf("Enter the candidate you want to vote for (1-10): ");
    int candidate_index;
    scanf("%d", &candidate_index);

    // Vote for the candidate
    vote(candidate_index - 1);

    // Get the winner
    candidate* winner = get_winner();

    // Print the results
    printf("The winner is %s with %d votes.\n", winner->name, winner->votes);

    return 0;
}