//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Structure to store the candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

// Structure to store the voter details
typedef struct voter {
    char name[50];
    int voted;
} voter_t;

// Function to initialize the candidates
void initialize_candidates(candidate_t *candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        strcpy(candidates[i].name, "");
        candidates[i].votes = 0;
    }
}

// Function to initialize the voters
void initialize_voters(voter_t *voters, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        strcpy(voters[i].name, "");
        voters[i].voted = 0;
    }
}

// Function to add a candidate
void add_candidate(candidate_t *candidates, int *num_candidates, char *name) {
    if (*num_candidates < MAX_CANDIDATES) {
        strcpy(candidates[*num_candidates].name, name);
        (*num_candidates)++;
    } else {
        printf("Error: Maximum number of candidates reached.\n");
    }
}

// Function to add a voter
void add_voter(voter_t *voters, int *num_voters, char *name) {
    if (*num_voters < MAX_VOTERS) {
        strcpy(voters[*num_voters].name, name);
        (*num_voters)++;
    } else {
        printf("Error: Maximum number of voters reached.\n");
    }
}

// Function to vote for a candidate
void vote(candidate_t *candidates, voter_t *voters, int num_candidates, int num_voters, char *voter_name, char *candidate_name) {
    // Find the voter
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            voter_index = i;
            break;
        }
    }

    // Check if the voter has already voted
    if (voter_index != -1 && voters[voter_index].voted == 0) {
        // Find the candidate
        int candidate_index = -1;
        for (int i = 0; i < num_candidates; i++) {
            if (strcmp(candidates[i].name, candidate_name) == 0) {
                candidate_index = i;
                break;
            }
        }

        // Check if the candidate is valid
        if (candidate_index != -1) {
            // Increment the candidate's vote count
            candidates[candidate_index].votes++;

            // Mark the voter as having voted
            voters[voter_index].voted = 1;

            printf("Vote recorded successfully.\n");
        } else {
            printf("Error: Invalid candidate name.\n");
        }
    } else {
        printf("Error: Voter has already voted or does not exist.\n");
    }
}

// Function to print the election results
void print_results(candidate_t *candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Initialize the candidates and voters
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates = 0;
    int num_voters = 0;

    // Add some candidates
    add_candidate(candidates, &num_candidates, "Candidate 1");
    add_candidate(candidates, &num_candidates, "Candidate 2");
    add_candidate(candidates, &num_candidates, "Candidate 3");

    // Add some voters
    add_voter(voters, &num_voters, "Voter 1");
    add_voter(voters, &num_voters, "Voter 2");
    add_voter(voters, &num_voters, "Voter 3");

    // Cast some votes
    vote(candidates, voters, num_candidates, num_voters, "Voter 1", "Candidate 1");
    vote(candidates, voters, num_candidates, num_voters, "Voter 2", "Candidate 2");
    vote(candidates, voters, num_candidates, num_voters, "Voter 3", "Candidate 3");

    // Print the election results
    print_results(candidates, num_candidates);

    return 0;
}