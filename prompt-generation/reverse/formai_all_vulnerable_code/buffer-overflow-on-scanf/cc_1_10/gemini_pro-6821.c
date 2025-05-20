//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

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

// Declare the array of candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

// Declare the number of candidates and voters
int num_candidates, num_voters;

// Declare the winner of the election
Candidate winner;

// Initialize the election system
void initialize_election() {
    // Set the number of candidates and voters
    num_candidates = 3;
    num_voters = 5;

    // Initialize the candidates
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].votes = 0;

    // Initialize the voters
    for (int i = 0; i < num_voters; i++) {
        sprintf(voters[i].name, "Voter %d", i + 1);
        voters[i].voted = 0;
    }
}

// Print the current standings of the election
void print_standings() {
    printf("Current standings:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

// Allow a voter to vote for a candidate
void vote(Voter *voter, Candidate *candidate) {
    // Check if the voter has already voted
    if (voter->voted) {
        printf("Error: Voter has already voted\n");
        return;
    }

    // Increment the vote count for the candidate
    candidate->votes++;

    // Mark the voter as having voted
    voter->voted = 1;
}

// Determine the winner of the election
void determine_winner() {
    // Initialize the winner to the first candidate
    winner = candidates[0];

    // Iterate through the remaining candidates
    for (int i = 1; i < num_candidates; i++) {
        // If the current candidate has more votes than the winner,
        // update the winner
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
}

// Print the results of the election
void print_results() {
    printf("Election results:\n");
    printf("Winner: %s\n", winner.name);
    printf("Total votes: %d\n", winner.votes);
    printf("\n");
}

// Main function
int main() {
    // Initialize the election system
    initialize_election();

    // Print the initial standings
    print_standings();

    // Allow the voters to vote
    for (int i = 0; i < num_voters; i++) {
        // Get the voter's choice
        int choice;
        printf("Voter %d, please enter your choice (1-%d): ", i + 1, num_candidates);
        scanf("%d", &choice);

        // Validate the voter's choice
        if (choice < 1 || choice > num_candidates) {
            printf("Error: Invalid choice\n");
            continue;
        }

        // Cast the voter's vote
        vote(&voters[i], &candidates[choice - 1]);
    }

    // Print the final standings
    print_standings();

    // Determine the winner of the election
    determine_winner();

    // Print the results of the election
    print_results();

    return 0;
}