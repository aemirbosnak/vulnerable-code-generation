//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
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

// Define the array of candidates
Candidate candidates[MAX_CANDIDATES];

// Define the array of voters
Voter voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the candidate information
void get_candidate_info(int num_candidates) {
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

// Get the voter information
void get_voter_info(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].id);
        voters[i].voted = 0;
    }
}

// Display the ballot
void display_ballot(int num_candidates) {
    printf("\nBallot:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Enter the number of the candidate you want to vote for: ");
}

// Cast a vote
void cast_vote(int num_candidates) {
    int vote;
    scanf("%d", &vote);
    if (vote >= 1 && vote <= num_candidates) {
        candidates[vote - 1].votes++;
        voters[vote - 1].voted = 1;
    } else {
        printf("Invalid vote. Please try again.\n");
        cast_vote(num_candidates);
    }
}

// Count the votes
void count_votes(int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Find the winner
Candidate find_winner(int num_candidates) {
    Candidate winner = candidates[0];
    for (int i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
    return winner;
}

// Display the results
void display_results(Candidate winner) {
    printf("\nThe winner is: %s\n", winner.name);
}

// Main function
int main() {
    int num_candidates = get_num_candidates();
    get_candidate_info(num_candidates);
    int num_voters = get_num_voters();
    get_voter_info(num_voters);
    for (int i = 0; i < num_voters; i++) {
        if (!voters[i].voted) {
            display_ballot(num_candidates);
            cast_vote(num_candidates);
        }
    }
    count_votes(num_candidates);
    Candidate winner = find_winner(num_candidates);
    display_results(winner);
    return 0;
}