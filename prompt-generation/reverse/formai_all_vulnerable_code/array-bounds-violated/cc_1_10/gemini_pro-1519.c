//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char name[20];
    int votes;
} Candidate;

// Define the structure of a voter
typedef struct {
    int id;
    int voted;
} Voter;

// Define the array of candidates
Candidate candidates[MAX_CANDIDATES];

// Define the array of voters
Voter voters[MAX_VOTERS];

// Define the number of candidates
int num_candidates;

// Define the number of voters
int num_voters;

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the candidates
void get_candidates() {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Get the number of voters
int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the voters
void get_voters() {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].id);
        voters[i].voted = 0;
    }
}

// Vote for a candidate
void vote(int voter_id, int candidate_id) {
    if (voters[voter_id - 1].voted == 0) {
        candidates[candidate_id - 1].votes++;
        voters[voter_id - 1].voted = 1;
    } else {
        printf("Voter %d has already voted.\n", voter_id);
    }
}

// Print the results of the election
void print_results() {
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Get the number of candidates
    num_candidates = get_num_candidates();

    // Get the candidates
    get_candidates();

    // Get the number of voters
    num_voters = get_num_voters();

    // Get the voters
    get_voters();

    // Vote for a candidate
    int voter_id, candidate_id;
    printf("Enter the ID of the voter: ");
    scanf("%d", &voter_id);
    printf("Enter the ID of the candidate: ");
    scanf("%d", &candidate_id);
    vote(voter_id, candidate_id);

    // Print the results of the election
    print_results();

    return 0;
}