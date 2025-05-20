//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a voter
typedef struct voter {
    char name[20];
    int vote;
} voter;

// Function to read voter information
void readVoter(voter *v) {
    printf("Enter your name: ");
    scanf("%s", v->name);
    printf("Enter your vote (1/2/3): ");
    scanf("%d", &v->vote);
}

// Function to validate voter vote
int validateVote(int vote) {
    if (vote < 1 || vote > 3) {
        return 0;
    } else {
        return 1;
    }
}

// Function to tally votes
void tallyVotes(voter *v, int *totalVotes) {
    totalVotes[v->vote]++;
}

// Main function
int main() {
    // Create an array of voters
    voter *v = malloc(10 * sizeof(voter));

    // Read voter information
    for (int i = 0; i < 10; i++) {
        readVoter(&v[i]);
    }

    // Validate voter votes
    for (int i = 0; i < 10; i++) {
        if (!validateVote(v[i].vote)) {
            printf("Error: Invalid vote.\n");
        }
    }

    // Tally votes
    int totalVotes[3] = {0};
    for (int i = 0; i < 10; i++) {
        tallyVotes(&v[i], totalVotes);
    }

    // Print vote results
    printf("Vote results:\n");
    for (int i = 0; i < 3; i++) {
        printf("Candidate %d: %d votes\n", i + 1, totalVotes[i]);
    }

    // Free memory
    free(v);

    return 0;
}