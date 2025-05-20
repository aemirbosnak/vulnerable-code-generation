//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
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
    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Define the candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    // Get the number of candidates
    int numCandidates = sizeof(candidates) / sizeof(candidate);

    // Get the number of votes
    int numVotes;
    printf("Enter the number of votes: ");
    scanf("%d", &numVotes);

    // Get the votes for each candidate
    for (int i = 0; i < numVotes; i++) {
        char name[50];
        printf("Enter the name of the candidate to vote for: ");
        scanf("%s", name);

        // Find the candidate in the array
        int found = 0;
        for (int j = 0; j < numCandidates; j++) {
            if (strcmp(name, candidates[j].name) == 0) {
                // Increment the candidate's votes
                candidates[j].votes++;
                found = 1;
                break;
            }
        }

        // If the candidate was not found, print an error message
        if (!found) {
            printf("Invalid candidate name.\n");
        }
    }

    // Sort the candidates based on their votes
    qsort(candidates, numCandidates, sizeof(candidate), compareCandidates);

    // Print the results of the election
    printResults(candidates, numCandidates);

    return 0;
}