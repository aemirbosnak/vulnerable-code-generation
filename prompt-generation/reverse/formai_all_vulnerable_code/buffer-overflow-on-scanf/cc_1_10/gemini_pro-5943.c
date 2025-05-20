//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate details
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Function to compare two candidates based on their votes
int compareCandidates(const void *a, const void *b) {
    candidate *c1 = (candidate *)a;
    candidate *c2 = (candidate *)b;
    return c2->votes - c1->votes;
}

// Function to print the results of the election
void printResults(candidate *candidates, int numCandidates) {
    // Sort the candidates in descending order of votes
    qsort(candidates, numCandidates, sizeof(candidate), compareCandidates);

    // Print the results
    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s: %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Get the number of candidates
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Allocate memory for the candidates
    candidate *candidates = malloc(sizeof(candidate) * numCandidates);

    // Get the details of each candidate
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get the votes for each candidate
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the number of votes for candidate %s: ", candidates[i].name);
        scanf("%d", &candidates[i].votes);
    }

    // Print the results of the election
    printResults(candidates, numCandidates);

    // Free the memory allocated for the candidates
    free(candidates);

    return 0;
}