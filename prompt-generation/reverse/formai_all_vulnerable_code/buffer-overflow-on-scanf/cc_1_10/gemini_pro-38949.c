//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: scalable
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
int num_candidates;
int num_voters;

// Declare the current voter
int current_voter;

// Declare the winner
int winner;

// Initialize the election system
void init_election() {
    // Set the number of candidates and voters to 0
    num_candidates = 0;
    num_voters = 0;

    // Set the current voter to -1
    current_voter = -1;

    // Set the winner to -1
    winner = -1;
}

// Add a candidate to the election
void add_candidate(char *name) {
    // Check if the number of candidates has reached the maximum
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: The maximum number of candidates has been reached.\n");
        return;
    }

    // Copy the candidate's name to the array of candidates
    strcpy(candidates[num_candidates].name, name);

    // Set the candidate's votes to 0
    candidates[num_candidates].votes = 0;

    // Increment the number of candidates
    num_candidates++;
}

// Add a voter to the election
void add_voter(char *name) {
    // Check if the number of voters has reached the maximum
    if (num_voters >= MAX_VOTERS) {
        printf("Error: The maximum number of voters has been reached.\n");
        return;
    }

    // Copy the voter's name to the array of voters
    strcpy(voters[num_voters].name, name);

    // Set the voter's voted flag to 0
    voters[num_voters].voted = 0;

    // Increment the number of voters
    num_voters++;
}

// Start the election
void start_election() {
    // Loop through the voters
    for (int i = 0; i < num_voters; i++) {
        // Check if the voter has already voted
        if (voters[i].voted == 1) {
            continue;
        }

        // Set the current voter to the current voter
        current_voter = i;

        // Print the list of candidates
        printf("Candidates:\n");
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }

        // Get the voter's vote
        int vote;
        printf("Enter your vote (1-%d): ", num_candidates);
        scanf("%d", &vote);

        // Check if the vote is valid
        if (vote < 1 || vote > num_candidates) {
            printf("Error: Invalid vote.\n");
            continue;
        }

        // Increment the vote for the selected candidate
        candidates[vote - 1].votes++;

        // Set the voter's voted flag to 1
        voters[i].voted = 1;
    }

    // Set the winner to the candidate with the most votes
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }
}

// Print the results of the election
void print_results() {
    // Print the winner
    printf("The winner is: %s\n", candidates[winner].name);

    // Print the number of votes for each candidate
    printf("Candidate Votes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s %d\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Initialize the election system
    init_election();

    // Add candidates to the election
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    // Add voters to the election
    add_voter("John");
    add_voter("Jane");
    add_voter("Joe");

    // Start the election
    start_election();

    // Print the results of the election
    print_results();

    return 0;
}