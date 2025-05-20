//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: visionary
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
    int candidate_id;
} Voter;

// Define the function to print the results of the election
void print_results(Candidate *candidates, int num_candidates) {
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Define the function to run the election
void run_election(Candidate *candidates, int num_candidates, Voter *voters, int num_voters) {
    // Initialize the votes for each candidate to 0
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }

    // Loop through each voter and cast their vote
    for (int i = 0; i < num_voters; i++) {
        // Get the candidate ID for the voter's vote
        int candidate_id = voters[i].candidate_id;

        // Increment the vote count for the selected candidate
        candidates[candidate_id].votes++;
    }

    // Print the results of the election
    print_results(candidates, num_candidates);
}

// Define the main function
int main() {
    // Declare the arrays to store the candidates and voters
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Get the number of candidates and voters
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get the names of the candidates
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    // Get the names of the voters and their candidate IDs
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);

        printf("Enter the ID of the candidate that voter %s is voting for: ", voters[i].name);
        scanf("%d", &voters[i].candidate_id);
    }

    // Run the election
    run_election(candidates, num_candidates, voters, num_voters);

    return 0;
}