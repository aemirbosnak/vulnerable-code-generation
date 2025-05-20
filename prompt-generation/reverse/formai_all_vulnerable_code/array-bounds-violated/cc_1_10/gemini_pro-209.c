//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structure
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// Function to compare two candidates based on votes
int compareCandidates(const void *a, const void *b) {
    Candidate *c1 = (Candidate *)a;
    Candidate *c2 = (Candidate *)b;
    return c2->votes - c1->votes;
}

// Main function
int main() {
    // Initialize candidates
    Candidate candidates[5] = {
        {"John Smith", 0},
        {"Jane Doe", 0},
        {"Bill Jones", 0},
        {"Mary Johnson", 0},
        {"Tom Brown", 0}
    };

    // Get the number of voters
    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Get the votes for each candidate
    for (int i = 0; i < numVoters; i++) {
        int vote;
        printf("Enter the vote for candidate %d: ", i + 1);
        scanf("%d", &vote);
        candidates[vote - 1].votes++;
    }

    // Sort the candidates based on votes
    qsort(candidates, 5, sizeof(Candidate), compareCandidates);

    // Print the results
    printf("Election results:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s: %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    Candidate winner = candidates[0];
    for (int i = 1; i < 5; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }

    // Print the winner
    printf("The winner is %s with %d votes.\n", winner.name, winner.votes);

    return 0;
}