//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int has_voted;
} Voter;

// Define the array of candidates
Candidate candidates[MAX_CANDIDATES];

// Define the array of voters
Voter voters[MAX_VOTERS];

// Define the number of candidates and voters
int num_candidates = 0;
int num_voters = 0;

// Initialize the voting system
void init_voting_system() {
    // Add candidates to the array
    strcpy(candidates[0].name, "Candidate A");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Candidate B");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Candidate C");
    candidates[2].votes = 0;

    // Add voters to the array
    strcpy(voters[0].name, "Voter A");
    voters[0].has_voted = 0;
    strcpy(voters[1].name, "Voter B");
    voters[1].has_voted = 0;
    strcpy(voters[2].name, "Voter C");
    voters[2].has_voted = 0;

    // Set the number of candidates and voters
    num_candidates = 3;
    num_voters = 3;
}

// Display the candidates
void display_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Display the voters
void display_voters() {
    printf("Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s\n", i + 1, voters[i].name);
    }
}

// Get the vote from a voter
int get_vote(Voter *voter) {
    int candidate_id;

    printf("Enter the candidate ID you want to vote for: ");
    scanf("%d", &candidate_id);

    // Check if the candidate ID is valid
    if (candidate_id < 1 || candidate_id > num_candidates) {
        printf("Invalid candidate ID.\n");
        return -1;
    }

    // Check if the voter has already voted
    if (voter->has_voted) {
        printf("You have already voted.\n");
        return -1;
    }

    // Increment the vote count for the candidate
    candidates[candidate_id - 1].votes++;

    // Mark the voter as having voted
    voter->has_voted = 1;

    return 0;
}

// Get the winner of the election
Candidate *get_winner() {
    // Find the candidate with the most votes
    Candidate *winner = NULL;
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            winner = &candidates[i];
            max_votes = candidates[i].votes;
        }
    }

    return winner;
}

// Main function
int main() {
    // Initialize the voting system
    init_voting_system();

    // Display the candidates
    display_candidates();

    // Display the voters
    display_voters();

    // Get the votes from the voters
    for (int i = 0; i < num_voters; i++) {
        if (get_vote(&voters[i]) == -1) {
            i--;
        }
    }

    // Get the winner of the election
    Candidate *winner = get_winner();

    // Print the results of the election
    printf("The winner of the election is: %s\n", winner->name);

    return 0;
}