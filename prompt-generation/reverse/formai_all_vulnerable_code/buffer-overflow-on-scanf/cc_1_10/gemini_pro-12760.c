//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Voter structure
typedef struct {
    char name[50];
    int age;
    char address[100];
    int voted;
} Voter;

// Candidate structure
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Voter database
Voter voters[100];

// Candidate database
Candidate candidates[10];

// Number of voters
int num_voters;

// Number of candidates
int num_candidates;

// Main function
int main() {
    // Initialize voter database
    num_voters = 0;
    strcpy(voters[num_voters].name, "Alice");
    voters[num_voters].age = 20;
    strcpy(voters[num_voters].address, "123 Main Street");
    voters[num_voters].voted = 0;
    num_voters++;

    strcpy(voters[num_voters].name, "Bob");
    voters[num_voters].age = 30;
    strcpy(voters[num_voters].address, "456 Elm Street");
    voters[num_voters].voted = 0;
    num_voters++;

    strcpy(voters[num_voters].name, "Carol");
    voters[num_voters].age = 40;
    strcpy(voters[num_voters].address, "789 Oak Street");
    voters[num_voters].voted = 0;
    num_voters++;

    // Initialize candidate database
    num_candidates = 0;
    strcpy(candidates[num_candidates].name, "John Smith");
    candidates[num_candidates].votes = 0;
    num_candidates++;

    strcpy(candidates[num_candidates].name, "Jane Doe");
    candidates[num_candidates].votes = 0;
    num_candidates++;

    // Welcome message
    printf("Welcome to the electronic voting system!\n");

    // Get voter input
    int voter_id;
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);

    // Check if voter is eligible to vote
    if (voter_id < 0 || voter_id >= num_voters || voters[voter_id].voted) {
        printf("Invalid voter ID or you have already voted.\n");
        return 1;
    }

    // Get candidate input
    int candidate_id;
    printf("Enter the candidate you want to vote for (0-%d): ", num_candidates - 1);
    scanf("%d", &candidate_id);

    // Check if candidate is valid
    if (candidate_id < 0 || candidate_id >= num_candidates) {
        printf("Invalid candidate ID.\n");
        return 1;
    }

    // Increment candidate's vote count
    candidates[candidate_id].votes++;

    // Mark voter as having voted
    voters[voter_id].voted = 1;

    // Thank you message
    printf("Thank you for voting!\n");

    // Print election results
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    int winner_id = 0;
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > candidates[winner_id].votes) {
            winner_id = i;
        }
    }

    // Print the winner
    printf("The winner is %s with %d votes.\n", candidates[winner_id].name, candidates[winner_id].votes);

    return 0;
}