//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for candidate details
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to initialize candidates with zero votes
void init_candidates(Candidate *candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        strcpy(candidates[i].name, "");
        candidates[i].votes = 0;
    }
}

// Function to display candidates and their votes
void display_candidates(Candidate *candidates, int num_candidates) {
    printf("\n------ VOTING RESULTS ------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

// Function to get candidate index based on user input
int get_candidate_index(Candidate *candidates, int num_candidates) {
    int input;
    do {
        printf("\nEnter the number of your preferred candidate (1 to %d): ", num_candidates);
        scanf("%d", &input);
    } while (input < 1 || input > num_candidates);

    return input - 1;
}

// Function to handle voting process
void vote(Candidate *candidates, int *num_votes, int num_candidates) {
    int candidate_index;

    // Get candidate index from user input
    candidate_index = get_candidate_index(candidates, num_candidates);

    // Increment votes for the selected candidate
    candidates[candidate_index].votes++;

    // Increment total number of votes
    (*num_votes)++;
}

int main() {
    int num_candidates, num_votes;
    Candidate candidates[100]; // Assuming maximum 100 candidates

    // Initialize candidates with zero votes
    init_candidates(candidates, 5); // Assume 5 candidates in this example

    // Initialize total number of votes
    num_votes = 0;

    printf("\n------ ELECTRONIC VOTING SYSTEM ------\n");

    // Voting process
    while (num_votes < 100) { // Assuming 100 maximum votes in this example
        vote(candidates, &num_votes, 5);
    }

    // Display final voting results
    printf("\n------ VOTING PROCESS COMPLETED ------\n");
    display_candidates(candidates, 5);

    return 0;
}