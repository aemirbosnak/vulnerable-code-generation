//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

// Function prototypes
void printMainMenu();
void printCandidatesMenu(int, char[MAX_CANDIDATES][50]);
void printResults(int[MAX_CANDIDATES], int, char[MAX_CANDIDATES][50]);

int main() {
    // Initialize variables
    int numVoters;
    int numCandidates;
    char candidateNames[MAX_CANDIDATES][50];
    int candidateVotes[MAX_CANDIDATES] = {0};

    // Get input from user
    printf("Welcome to the Electronic Voting System!\n\n");
    printf("How many voters are there? (max %d)\n", MAX_VOTERS);
    scanf("%d", &numVoters);

    if (numVoters > MAX_VOTERS) {
        printf("Error: Maximum number of voters exceeded.\n");
        return 0;
    }

    printf("\nHow many candidates are there? (max %d)\n", MAX_CANDIDATES);
    scanf("%d", &numCandidates);

    if (numCandidates > MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates exceeded.\n");
        return 0;
    }
    
    printf("\nEnter the name of each candidate:\n");

    for (int i = 0; i < numCandidates; i++) {
        scanf("%s", candidateNames[i]);
    }

    // Start voting process
    printf("\nVoting has started!\n");
    for (int i = 1; i <= numVoters; i++) {
        printf("\nVoter %d, please select a candidate:\n", i);
        printCandidatesMenu(numCandidates, candidateNames);
        int voteChoice;
        scanf("%d", &voteChoice);

        if (voteChoice > numCandidates || voteChoice < 1) {
            printf("\nInvalid input.\n");
            i--;
        }
        else {
            candidateVotes[voteChoice - 1]++;
            printf("\nThank you for voting for %s.\n", candidateNames[voteChoice - 1]);
        }   
    }

    // Print results
    printResults(candidateVotes, numCandidates, candidateNames);

    return 0;
}

void printMainMenu() {
    printf("\n1. View Candidates\n");
    printf("2. Vote\n");
    printf("3. Exit\n");
}

void printCandidatesMenu(int numCandidates, char candidateNames[MAX_CANDIDATES][50]) {
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidateNames[i]);
    }
}

void printResults(int candidateVotes[MAX_CANDIDATES], int numCandidates, char candidateNames[MAX_CANDIDATES][50]) {
    printf("\n--- Results ---\n");

    int winnerIndex = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (candidateVotes[i] > candidateVotes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    printf("\nWinner: %s\n\n", candidateNames[winnerIndex]);

    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidateNames[i], candidateVotes[i]);
    }
}