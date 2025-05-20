//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes per candidate
#define MAX_VOTES 100

// Create a struct to store the candidate's name and number of votes
typedef struct {
    char *name;
    int num_votes;
} candidate_t;

// Create an array of candidates
candidate_t candidates[NUM_CANDIDATES] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0},
    {"Eve", 0}
};

// Get the user's vote
int get_vote() {
    int vote;
    printf("Enter the number of the candidate you want to vote for (1-%d): ", NUM_CANDIDATES);
    scanf("%d", &vote);
    return vote;
}

// Validate the user's vote
int validate_vote(int vote) {
    if (vote < 1 || vote > NUM_CANDIDATES) {
        printf("Invalid vote. Please enter a number between 1 and %d.\n", NUM_CANDIDATES);
        return 0;
    }
    return 1;
}

// Cast the user's vote
void cast_vote(int vote) {
    candidates[vote - 1].num_votes++;
}

// Print the results of the election
void print_results() {
    printf("Election results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].num_votes);
    }
}

// Free the memory allocated for the candidates
void free_candidates() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        free(candidates[i].name);
    }
}

// Main function
int main() {
    // Get the user's vote
    int vote = get_vote();

    // Validate the user's vote
    if (!validate_vote(vote)) {
        return 1;
    }

    // Cast the user's vote
    cast_vote(vote);

    // Print the results of the election
    print_results();

    // Free the memory allocated for the candidates
    free_candidates();

    return 0;
}