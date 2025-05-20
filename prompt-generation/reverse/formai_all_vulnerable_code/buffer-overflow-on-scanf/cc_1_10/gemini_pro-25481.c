//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Structure to represent a candidate
typedef struct {
    char name[50];
    int votes;
} candidate;

// Structure to represent a voter
typedef struct {
    int id;
    int voted;
} voter;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Array of voters
voter voters[MAX_VOTERS];

// Number of candidates
int num_candidates;

// Number of voters
int num_voters;

// Get the number of candidates and voters from the user
void get_num_candidates_and_voters() {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
}

// Get the details of the candidates
void get_candidate_details() {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);

        candidates[i].votes = 0;
    }
}

// Get the details of the voters
void get_voter_details() {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].id);

        voters[i].voted = 0;
    }
}

// Cast a vote
void cast_vote(int voter_id, int candidate_id) {
    // Check if the voter has already voted
    if (voters[voter_id - 1].voted == 1) {
        printf("Error: Voter %d has already voted.\n", voter_id);
        return;
    }

    // Increment the vote count of the candidate
    candidates[candidate_id - 1].votes++;

    // Mark the voter as having voted
    voters[voter_id - 1].voted = 1;

    printf("Vote successfully cast.\n");
}

// Print the results of the election
void print_results() {
    // Find the winner
    int winner_id = 0;
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            winner_id = i;
            max_votes = candidates[i].votes;
        }
    }

    // Print the winner
    printf("The winner is: %s\n", candidates[winner_id].name);

    // Print the vote count of each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Get the number of candidates and voters
    get_num_candidates_and_voters();

    // Get the details of the candidates
    get_candidate_details();

    // Get the details of the voters
    get_voter_details();

    // Cast votes
    int voter_id, candidate_id;
    while (1) {
        printf("Enter the ID of the voter: ");
        scanf("%d", &voter_id);

        printf("Enter the ID of the candidate: ");
        scanf("%d", &candidate_id);

        cast_vote(voter_id, candidate_id);

        printf("Do you want to continue voting? (y/n) ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    // Print the results of the election
    print_results();

    return 0;
}