//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to hold candidate details
struct Candidate {
    char name[100];
    int votes;
};

// Function to initialize the candidate structure
void initCandidate(struct Candidate *candidate) {
    srand(time(NULL));
    candidate->votes = 0;
    sprintf(candidate->name, "%s", "Candidate %d");
}

// Function to cast a vote for a candidate
void vote(struct Candidate *candidates, int numCandidates) {
    int candidateIndex;
    int choice;

    // Ask for user input
    printf("Enter the index of the candidate you want to vote for: ");
    scanf("%d", &candidateIndex);

    // Validate input
    if (candidateIndex < 0 || candidateIndex >= numCandidates) {
        printf("Invalid index, please try again.\n");
        return;
    }

    // Increment candidate votes
    candidates[candidateIndex].votes++;
    printf("Vote cast successfully!\n");
}

// Function to display candidate results
void displayResults(struct Candidate candidates[100]) {
    int i, totalVotes = 0;

    // Count total votes
    for (i = 0; i < 100; i++) {
        totalVotes += candidates[i].votes;
    }

    // Print results
    printf("\nResults:\n");
    for (i = 0; i < 100; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("Total Votes: %d\n", totalVotes);
}

int main() {
    struct Candidate candidates[100];
    int numCandidates;

    // Get number of candidates
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);

    // Initialize candidates
    for (int i = 0; i < numCandidates; i++) {
        initCandidate(&candidates[i]);
    }

    // Start voting
    printf("\nElection is now open!\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Vote for candidate %s: ", candidates[i].name);
        vote(candidates, numCandidates);
    }

    // End voting
    printf("\nElection has ended!\n");

    // Display results
    displayResults(candidates);

    return 0;
}