//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: detailed
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
} Candidate;

// Define the structure of a voter
typedef struct {
    char name[50];
    int hasVoted;
} Voter;

// Initialize the candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the details of the candidates
void get_candidates(int num_candidates) {
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

// Get the details of the voters
void get_voters(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].hasVoted = 0;
    }
}

// Allow a voter to vote
void vote(int voter_index) {
    int candidate_index;
    printf("Voter %s, enter the candidate number you want to vote for: ", voters[voter_index].name);
    scanf("%d", &candidate_index);
    candidates[candidate_index - 1].votes++;
    voters[voter_index].hasVoted = 1;
}

// Check if all voters have voted
int all_voters_voted(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        if (!voters[i].hasVoted) {
            return 0;
        }
    }
    return 1;
}

// Get the winner of the election
int get_winner() {
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    return winner_index;
}

// Print the results of the election
void print_results(int winner_index) {
    printf("The winner of the election is %s with %d votes.\n", candidates[winner_index].name, candidates[winner_index].votes);
}

// Main function
int main() {
    int num_candidates = get_num_candidates();
    get_candidates(num_candidates);
    int num_voters = get_num_voters();
    get_voters(num_voters);
    while (!all_voters_voted(num_voters)) {
        for (int i = 0; i < num_voters; i++) {
            if (!voters[i].hasVoted) {
                vote(i);
            }
        }
    }
    int winner_index = get_winner();
    print_results(winner_index);
    return 0;
}