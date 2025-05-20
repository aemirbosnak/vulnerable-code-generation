//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the maximum number of votes for each candidate
#define MAX_CANDIDATES 5

// Define the structure of a voter
typedef struct Voter {
    char name[50];
    int vote;
    int hasVoted;
} Voter;

// Define the structure of a candidate
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// Create an array of voters
Voter voters[MAX_VOTERS];

// Create an array of candidates
Candidate candidates[MAX_CANDIDATES];

// Function to add a voter
void addVoter() {
    // Get the voter's name
    printf("Enter your name: ");
    scanf("%s", voters[MAX_VOTERS - 1].name);

    // Set the voter's vote
    printf("Enter your vote for candidate number: ");
    scanf("%d", &voters[MAX_VOTERS - 1].vote);

    // Set the voter's hasVoted flag to true
    voters[MAX_VOTERS - 1].hasVoted = 1;
}

// Function to add a candidate
void addCandidate() {
    // Get the candidate's name
    printf("Enter the candidate's name: ");
    scanf("%s", candidates[MAX_CANDIDATES - 1].name);

    // Set the candidate's votes to 0
    candidates[MAX_CANDIDATES - 1].votes = 0;
}

// Function to vote
void vote() {
    // Check if the voter has already voted
    if (voters[MAX_VOTERS - 1].hasVoted) {
        printf("You have already voted.\n");
    } else {
        // Get the voter's vote
        printf("Enter your vote for candidate number: ");
        scanf("%d", &voters[MAX_VOTERS - 1].vote);

        // Set the voter's hasVoted flag to true
        voters[MAX_VOTERS - 1].hasVoted = 1;

        // Increment the candidate's votes
        candidates[voters[MAX_VOTERS - 1].vote - 1].votes++;
    }
}

// Function to display the results
void displayResults() {
    // Print the candidate names
    printf("Candidate names:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s\n", candidates[i].name);
    }

    // Print the candidate votes
    printf("Candidate votes:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d\n", candidates[i].votes);
    }

    // Print the winner
    int winner = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > winner) {
            winner = i;
        }
    }
    printf("The winner is: %s\n", candidates[winner].name);
}

int main() {
    // Initialize the voters and candidates
    for (int i = 0; i < MAX_VOTERS; i++) {
        voters[i].hasVoted = 0;
    }
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Add voters and candidates
    addVoter();
    addCandidate();

    // Vote
    vote();

    // Display the results
    displayResults();

    return 0;
}