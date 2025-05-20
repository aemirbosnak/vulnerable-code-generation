//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function for counting votes
int countVotes(int candidate, int *votes, int numVotes) {
    int count = 0;
    for (int i = 0; i < numVotes; i++) {
        if (votes[i] == candidate) {
            count++;
        }
    }
    return count;
}

// Function for displaying voting results
void displayResults(int *votes, int numVotes, int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s: %d votes\n", i+1, (char *)i, countVotes(i, votes, numVotes));
    }
}

// Function for getting candidate names from user input
void getCandidates(char *candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d name: ", i+1);
        scanf("%s", candidates[i]);
    }
}

// Function for getting votes from user input
void getVotes(int *votes, int numVotes) {
    for (int i = 0; i < numVotes; i++) {
        printf("Enter vote %d: ", i+1);
        scanf("%d", &votes[i]);
    }
}

// Function for main voting process
void vote(char *candidates[], int numCandidates, int *votes, int numVotes) {
    printf("\nVoting for %d candidates:\n", numCandidates);
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
    printf("\nEnter your votes:\n");
    getVotes(votes, numVotes);
    printf("\nYour votes have been cast.\n");
}

// Main function for electronic voting system
int main() {
    int numCandidates, numVotes;
    printf("\nEnter number of candidates: ");
    scanf("%d", &numCandidates);
    char *candidates[numCandidates];
    getCandidates(candidates, numCandidates);
    printf("\nEnter number of votes: ");
    scanf("%d", &numVotes);
    int votes[numVotes];
    vote(candidates, numCandidates, votes, numVotes);
    displayResults(votes, numVotes, numCandidates);
    return 0;
}