//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to start the voting process
void startVoting();

// Function to record votes
void recordVote(int candidateNum);

// Function to display vote count
void displayVoteCount();

// Candidate struct
struct Candidate {
    char name[50];
    int voteCount;
};

// Array of candidates
struct Candidate candidates[10];

// Total number of candidates
int numCandidates;

// Flag variable to check if voting has started
int votingStarted = 0;

int main() {
    // Initialize candidates
    strcpy(candidates[0].name, "John Doe");
    strcpy(candidates[1].name, "Jane Smith");
    numCandidates = 2;

    // Start voting process
    startVoting();

    return 0;
}

// Function to start the voting process
void startVoting() {
    char choice;

    printf("\nWelcome to the Electronic Voting System!\n");

    // Prompt user to start voting
    printf("\nTo start voting, enter 's': ");
    scanf(" %c", &choice);

    // Check if user entered 's' to start voting
    if (choice == 's') {
        printf("\nVoting has begun!\n");
        printf("\nCandidates:\n");

        // Display list of candidates
        for (int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", (i+1), candidates[i].name);
        }

        // Set flag variable to indicate that voting has started
        votingStarted = 1;

        // Prompt user to enter vote
        printf("\nEnter candidate number to vote (1-%d): ", numCandidates);
        scanf("%d", &choice);

        // Record vote
        recordVote(choice);
    } else {
        printf("\nInvalid choice!");
    }
}

// Function to record votes
void recordVote(int candidateNum) {
    // Check if voting has started
    if (votingStarted) {
        // Check if candidate number is valid
        if (candidateNum >= 1 && candidateNum <= numCandidates) {
            candidates[candidateNum-1].voteCount++;
            printf("\nVote recorded for %s!\n", candidates[candidateNum-1].name);

            // Prompt user to enter another vote
            printf("\nEnter candidate number to vote (1-%d): ", numCandidates);
            scanf("%d", &candidateNum);

            // Record vote
            recordVote(candidateNum);
        } else {
            printf("\nInvalid candidate number!");
        }
    } else {
        printf("\nVoting has not started yet!");
    }
}

// Function to display vote count
void displayVoteCount() {
    // Check if voting has started
    if (votingStarted) {
        printf("\nVote count:\n");

        for (int i = 0; i < numCandidates; i++) {
            printf("%s: %d\n", candidates[i].name, candidates[i].voteCount);
        }
    } else {
        printf("\nVoting has not started yet!");
    }
}