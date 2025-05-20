//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to initialize candidates
void initCandidates(candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Function to cast a vote
void castVote(candidate candidates[], int numCandidates) {
    int choice;
    printf("\nEnter your choice (1-%d): ", numCandidates);
    scanf("%d", &choice);
    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice. Please enter a number between 1 and %d.\n", numCandidates);
    } else {
        candidates[choice - 1].votes++;
    }
}

// Function to print the results
void printResults(candidate candidates[], int numCandidates) {
    printf("\nResults:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Initialize candidates
    const int NUM_CANDIDATES = 3;
    candidate candidates[NUM_CANDIDATES];
    initCandidates(candidates, NUM_CANDIDATES);

    // Cast votes
    int numVoters;
    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);
    for (int i = 0; i < numVoters; i++) {
        castVote(candidates, NUM_CANDIDATES);
    }

    // Print the results
    printResults(candidates, NUM_CANDIDATES);

    return 0;
}