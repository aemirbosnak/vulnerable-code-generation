//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate data type
typedef struct {
    int id;
    char name[100];
    int vote_count;
} candidate_t;

// Define the voter data type
typedef struct {
    int id;
    char name[100];
    int voted;
} voter_t;

// Declare the global variables
candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];
int num_candidates;
int num_voters;

// Initialize the electronic voting system
void init_system() {
    // Initialize the candidates
    candidates[0].id = 1;
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].vote_count = 0;
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].vote_count = 0;
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].vote_count = 0;
    num_candidates = 3;

    // Initialize the voters
    voters[0].id = 1;
    strcpy(voters[0].name, "Voter 1");
    voters[0].voted = 0;
    voters[1].id = 2;
    strcpy(voters[1].name, "Voter 2");
    voters[1].voted = 0;
    voters[2].id = 3;
    strcpy(voters[2].name, "Voter 3");
    voters[2].voted = 0;
    num_voters = 3;
}

// Print the candidate list
void print_candidates() {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

// Get the voter's choice
int get_voter_choice() {
    int choice;
    printf("Enter your choice (1-%d): ", num_candidates);
    scanf("%d", &choice);
    return choice;
}

// Cast a vote
void cast_vote(int voter_id, int candidate_id) {
    // Find the voter
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            // Mark the voter as voted
            voters[i].voted = 1;

            // Find the candidate
            for (int j = 0; j < num_candidates; j++) {
                if (candidates[j].id == candidate_id) {
                    // Increment the candidate's vote count
                    candidates[j].vote_count++;

                    // Break out of the loop
                    break;
                }
            }

            // Break out of the loop
            break;
        }
    }
}

// Count the votes
void count_votes() {
    // Iterate over the candidates
    for (int i = 0; i < num_candidates; i++) {
        // Print the candidate's name and vote count
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

// Declare the main function
int main() {
    // Initialize the system
    init_system();

    // Print the candidate list
    print_candidates();

    // Get the voter's choice
    int voter_id = 1;
    int choice = get_voter_choice();

    // Cast the vote
    cast_vote(voter_id, choice);

    // Count the votes
    count_votes();

    return 0;
}