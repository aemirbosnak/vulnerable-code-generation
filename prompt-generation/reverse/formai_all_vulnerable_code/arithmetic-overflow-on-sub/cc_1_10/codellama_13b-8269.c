//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define NUM_CANDIDATES 3
#define NUM_VOTERS 5

// Define data structures
struct voter {
    char name[32];
    int votes[NUM_CANDIDATES];
};

struct candidate {
    char name[32];
    int votes;
};

// Function prototypes
void display_voters(struct voter voters[], int num_voters);
void display_candidates(struct candidate candidates[], int num_candidates);
void vote(struct voter voters[], int num_voters, struct candidate candidates[], int num_candidates);

// Main function
int main() {
    // Initialize voters
    struct voter voters[NUM_VOTERS] = {
        { "Alice", { 0, 0, 0 } },
        { "Bob", { 0, 0, 0 } },
        { "Charlie", { 0, 0, 0 } },
        { "David", { 0, 0, 0 } },
        { "Eve", { 0, 0, 0 } }
    };

    // Initialize candidates
    struct candidate candidates[NUM_CANDIDATES] = {
        { "Candidate 1", 0 },
        { "Candidate 2", 0 },
        { "Candidate 3", 0 }
    };

    // Display initial state
    display_voters(voters, NUM_VOTERS);
    display_candidates(candidates, NUM_CANDIDATES);

    // Ask for votes
    vote(voters, NUM_VOTERS, candidates, NUM_CANDIDATES);

    // Display final state
    display_voters(voters, NUM_VOTERS);
    display_candidates(candidates, NUM_CANDIDATES);

    return 0;
}

// Function definitions
void display_voters(struct voter voters[], int num_voters) {
    printf("Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("  %s: ", voters[i].name);
        for (int j = 0; j < NUM_CANDIDATES; j++) {
            printf("%d ", voters[i].votes[j]);
        }
        printf("\n");
    }
}

void display_candidates(struct candidate candidates[], int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("  %s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void vote(struct voter voters[], int num_voters, struct candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s, please enter your vote (1, 2, or 3): ", voters[i].name);
        int vote;
        scanf("%d", &vote);
        voters[i].votes[vote - 1]++;
    }
}