//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the data structures for the candidates and voters
typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int voted;
} Voter;

// Declare the arrays to store the candidates and voters
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

// Get the number of candidates and voters
int get_num_candidates() {
    int num_candidates;
    printf("How many candidates are running? ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

int get_num_voters() {
    int num_voters;
    printf("How many voters are there? ");
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

// Get the voter names
void get_voter_names(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
    }
}

// Conduct the voting
void conduct_voting(int num_candidates, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s, please cast your vote: ", voters[i].name);
        int candidate_index;
        scanf("%d", &candidate_index);
        candidates[candidate_index - 1].votes++;
        voters[i].voted = 1;
    }
}

// Print the results
void print_results(int num_candidates) {
    printf("\nThe results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Declare the main function
int main() {
    // Get the number of candidates and voters
    int num_candidates = get_num_candidates();
    int num_voters = get_num_voters();

    // Get the candidate names
    get_candidate_names(num_candidates);

    // Get the voter names
    get_voter_names(num_voters);

    // Conduct the voting
    conduct_voting(num_candidates, num_voters);

    // Print the results
    print_results(num_candidates);

    return 0;
}