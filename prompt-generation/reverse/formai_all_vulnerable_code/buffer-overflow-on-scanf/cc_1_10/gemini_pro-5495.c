//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the data structures for the candidates and voters
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

typedef struct voter {
    int id;
    int voted;
} voter;

// Initialize the candidates and voters
candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

// Get the number of candidates and voters
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the candidate names
void get_candidate_names(int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }
}

// Get the voter information
void get_voter_information(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].id);
        voters[i].voted = 0;
    }
}

// Print the candidate names and votes
void print_results(int num_candidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Conduct the election
void conduct_election(int num_candidates, int num_voters) {
    int vote;
    for (int i = 0; i < num_voters; i++) {
        printf("\nVoter %d, enter your vote (1-%d): ", voters[i].id, num_candidates);
        scanf("%d", &vote);
        if (vote >= 1 && vote <= num_candidates && !voters[i].voted) {
            candidates[vote - 1].votes++;
            voters[i].voted = 1;
        } else {
            printf("Invalid vote. Please try again.\n");
            i--;
        }
    }
}

// Find the winner
int find_winner(int num_candidates) {
    int max_votes = 0;
    int winner = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }
    return winner;
}

// Print the winner
void print_winner(int winner) {
    printf("\nThe winner of the election is: %s\n", candidates[winner].name);
}

// Main function
int main() {
    int num_candidates = get_num_candidates();
    int num_voters = get_num_voters();
    get_candidate_names(num_candidates);
    get_voter_information(num_voters);
    conduct_election(num_candidates, num_voters);
    int winner = find_winner(num_candidates);
    print_results(num_candidates);
    print_winner(winner);
    return 0;
}