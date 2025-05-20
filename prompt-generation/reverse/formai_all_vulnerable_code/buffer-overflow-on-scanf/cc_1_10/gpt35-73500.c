//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>

// defining constants for maximum candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

// function to display the menu for the voting system
void displayMenu(int numCandidates, char candidates[MAX_CANDIDATES][50]) {
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select a candidate from the following list:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
    printf("0. Quit\n");
}

int main() {
    char candidates[MAX_CANDIDATES][50];
    int numCandidates = 0;
    int votes[MAX_VOTERS];
    int numVoters = 0;
    int voteCount[MAX_CANDIDATES] = {0};
    
    // loop to add candidates to the system
    char candidateName[50];
    printf("Enter candidate name (or 'done' to finish): ");
    scanf("%s", candidateName);
    while (strcmp(candidateName, "done") != 0 && numCandidates < MAX_CANDIDATES) {
        strcpy(candidates[numCandidates], candidateName);
        numCandidates++;
        printf("Enter candidate name (or 'done' to finish): ");
        scanf("%s", candidateName);
    }
    
    // display the voting menu
    displayMenu(numCandidates, candidates);
    
    // loop to accept votes from voters
    int vote;
    printf("Please enter your vote (or 0 to quit): ");
    scanf("%d", &vote);
    while (vote != 0 && numVoters < MAX_VOTERS) {
        if (vote < 0 || vote > numCandidates) {
            printf("Invalid vote. Please try again.\n");
        } else {
            votes[numVoters] = vote;
            numVoters++;
            voteCount[vote-1]++;
        }
        displayMenu(numCandidates, candidates);
        printf("Please enter your vote (or 0 to quit): ");
        scanf("%d", &vote);
    }
    
    // display the results
    printf("Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i], voteCount[i]);
    }
    
    return 0;
}