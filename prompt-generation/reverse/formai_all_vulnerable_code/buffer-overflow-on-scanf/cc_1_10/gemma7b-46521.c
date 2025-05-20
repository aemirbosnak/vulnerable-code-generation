//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the number of voters
#define NUM_VOTERS 10

// Define the number of candidates
#define NUM_CANDIDATES 3

// Define the structure of a voter
typedef struct Voter {
    char name[20];
    int vote;
} Voter;

// Define the structure of a candidate
typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

// Create an array of voters
Voter voters[NUM_VOTERS];

// Create an array of candidates
Candidate candidates[NUM_CANDIDATES];

// Function to read the votes of a voter
void read_votes(Voter *voter) {
    printf("Enter your vote for candidate 1-3: ");
    scanf("%d", &voter->vote);
}

// Function to add the votes of a voter
void add_votes(Voter *voter) {
    candidates[voter->vote - 1].votes++;
}

// Function to print the results of the election
void print_results() {
    printf("The results of the election are:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize the voters and candidates
    for (int i = 0; i < NUM_VOTERS; i++) {
        voters[i].name[0] = '\0';
        voters[i].vote = 0;
    }

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Read the votes of each voter
    for (int i = 0; i < NUM_VOTERS; i++) {
        read_votes(&voters[i]);
        add_votes(&voters[i]);
    }

    // Print the results of the election
    print_results();

    return 0;
}