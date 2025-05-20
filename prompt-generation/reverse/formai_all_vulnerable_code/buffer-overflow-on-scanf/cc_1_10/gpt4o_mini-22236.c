//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50

// Structure to hold candidate details
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// Function prototypes
void initializeCandidates(Candidate candidates[], int numCandidates);
void castVote(Candidate candidates[], int numCandidates);
void displayResults(Candidate candidates[], int numCandidates);
int isValidChoice(int choice, int numCandidates);

int main() {
    int numCandidates;
    Candidate candidates[MAX_CANDIDATES];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates (max 5): ");
    scanf("%d", &numCandidates);

    // Validate number of candidates
    if (numCandidates <= 0 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates! Exiting...\n");
        return 1;
    }

    // Initialize candidates
    initializeCandidates(candidates, numCandidates);

    char continueVoting;
    do {
        castVote(candidates, numCandidates);
        printf("Do you want to cast another vote? (y/n): ");
        getchar(); // clear newline from input buffer
        scanf("%c", &continueVoting);
    } while (continueVoting == 'y' || continueVoting == 'Y');

    // Display the results of the voting
    displayResults(candidates, numCandidates);

    return 0;
}

// Function to initialize candidates
void initializeCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        getchar(); // clear newline from input buffer
        fgets(candidates[i].name, MAX_NAME_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // remove newline
        candidates[i].votes = 0; // initialize votes to 0
    }
}

// Function to cast a vote
void castVote(Candidate candidates[], int numCandidates) {
    int choice;
    printf("\nPlease cast your vote:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &choice);

    if (isValidChoice(choice, numCandidates)) {
        candidates[choice - 1].votes++;
        printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice! Vote not recorded.\n");
    }
}

// Function to display voting results
void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("The winner is %s with %d votes!\n", candidates[winnerIndex].name, maxVotes);
    } else {
        printf("No votes were cast.\n");
    }
}

// Function to validate the user's choice
int isValidChoice(int choice, int numCandidates) {
    return (choice > 0 && choice <= numCandidates);
}