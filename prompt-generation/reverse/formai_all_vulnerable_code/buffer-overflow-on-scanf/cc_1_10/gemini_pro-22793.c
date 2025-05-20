//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate struct
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// Voter struct
typedef struct Voter {
    char id[50];
    int voted;
} Voter;

// Database of candidates
Candidate candidates[10];

// Database of voters
Voter voters[100];

// Number of candidates
int num_candidates;

// Number of voters
int num_voters;

// Current voter
Voter current_voter;

// Function to initialize the system
void init_system() {
    // Initialize candidates
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].votes = 0;

    // Initialize voters
    for (int i = 0; i < num_voters; i++) {
        strcpy(voters[i].id, "Voter");
        voters[i].voted = 0;
    }

    // Initialize current voter
    current_voter.id[0] = '\0';
    current_voter.voted = 0;

    // Set number of candidates and voters
    num_candidates = 3;
    num_voters = 100;
}

// Function to start the voting process
void start_voting() {
    // Get voter ID
    printf("Enter your voter ID: ");
    scanf("%s", current_voter.id);

    // Check if voter has already voted
    if (current_voter.voted) {
        printf("Error: You have already voted.\n");
        return;
    }

    // Display candidates
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    // Get voter's choice
    int choice;
    printf("Enter your choice (1-%d): ", num_candidates);
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > num_candidates) {
        printf("Error: Invalid choice.\n");
        return;
    }

    // Increment votes for the chosen candidate
    candidates[choice - 1].votes++;

    // Mark voter as having voted
    current_voter.voted = 1;

    // Print confirmation message
    printf("Thank you for voting.\n");
}

// Function to display the results
void display_results() {
    // Print header
    printf("Election Results:\n");

    // Print candidate names and votes
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    int winner = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winner].name);
}

// Main function
int main() {
    // Initialize the system
    init_system();

    // Start the voting process
    start_voting();

    // Display the results
    display_results();

    return 0;
}