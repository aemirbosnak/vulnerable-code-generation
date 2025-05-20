//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate information
typedef struct candidate {
    char name[50];
    int votes;
} Candidate;

// Global variables
Candidate candidates[10];
int num_candidates = 0;
int num_voters = 0;

// Function to add a candidate
void add_candidate(char *name) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

// Function to vote for a candidate
void vote(int candidate_num) {
    candidates[candidate_num].votes++;
}

// Function to print the results
void print_results() {
    int winner_index = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winner_index].votes) {
            winner_index = i;
        }
    }

    printf("The winner is %s with %d votes\n", candidates[winner_index].name, candidates[winner_index].votes);
}

// Main function
int main() {
    // Add candidates
    add_candidate("John Doe");
    add_candidate("Jane Doe");
    add_candidate("Bob Smith");

    // Get number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get votes
    for (int i = 0; i < num_voters; i++) {
        int candidate_num;
        printf("Enter the number of the candidate you want to vote for: ");
        scanf("%d", &candidate_num);
        vote(candidate_num);
    }

    // Print results
    print_results();

    return 0;
}