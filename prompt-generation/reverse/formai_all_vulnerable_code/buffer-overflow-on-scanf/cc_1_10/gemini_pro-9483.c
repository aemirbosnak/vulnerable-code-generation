//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Define the structure of a voter
typedef struct {
    char name[50];
    int voted;
} Voter;

// Create an array of candidates
Candidate candidates[MAX_CANDIDATES];

// Create an array of voters
Voter voters[MAX_VOTERS];

// Initialize the voting system
void init_voting_system() {
    // Set the number of candidates to 0
    int num_candidates = 0;

    // Set the number of voters to 0
    int num_voters = 0;

    // Get the names of the candidates
    printf("Enter the names of the candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        scanf("%s", candidates[i].name);
        num_candidates++;
    }

    // Get the names of the voters
    printf("Enter the names of the voters:\n");
    for (int i = 0; i < MAX_VOTERS; i++) {
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
        num_voters++;
    }
}

// Cast a vote for a candidate
void cast_vote(int voter_index, int candidate_index) {
    // Check if the voter has already voted
    if (voters[voter_index].voted) {
        printf("Error: Voter has already voted\n");
        return;
    }

    // Increment the vote count for the candidate
    candidates[candidate_index].votes++;

    // Mark the voter as having voted
    voters[voter_index].voted = 1;
}

// Count the votes for each candidate
void count_votes() {
    // Iterate over the candidates and print their names and vote counts
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Find the winner of the election
Candidate find_winner() {
    // Initialize the winning candidate to the first candidate
    Candidate winner = candidates[0];

    // Iterate over the remaining candidates and update the winning candidate if they have more votes
    for (int i = 1; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    // Return the winning candidate
    return winner;
}

// Print the results of the election
void print_results(Candidate winner) {
    // Print the name of the winner
    printf("The winner of the election is: %s\n", winner.name);

    // Print the total number of votes cast
    int total_votes = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        total_votes += candidates[i].votes;
    }
    printf("Total number of votes cast: %d\n", total_votes);
}

// Main function
int main() {
    // Initialize the voting system
    init_voting_system();

    // Cast votes for the candidates
    cast_vote(0, 0);
    cast_vote(1, 1);
    cast_vote(2, 2);
    cast_vote(3, 0);
    cast_vote(4, 1);
    cast_vote(5, 2);

    // Count the votes for each candidate
    count_votes();

    // Find the winner of the election
    Candidate winner = find_winner();

    // Print the results of the election
    print_results(winner);

    return 0;
}