//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Global variables for tracking number of votes
int votesA = 0;
int votesB = 0;
int votesC = 0;
int votesD = 0;

// Function to display voting options and collect input
void vote() {
    int choice;
    printf("\n\nVoting options:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");
    printf("4. Candidate D\n");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            votesA++;
            break;
        case 2:
            votesB++;
            break;
        case 3:
            votesC++;
            break;
        case 4:
            votesD++;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

// Function to display the results of the vote
void results() {
    printf("\n\nResults:\n");
    printf("Candidate A: %d votes\n", votesA);
    printf("Candidate B: %d votes\n", votesB);
    printf("Candidate C: %d votes\n", votesC);
    printf("Candidate D: %d votes\n", votesD);
    if (votesA > votesB && votesA > votesC && votesA > votesD) {
        printf("Candidate A wins!\n");
    } else if (votesB > votesA && votesB > votesC && votesB > votesD) {
        printf("Candidate B wins!\n");
    } else if (votesC > votesA && votesC > votesB && votesC > votesD) {
        printf("Candidate C wins!\n");
    } else if (votesD > votesA && votesD > votesB && votesD > votesC) {
        printf("Candidate D wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int numVoters;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    for (int i = 1; i <= numVoters; i++) {
        printf("\n\nVote #%d\n", i);
        vote();
    }
    results();
    return 0;
}