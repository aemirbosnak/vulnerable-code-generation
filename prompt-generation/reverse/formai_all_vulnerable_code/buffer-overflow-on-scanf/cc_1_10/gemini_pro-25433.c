//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} candidate;

// Define the structure of a voter
typedef struct {
    char name[50];
    int voted;
} voter;

// Define the array of candidates
candidate candidates[MAX_CANDIDATES];

// Define the array of voters
voter voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the details of the candidates
void get_candidate_details(int num_candidates) {
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
void get_voter_details(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
}

// Cast a vote
void cast_vote(int num_candidates, int num_voters) {
    char name[50];
    int candidate_index;

    printf("Enter your name: ");
    scanf("%s", name);

    // Find the voter in the array of voters
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(name, voters[i].name) == 0) {
            voter_index = i;
            break;
        }
    }

    // If the voter is not found, return an error
    if (voter_index == -1) {
        printf("Voter not found\n");
        return;
    }

    // If the voter has already voted, return an error
    if (voters[voter_index].voted == 1) {
        printf("Voter has already voted\n");
        return;
    }

    // Get the name of the candidate the voter wants to vote for
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", name);

    // Find the candidate in the array of candidates
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // If the candidate is not found, return an error
    if (candidate_index == -1) {
        printf("Candidate not found\n");
        return;
    }

    // Cast the vote
    candidates[candidate_index].votes++;
    voters[voter_index].voted = 1;
}

// Get the winner of the election
candidate get_winner(int num_candidates) {
    candidate winner;
    winner.votes = -1;

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    return winner;
}

// Print the results of the election
void print_results(int num_candidates) {
    printf("The results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    candidate winner = get_winner(num_candidates);
    printf("The winner of the election is: %s\n", winner.name);
}

int main() {
    int num_candidates = get_num_candidates();
    get_candidate_details(num_candidates);
    int num_voters = get_num_voters();
    get_voter_details(num_voters);

    for (int i = 0; i < num_voters; i++) {
        cast_vote(num_candidates, num_voters);
    }

    print_results(num_candidates);

    return 0;
}