//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to cast a vote
void vote(int candidateNumber, int* candidateVotes, int numOfCandidates) {
    if(candidateNumber > 0 && candidateNumber <= numOfCandidates) {
        candidateVotes[candidateNumber-1]++;
        printf("Thank you for casting your vote!\n\n");
    } else {
        printf("Invalid candidate number. Please try again.\n\n");
    }
}

// Function to display the winner
void displayWinner(int* candidateVotes, int numOfCandidates) {
    int maxVotes = 0, maxIndex = 0;
    for(int i=0; i<numOfCandidates; i++) {
        if(candidateVotes[i] > maxVotes) {
            maxVotes = candidateVotes[i];
            maxIndex = i;
        }
    }
    printf("The winner is candidate %d with %d votes!\n", maxIndex+1, maxVotes);
}

int main() {
    int numOfCandidates, numOfVoters, voterID, candidateNumber;
    printf("Welcome to the Electronic Voting System!\n\n");

    // Ask for the number of candidates
    printf("Please enter the number of candidates: ");
    scanf("%d", &numOfCandidates);
    int candidateVotes[numOfCandidates];
    for(int i=0; i<numOfCandidates; i++) {
        candidateVotes[i] = 0; // Initialize vote count to 0 for all candidates
    }

    // Ask for the number of voters
    printf("Please enter the number of voters: ");
    scanf("%d", &numOfVoters);

    // Start taking votes
    for(int i=0; i<numOfVoters; i++) {
        printf("Voter #%d, please enter your voter ID: ", i+1);
        scanf("%d", &voterID);
        printf("\n");
        printf("Welcome voter %d! Please select your candidate: \n", voterID);
        for(int j=0; j<numOfCandidates; j++) {
            printf("Candidate %d\n", j+1);
        }
        printf("Please enter the candidate number: ");
        scanf("%d", &candidateNumber);
        vote(candidateNumber, candidateVotes, numOfCandidates);
    }

    // Display the winner
    printf("\n\nThank you for voting!\n\n");
    displayWinner(candidateVotes, numOfCandidates);
    return 0;
}