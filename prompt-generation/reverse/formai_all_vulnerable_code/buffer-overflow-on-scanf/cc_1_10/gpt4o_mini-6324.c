//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int numCandidates;

void clearVotes() {
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0;
    }
}

void castVote() {
    int choice, isValid;

    printf("\nVoting Menu:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Choose a candidate by number (0 to cancel): ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("Voting cancelled.\n");
        return;
    }

    isValid = (choice > 0 && choice <= numCandidates);
    if (isValid) {
        candidates[choice - 1].votes++;
        printf("Vote cast for %s!\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice. Try again.\n");
    }

    // Recursively call castVote for another round
    castVote();
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void enterCandidates() {
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);
    if (numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Setting to 1.\n");
        numCandidates = 1;
    }

    for (int i = 0; i < numCandidates; i++) {
        printf("Enter name for candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to 0
    }
}

void startVotingProcess() {
    printf("Welcome to the Electronic Voting System!\n");
    enterCandidates();
    
    // Clear votes in case of restart
    clearVotes(); 

    // Start the voting
    castVote();

    // Display results after voting ends
    displayResults();
}

int main() {
    startVotingProcess();
    return 0;
}