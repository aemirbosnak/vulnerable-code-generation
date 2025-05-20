//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

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
    int id;
    int voted;
} Voter;

// Initialize the candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

// Initialize the number of candidates and voters
int num_candidates = 0;
int num_voters = 0;

// Get the candidate by their name
Candidate* get_candidate(char *name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return &candidates[i];
        }
    }
    return NULL;
}

// Add a new candidate
void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

// Add a new voter
void add_voter(int id) {
    if (num_voters >= MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }
    voters[num_voters].id = id;
    voters[num_voters].voted = 0;
    num_voters++;
}

// Print the list of candidates
void print_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Print the list of voters
void print_voters() {
    printf("Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d. %d\n", i + 1, voters[i].id);
    }
}

// Get the vote from a voter
int get_vote() {
    int vote;
    printf("Enter the candidate number you want to vote for (1-%d): ", num_candidates);
    scanf("%d", &vote);
    return vote - 1;
}

// Cast a vote for a candidate
void cast_vote(int vote) {
    if (vote < 0 || vote >= num_candidates) {
        printf("Error: Invalid candidate number.\n");
        return;
    }
    candidates[vote].votes++;
}

// Get the winner of the election
Candidate* get_winner() {
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

// Print the results of the election
void print_results() {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    Candidate *winner = get_winner();
    printf("The winner is %s with %d votes.\n", winner->name, winner->votes);
}

// Main function
int main() {
    // Add some candidates
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    // Add some voters
    add_voter(1);
    add_voter(2);
    add_voter(3);

    // Print the list of candidates and voters
    print_candidates();
    print_voters();

    // Get the votes from the voters
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].voted == 0) {
            int vote = get_vote();
            cast_vote(vote);
            voters[i].voted = 1;
        }
    }

    // Print the results of the election
    print_results();

    return 0;
}