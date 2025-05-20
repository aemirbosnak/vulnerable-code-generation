//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define NAME_LENGTH 50

// Struct to hold candidate information
typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

// Function to display the candidates
void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to cast a vote
void castVote(Candidate candidates[], int numCandidates) {
    int choice;
    printf("Enter the candidate number to vote (1-%d): ", numCandidates);
    while (1) {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= numCandidates) {
            candidates[choice - 1].votes++;
            printf("Vote cast for %s!\n", candidates[choice - 1].name);
            break;
        } else {
            printf("Invalid choice. Please enter a number between 1 and %d: ", numCandidates);
        }
    }
}

// Function to display results
void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to find the winner
void findWinner(Candidate candidates[], int numCandidates) {
    int maxVotes = -1;
    int winnerIndex = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }
    if (winnerIndex != -1) {
        printf("The winner is: %s with %d votes!\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
    } else {
        printf("No votes were cast.\n");
    }
}

// Main function
int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates;
    int totalVotes = 0;

    printf("Welcome to the Electronic Voting System!\n");
    
    // Get the number of candidates
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);
    if (numCandidates > MAX_CANDIDATES || numCandidates < 1) {
        printf("Invalid number of candidates. Exiting...\n");
        return 1;
    }

    // Input the candidates' names
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes
    }

    // Voting process
    while (totalVotes < MAX_VOTERS) {
        printf("\nTotal Votes Cast: %d/%d\n", totalVotes, MAX_VOTERS);
        displayCandidates(candidates, numCandidates);
        castVote(candidates, numCandidates);
        totalVotes++;

        char continueVoting;
        printf("Do you want to continue voting? (y/n): ");
        scanf(" %c", &continueVoting);
        if (continueVoting != 'y') {
            break;
        }
    }

    displayResults(candidates, numCandidates);
    findWinner(candidates, numCandidates);

    return 0;
}