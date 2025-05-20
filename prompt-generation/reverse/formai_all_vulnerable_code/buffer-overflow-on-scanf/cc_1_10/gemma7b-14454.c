//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the number of voters
#define NUM_VOTERS 100

// Define the candidate options
#define NUM_CANDIDATES 5

// Create an array of voters
struct voter {
    char name[20];
    int vote;
    int hasVoted;
};

// Create an array of candidates
struct candidate {
    char name[20];
    int votes;
};

// Function to read voter information
void readVoterInfo(struct voter *v) {
    printf("Enter your name: ");
    scanf("%s", v->name);

    printf("Enter your vote (1-5): ");
    scanf("%d", &v->vote);

    v->hasVoted = 1;
}

// Function to update candidate votes
void updateCandidateVotes(struct candidate *c, int vote) {
    c->votes++;
}

// Function to display election results
void displayResults(struct candidate *c) {
    printf("Election Results:\n");

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", c[i].name, c[i].votes);
    }

    printf("Winner: %s\n", c[0].name);
}

int main() {
    // Create an array of voters
    struct voter voters[NUM_VOTERS];

    // Create an array of candidates
    struct candidate candidates[NUM_CANDIDATES];

    // Read voter information
    for (int i = 0; i < NUM_VOTERS; i++) {
        readVoterInfo(&voters[i]);
    }

    // Update candidate votes
    for (int i = 0; i < NUM_VOTERS; i++) {
        updateCandidateVotes(&candidates[voters[i].vote - 1], voters[i].vote);
    }

    // Display election results
    displayResults(candidates);

    return 0;
}