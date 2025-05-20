//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate details
struct candidate {
    char name[50];
    int votes;
};

// Array of candidates
struct candidate candidates[4] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"Dave", 0}
};

// Get number of candidates
int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

// Get number of voters
int num_voters;

// Get votes for each candidate
void get_votes() {
    for (int i = 0; i < num_voters; i++) {
        int vote;
        printf("Enter your vote (1-%d): ", num_candidates);
        scanf("%d", &vote);
        candidates[vote - 1].votes++;
    }
}

// Print results
void print_results() {
    printf("\nElection Results:\n\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Declare and initialize necessary variables
int main() {
    printf("Welcome to the Electronic Voting System!\n\n");
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    get_votes();
    print_results();
    return 0;
}