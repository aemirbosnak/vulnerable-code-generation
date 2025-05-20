//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
// EVS.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for a candidate
struct Candidate {
    char name[100];
    int votes;
};

// Structure for a voter
struct Voter {
    char name[100];
    int vote;
};

// Structure for an election
struct Election {
    char name[100];
    int num_candidates;
    struct Candidate *candidates;
    int num_voters;
    struct Voter *voters;
};

// Function to create a new election
struct Election* create_election(char* name, int num_candidates, int num_voters) {
    struct Election* election = malloc(sizeof(struct Election));
    strcpy(election->name, name);
    election->num_candidates = num_candidates;
    election->candidates = malloc(num_candidates * sizeof(struct Candidate));
    election->num_voters = num_voters;
    election->voters = malloc(num_voters * sizeof(struct Voter));
    return election;
}

// Function to add a candidate to an election
void add_candidate(struct Election* election, char* name) {
    struct Candidate* candidate = &election->candidates[election->num_candidates];
    strcpy(candidate->name, name);
    candidate->votes = 0;
    election->num_candidates++;
}

// Function to add a voter to an election
void add_voter(struct Election* election, char* name) {
    struct Voter* voter = &election->voters[election->num_voters];
    strcpy(voter->name, name);
    voter->vote = 0;
    election->num_voters++;
}

// Function to cast a vote
void cast_vote(struct Election* election, int voter_index, int candidate_index) {
    struct Voter* voter = &election->voters[voter_index];
    struct Candidate* candidate = &election->candidates[candidate_index];
    voter->vote = candidate_index;
    candidate->votes++;
}

// Function to tally the votes
void tally_votes(struct Election* election) {
    for (int i = 0; i < election->num_candidates; i++) {
        struct Candidate* candidate = &election->candidates[i];
        printf("Candidate %s has %d votes\n", candidate->name, candidate->votes);
    }
}

// Function to print the winner
void print_winner(struct Election* election) {
    int max_votes = 0;
    int winner_index = 0;
    for (int i = 0; i < election->num_candidates; i++) {
        struct Candidate* candidate = &election->candidates[i];
        if (candidate->votes > max_votes) {
            max_votes = candidate->votes;
            winner_index = i;
        }
    }
    struct Candidate* winner = &election->candidates[winner_index];
    printf("Winner: %s\n", winner->name);
}

int main() {
    // Create a new election
    struct Election* election = create_election("EVS", 2, 5);

    // Add candidates
    add_candidate(election, "Candidate 1");
    add_candidate(election, "Candidate 2");

    // Add voters
    add_voter(election, "Voter 1");
    add_voter(election, "Voter 2");
    add_voter(election, "Voter 3");
    add_voter(election, "Voter 4");
    add_voter(election, "Voter 5");

    // Cast votes
    cast_vote(election, 0, 0);
    cast_vote(election, 1, 0);
    cast_vote(election, 2, 1);
    cast_vote(election, 3, 1);
    cast_vote(election, 4, 0);

    // Tally the votes
    tally_votes(election);

    // Print the winner
    print_winner(election);

    // Free memory
    free(election->candidates);
    free(election->voters);
    free(election);

    return 0;
}