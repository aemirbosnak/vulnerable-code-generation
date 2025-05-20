//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of voters
#define NUM_VOTERS 100

// Define the structure of a voter
typedef struct Voter {
    char name[50];
    int vote;
} Voter;

// Create an array of voters
Voter voters[NUM_VOTERS];

// Function to read voter information
void readVoterInfo(int i) {
    printf("Enter the name of voter %d: ", i);
    scanf("%s", voters[i].name);

    printf("Enter the vote of voter %d: ", i);
    scanf("%d", &voters[i].vote);
}

// Function to vote
void vote(int voterId) {
    // Check if the voter has already voted
    if (voters[voterId].vote != -1) {
        printf("Error: voter has already voted.\n");
        return;
    }

    // Get the voter's vote
    printf("Enter your vote: ");
    scanf("%d", &voters[voterId].vote);

    // Mark the voter as having voted
    voters[voterId].vote = -1;
}

// Function to display the results
void displayResults() {
    int totalVotes = 0;
    for (int i = 0; i < NUM_VOTERS; i++) {
        if (voters[i].vote != -1) {
            totalVotes++;
        }
    }

    printf("Total number of votes: %d\n", totalVotes);

    for (int i = 0; i < NUM_VOTERS; i++) {
        if (voters[i].vote != -1) {
            printf("%s voted for %d\n", voters[i].name, voters[i].vote);
        }
    }
}

int main() {
    // Initialize the voters
    for (int i = 0; i < NUM_VOTERS; i++) {
        voters[i].vote = -1;
    }

    // Read voter information
    for (int i = 0; i < NUM_VOTERS; i++) {
        readVoterInfo(i);
    }

    // Vote
    vote(0);

    // Display the results
    displayResults();

    return 0;
}