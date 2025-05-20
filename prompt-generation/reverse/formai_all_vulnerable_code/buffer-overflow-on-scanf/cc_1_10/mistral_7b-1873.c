//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#define MAX_CANDIDATES 5
#define MAX_VOTES 100

// Structure to represent a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Initialize candidates with zero votes
Candidate candidates[MAX_CANDIDATES] = {{"", 0}};

void register_voter() {
    int voter_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);
    printf("\n");
}

void vote(int candidate_index) {
    candidates[candidate_index].votes++;
}

void display_candidates() {
    int i;
    printf("\nCandidates:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > 0) {
            printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    int num_candidates, i, voter_id, candidate;

    // Get number of candidates from user
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    printf("\n");

    // Initialize candidates with their names
    for (i = 0; i < num_candidates && i < MAX_CANDIDATES; i++) {
        printf("Enter candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);
        printf("\n");
    }

    // Registration of voters
    printf("\nRegistration of voters:\n");
    for (i = 0; i < MAX_VOTES; i++) {
        register_voter();
    }

    // Voting
    printf("\nVoting:\n");
    for (i = 0; i < MAX_VOTES; i++) {
        printf("Enter candidate number to vote for: ");
        scanf("%d", &candidate);
        vote(candidate-1);
    }

    // Displaying results
    printf("\nResults:\n");
    display_candidates();

    return 0;
}