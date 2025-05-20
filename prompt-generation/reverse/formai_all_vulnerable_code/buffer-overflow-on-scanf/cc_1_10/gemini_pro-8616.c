//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the data structures
typedef struct {
    char name[20];
    int votes;
} Candidate;

typedef struct {
    char name[20];
    int voted;
} Voter;

// Initialize the candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

// Get the number of candidates and voters
int num_candidates, num_voters;

// Initialize the voting system
void init_voting_system() {
    // Get the number of candidates and voters
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Initialize the candidates
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Initialize the voters
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
}

// Cast a vote
void cast_vote(int voter_index, int candidate_index) {
    // Check if the voter has already voted
    if (voters[voter_index].voted == 1) {
        printf("Error: Voter has already voted.\n");
        return;
    }

    // Increment the vote count for the candidate
    candidates[candidate_index].votes++;

    // Mark the voter as having voted
    voters[voter_index].voted = 1;
}

// Count the votes
void count_votes() {
    // Initialize the vote count for each candidate
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }

    // Count the votes for each voter
    for (int i = 0; i < num_voters; i++) {
        // Check if the voter has voted
        if (voters[i].voted == 1) {
            // Get the candidate index that the voter voted for
            int candidate_index = -1;
            for (int j = 0; j < num_candidates; j++) {
                if (strcmp(voters[i].name, candidates[j].name) == 0) {
                    candidate_index = j;
                    break;
                }
            }

            // Increment the vote count for the candidate
            candidates[candidate_index].votes++;
        }
    }
}

// Print the results
void print_results() {
    // Find the winner
    int winner_index = -1;
    int max_votes = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            winner_index = i;
            max_votes = candidates[i].votes;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winner_index].name);
}

// Main function
int main() {
    // Initialize the voting system
    init_voting_system();

    // Cast votes
    for (int i = 0; i < num_voters; i++) {
        // Get the voter's choice
        int candidate_index;
        printf("Enter the number of the candidate you want to vote for (1-%d): ", num_candidates);
        scanf("%d", &candidate_index);

        // Cast the vote
        cast_vote(i, candidate_index - 1);
    }

    // Count the votes
    count_votes();

    // Print the results
    print_results();

    return 0;
}