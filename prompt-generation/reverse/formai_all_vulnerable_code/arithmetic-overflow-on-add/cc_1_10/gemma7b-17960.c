//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the candidate list
struct candidate {
    char name[20];
    int votes;
};

// Function to add a candidate
void addCandidate(struct candidate **candidates, int *numCandidates) {
    *candidates = (struct candidate *)realloc(*candidates, (*numCandidates + 1) * sizeof(struct candidate));
    (*numCandidates)++;
    printf("Enter the candidate's name: ");
    scanf("%s", (*candidates)->name);
    (*candidates)->votes = 0;
}

// Function to vote for a candidate
void voteForCandidate(struct candidate *candidates, int numCandidates) {
    char candidateName[20];
    printf("Enter the candidate's name: ");
    scanf("%s", candidateName);

    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            candidates[i].votes++;
            printf("Vote cast for %s.\n", candidates[i].name);
            return;
        }
    }

    printf("Error: candidate not found.\n");
}

int main() {
    struct candidate *candidates = NULL;
    int numCandidates = 0;

    // Add some candidates
    addCandidate(&candidates, &numCandidates);
    addCandidate(&candidates, &numCandidates);
    addCandidate(&candidates, &numCandidates);

    // Vote for a candidate
    voteForCandidate(candidates, numCandidates);

    // Print the results
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}