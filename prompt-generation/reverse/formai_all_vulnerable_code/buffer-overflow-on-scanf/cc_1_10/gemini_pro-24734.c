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
} candidate_t;

// Define the structure of a voter
typedef struct {
    char name[50];
    int has_voted;
} voter_t;

// Define the array of candidates
candidate_t candidates[MAX_CANDIDATES];

// Define the array of voters
voter_t voters[MAX_VOTERS];

// Initialize the voting system
void initialize_voting_system() {
    // Set the number of candidates to 0
    int num_candidates = 0;

    // Set the number of voters to 0
    int num_voters = 0;

    // Prompt the user to enter the names of the candidates
    printf("Enter the names of the candidates (max %d):\n", MAX_CANDIDATES);
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        scanf("%s", candidates[i].name);
        if (strcmp(candidates[i].name, "") == 0) {
            break;
        }
        num_candidates++;
    }

    // Prompt the user to enter the names of the voters
    printf("Enter the names of the voters (max %d):\n", MAX_VOTERS);
    for (int i = 0; i < MAX_VOTERS; i++) {
        scanf("%s", voters[i].name);
        if (strcmp(voters[i].name, "") == 0) {
            break;
        }
        voters[i].has_voted = 0;
        num_voters++;
    }

    // Set the number of candidates and voters
    num_candidates = num_candidates;
    num_voters = num_voters;
}

// Cast a vote for a candidate
void cast_vote(char *voter_name, char *candidate_name) {
    // Find the voter
    int voter_index = -1;
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            voter_index = i;
            break;
        }
    }

    // Check if the voter has already voted
    if (voter_index == -1 || voters[voter_index].has_voted) {
        printf("Error: Voter %s has already voted or does not exist.\n", voter_name);
        return;
    }

    // Find the candidate
    int candidate_index = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // Check if the candidate exists
    if (candidate_index == -1) {
        printf("Error: Candidate %s does not exist.\n", candidate_name);
        return;
    }

    // Cast the vote
    candidates[candidate_index].votes++;
    voters[voter_index].has_voted = 1;
}

// Get the winner of the election
char *get_winner() {
    // Find the candidate with the most votes
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Return the name of the winner
    return candidates[winner_index].name;
}

// Print the results of the election
void print_results() {
    // Print the names of the candidates and their votes
    printf("Election Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > 0) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }

    // Print the name of the winner
    printf("Winner: %s\n", get_winner());
}

// Main function
int main() {
    // Initialize the voting system
    initialize_voting_system();

    // Cast some votes
    cast_vote("John Doe", "Alice Smith");
    cast_vote("Jane Smith", "Bob Jones");
    cast_vote("Bill Jones", "Alice Smith");
    cast_vote("Mary Johnson", "Bob Jones");
    cast_vote("Tom Brown", "Alice Smith");

    // Print the results of the election
    print_results();

    return 0;
}