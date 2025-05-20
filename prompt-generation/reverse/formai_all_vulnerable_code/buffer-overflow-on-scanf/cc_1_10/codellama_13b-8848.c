//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: modular
// modular_voting_system.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for a candidate
struct Candidate {
    char name[100];
    int votes;
};

// Function to print the results
void print_results(struct Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to vote
void vote(struct Candidate candidates[], int num_candidates, char* candidate_name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidates[i].votes++;
            return;
        }
    }
}

int main() {
    // Initialize candidates
    struct Candidate candidates[] = {
        {"John", 0},
        {"Jane", 0},
        {"Bob", 0}
    };

    // Get number of candidates
    int num_candidates = sizeof(candidates) / sizeof(struct Candidate);

    // Get user input
    char candidate_name[100];
    printf("Enter candidate name: ");
    scanf("%s", candidate_name);

    // Vote
    vote(candidates, num_candidates, candidate_name);

    // Print results
    print_results(candidates, num_candidates);

    return 0;
}