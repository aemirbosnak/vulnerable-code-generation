//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The structure of a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// The structure of a voter
typedef struct voter {
    char id[50];
    int hasVoted;
} voter;

// The main function
int main() {
    // Initialize the candidates
    candidate candidates[3] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Bill Smith", 0}
    };

    // Initialize the voters
    voter voters[5] = {
        {"12345", 0},
        {"23456", 0},
        {"34567", 0},
        {"45678", 0},
        {"56789", 0}
    };

    // Get the number of candidates
    int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

    // Get the number of voters
    int numVoters = sizeof(voters) / sizeof(voters[0]);

    // Run the election
    while (1) {
        // Get the voter's ID
        printf("Enter your voter ID: ");
        char id[50];
        scanf("%s", id);

        // Find the voter in the list of voters
        int voterIndex = -1;
        for (int i = 0; i < numVoters; i++) {
            if (strcmp(voters[i].id, id) == 0) {
                voterIndex = i;
                break;
            }
        }

        // If the voter was not found, then they are not eligible to vote
        if (voterIndex == -1) {
            printf("Invalid voter ID\n");
            continue;
        }

        // If the voter has already voted, then they cannot vote again
        if (voters[voterIndex].hasVoted) {
            printf("You have already voted\n");
            continue;
        }

        // Get the candidate that the voter wants to vote for
        printf("Enter the name of the candidate you want to vote for: ");
        char name[50];
        scanf("%s", name);

        // Find the candidate in the list of candidates
        int candidateIndex = -1;
        for (int i = 0; i < numCandidates; i++) {
            if (strcmp(candidates[i].name, name) == 0) {
                candidateIndex = i;
                break;
            }
        }

        // If the candidate was not found, then the voter cannot vote for them
        if (candidateIndex == -1) {
            printf("Invalid candidate name\n");
            continue;
        }

        // Increment the vote count for the candidate
        candidates[candidateIndex].votes++;

        // Set the voter's hasVoted flag to true
        voters[voterIndex].hasVoted = 1;

        // Print the current vote totals
        for (int i = 0; i < numCandidates; i++) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }

        // Ask the voter if they want to continue voting
        printf("Do you want to continue voting? (y/n) ");
        char choice;
        scanf(" %c", &choice);

        // If the voter does not want to continue voting, then exit the loop
        if (choice == 'n') {
            break;
        }
    }

    // Find the winner of the election
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    // Print the winner of the election
    printf("The winner of the election is %s with %d votes\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);

    return 0;
}