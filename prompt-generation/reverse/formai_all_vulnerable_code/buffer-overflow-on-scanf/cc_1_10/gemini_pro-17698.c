//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int candidate_id;
} voter;

// Define the array of candidates
candidate candidates[MAX_CANDIDATES];

// Define the array of voters
voter voters[MAX_VOTERS];

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

// Get the details of a candidate
candidate get_candidate_details(int candidate_id) {
    candidate candidate;
    printf("Enter the name of candidate %d: ", candidate_id + 1);
    scanf("%s", candidate.name);
    candidate.votes = 0;
    return candidate;
}

// Get the number of voters
int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the details of a voter
voter get_voter_details(int voter_id) {
    voter voter;
    printf("Enter the name of voter %d: ", voter_id + 1);
    scanf("%s", voter.name);
    printf("Enter the candidate ID that voter %d wants to vote for: ", voter_id + 1);
    scanf("%d", &voter.candidate_id);
    return voter;
}

// Cast a vote for a candidate
void cast_vote(int candidate_id) {
    candidates[candidate_id - 1].votes++;
}

// Find the winner of the election
int find_winner() {
    int max_votes = 0;
    int winner_id = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_id = i;
        }
    }
    return winner_id;
}

// Print the results of the election
void print_results() {
    printf("The results of the election are as follows:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    int winner_id = find_winner();
    if (winner_id == -1) {
        printf("There is no winner. The election is a tie.\n");
    } else {
        printf("The winner of the election is %s.\n", candidates[winner_id].name);
    }
}

// Main function
int main() {
    // Get the number of candidates
    num_candidates = get_num_candidates();

    // Get the details of each candidate
    for (int i = 0; i < num_candidates; i++) {
        candidates[i] = get_candidate_details(i);
    }

    // Get the number of voters
    num_voters = get_num_voters();

    // Get the details of each voter
    for (int i = 0; i < num_voters; i++) {
        voters[i] = get_voter_details(i);
    }

    // Cast votes for each voter
    for (int i = 0; i < num_voters; i++) {
        cast_vote(voters[i].candidate_id);
    }

    // Find the winner of the election
    int winner_id = find_winner();

    // Print the results of the election
    print_results();

    return 0;
}