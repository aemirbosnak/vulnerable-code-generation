//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A struct to represent a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// A struct to represent the election results
typedef struct results {
    candidate candidates[10];
    int num_candidates;
    int total_votes;
} results;

// Function to create a new candidate
candidate create_candidate(char name[]) {
    candidate new_candidate;
    strcpy(new_candidate.name, name);
    new_candidate.votes = 0;
    return new_candidate;
}

// Function to add a candidate to the election
void add_candidate(results *election, candidate new_candidate) {
    election->candidates[election->num_candidates] = new_candidate;
    election->num_candidates++;
}

// Function to cast a vote for a candidate
void cast_vote(results *election, char candidate_name[]) {
    for (int i = 0; i < election->num_candidates; i++) {
        if (strcmp(election->candidates[i].name, candidate_name) == 0) {
            election->candidates[i].votes++;
            election->total_votes++;
            break;
        }
    }
}

// Function to print the election results
void print_results(results *election) {
    printf("Election Results:\n");
    printf("Total Votes: %d\n", election->total_votes);
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

// Main function
int main() {
    // Create a new election
    results election;
    election.num_candidates = 0;
    election.total_votes = 0;

    // Add candidates to the election
    add_candidate(&election, create_candidate("Alice"));
    add_candidate(&election, create_candidate("Bob"));
    add_candidate(&election, create_candidate("Carol"));

    // Cast votes for candidates
    cast_vote(&election, "Alice");
    cast_vote(&election, "Bob");
    cast_vote(&election, "Carol");
    cast_vote(&election, "Alice");

    // Print the election results
    print_results(&election);

    return 0;
}