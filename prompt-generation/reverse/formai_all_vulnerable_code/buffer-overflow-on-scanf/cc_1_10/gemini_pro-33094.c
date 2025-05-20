//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char *name;
    int votes;
} candidate_t;

// Define the structure of a voter
typedef struct {
    char *name;
    int voted;
} voter_t;

// Create an array of candidates
candidate_t candidates[MAX_CANDIDATES];

// Create an array of voters
voter_t voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the details of a candidate
void get_candidate_details(candidate_t *candidate) {
    printf("Enter the name of the candidate: ");
    scanf(" %[^\n]%*c", candidate->name);
    candidate->votes = 0;
}

// Get the number of voters
int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the details of a voter
void get_voter_details(voter_t *voter) {
    printf("Enter the name of the voter: ");
    scanf(" %[^\n]%*c", voter->name);
    voter->voted = 0;
}

// Print the candidates
void print_candidates(int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Get the vote of a voter
int get_vote(int num_candidates) {
    int vote;
    printf("Enter your vote (1-%d): ", num_candidates);
    scanf("%d", &vote);
    return vote;
}

// Update the vote count of a candidate
void update_vote_count(int vote, candidate_t *candidates) {
    candidates[vote - 1].votes++;
}

// Check if a voter has already voted
int has_voted(voter_t *voter) {
    return voter->voted;
}

// Mark a voter as having voted
void mark_voted(voter_t *voter) {
    voter->voted = 1;
}

// Print the results of the election
void print_results(int num_candidates) {
    printf("The results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Free the memory allocated for the candidates and voters
void free_memory(int num_candidates, int num_voters) {
    for (int i = 0; i < num_candidates; i++) {
        free(candidates[i].name);
    }
    for (int i = 0; i < num_voters; i++) {
        free(voters[i].name);
    }
}

int main() {
    // Get the number of candidates and voters
    int num_candidates = get_num_candidates();
    int num_voters = get_num_voters();

    // Get the details of the candidates
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].name = malloc(100 * sizeof(char));
        get_candidate_details(&candidates[i]);
    }

    // Get the details of the voters
    for (int i = 0; i < num_voters; i++) {
        voters[i].name = malloc(100 * sizeof(char));
        get_voter_details(&voters[i]);
    }

    // Print the candidates
    print_candidates(num_candidates);

    // Allow the voters to vote
    for (int i = 0; i < num_voters; i++) {
        if (!has_voted(&voters[i])) {
            int vote = get_vote(num_candidates);
            update_vote_count(vote, candidates);
            mark_voted(&voters[i]);
        }
    }

    // Print the results of the election
    print_results(num_candidates);

    // Free the memory allocated for the candidates and voters
    free_memory(num_candidates, num_voters);

    return 0;
}