//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of candidates and voters
#define NUM_CANDIDATES 3
#define NUM_VOTERS 10

// Define the candidate names and their IDs
char *candidateNames[NUM_CANDIDATES] = {"Sir William", "Lady Elizabeth", "Lord Henry"};
int candidateIDs[NUM_CANDIDATES] = {1, 2, 3};

// Define the voter IDs
int voterIDs[NUM_VOTERS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Define the voting results
int results[NUM_CANDIDATES] = {0, 0, 0};

// Function prototypes
void initializeVotes();
void castVote(int voterID);
void displayResults();

int main() {
    srand(time(NULL));
    initializeVotes();
    for (int i = 0; i < NUM_VOTERS; i++) {
        castVote(voterIDs[i]);
    }
    displayResults();
    return 0;
}

// Initialize the votes to 0
void initializeVotes() {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        results[i] = 0;
    }
}

// Cast a vote for a candidate
void castVote(int voterID) {
    int candidateID;
    printf("Enter the candidate ID for whom you wish to cast your vote: ");
    scanf("%d", &candidateID);
    if (candidateID >= 1 && candidateID <= NUM_CANDIDATES) {
        results[candidateID - 1]++;
        printf("Your vote has been cast for %s.\n", candidateNames[candidateID - 1]);
    } else {
        printf("Invalid candidate ID.\n");
    }
}

// Display the voting results
void displayResults() {
    printf("\n\nVoting results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidateNames[i], results[i]);
    }
}