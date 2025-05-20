//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare candidates based on votes
int compareCandidates(const void *a, const void *b) {
    candidate *c1 = (candidate *)a;
    candidate *c2 = (candidate *)b;
    return c2->votes - c1->votes;
}

// Function to print the results of the election
void printResults(candidate *candidates, int numCandidates) {
    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("---------------------\n");
}

int main() {
    // Initialize the candidates
    candidate candidates[] = {
        {"John Smith", 0},
        {"Jane Doe", 0},
        {"Bob Johnson", 0}
    };
    int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

    // Get the number of voters
    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Get the votes for each candidate
    for (int i = 0; i < numVoters; i++) {
        int vote;
        printf("Enter your vote (1 for John Smith, 2 for Jane Doe, 3 for Bob Johnson): ");
        scanf("%d", &vote);
        candidates[vote - 1].votes++;
    }

    // Sort the candidates based on votes
    qsort(candidates, numCandidates, sizeof(candidate), compareCandidates);

    // Print the results of the election
    printResults(candidates, numCandidates);

    return 0;
}