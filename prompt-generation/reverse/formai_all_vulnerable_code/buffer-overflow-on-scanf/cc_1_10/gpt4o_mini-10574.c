//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to display the candidate options
void displayCandidates() {
    printf("Candidates:\n");
    printf("1. Alice\n");
    printf("2. Bob\n");
    printf("3. Charlie\n");
}

// Function to cast a vote
int castVote() {
    int vote;
    printf("Enter your vote (1-3): ");
    scanf("%d", &vote);
    return vote;
}

// Function to tally votes
void tallyVotes(int votes[], int totalVotes) {
    printf("\nVote Tally:\n");
    printf("Alice: %d\n", votes[0]);
    printf("Bob: %d\n", votes[1]);
    printf("Charlie: %d\n", votes[2]);

    if (votes[0] > votes[1] && votes[0] > votes[2]) {
        printf("Winner: Alice\n");
    } else if (votes[1] > votes[0] && votes[1] > votes[2]) {
        printf("Winner: Bob\n");
    } else if (votes[2] > votes[0] && votes[2] > votes[1]) {
        printf("Winner: Charlie\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int totalVotes = 0;
    int numVoters, candidateVote;
    
    printf("Welcome to the Electronic Voting System\n");
    printf("How many voters are participating? ");
    scanf("%d", &numVoters);

    // Array to hold vote counts for each candidate
    int votes[3] = {0, 0, 0};

    for (int i = 0; i < numVoters; i++) {
        displayCandidates();
        candidateVote = castVote();

        // Validate vote
        while (candidateVote < 1 || candidateVote > 3) {
            printf("Invalid vote. Please try again.\n");
            candidateVote = castVote();
        }

        // Increment the vote for the appropriate candidate
        votes[candidateVote - 1]++;
        totalVotes++;
        printf("Thank you for voting!\n\n");
    }

    // Display the results
    tallyVotes(votes, totalVotes);

    return 0;
}