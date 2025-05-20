//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the number of candidates
#define NUM_CANDIDATES 3

// Define the candidate names
char candidates[NUM_CANDIDATES][50] = {
    "Candidate A",
    "Candidate B",
    "Candidate C"
};

// Define the candidate IDs
int candidateIDs[NUM_CANDIDATES] = {
    1,
    2,
    3
};

// Define the number of voters
#define NUM_VOTERS 10

// Define the voter IDs
int voterIDs[NUM_VOTERS] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10
};

// Function to print the candidate names
void printCandidates() {
    printf("Candidates:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("  %s\n", candidates[i]);
    }
}

// Function to print the voter IDs
void printVoterIDs() {
    printf("Voters:\n");
    for (int i = 0; i < NUM_VOTERS; i++) {
        printf("  %d\n", voterIDs[i]);
    }
}

// Function to get the voter's choice
int getVoterChoice() {
    int choice = 0;
    printf("Please enter your choice (1-3): ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }
    return choice;
}

// Function to cast the voter's vote
void castVote(int voterID, int choice) {
    printf("Voter %d voted for candidate %d.\n", voterID, choice);
}

// Function to count the votes
int countVotes() {
    int totalVotes = 0;
    printf("Total votes cast: ");
    scanf("%d", &totalVotes);
    return totalVotes;
}

int main() {
    // Print the candidate names
    printCandidates();

    // Print the voter IDs
    printVoterIDs();

    // Get the voter's choice
    int choice = getVoterChoice();

    // Cast the voter's vote
    castVote(voterIDs[0], choice);

    // Count the votes
    int totalVotes = countVotes();

    printf("Total votes cast: %d\n", totalVotes);

    // Print the candidate names again
    printCandidates();

    // Print the voter IDs again
    printVoterIDs();

    // Get the voter's choice again
    choice = getVoterChoice();

    // Cast the voter's vote again
    castVote(voterIDs[1], choice);

    // Count the votes again
    totalVotes = countVotes();

    printf("Total votes cast: %d\n", totalVotes);

    // Print the candidate names again
    printCandidates();

    // Print the voter IDs again
    printVoterIDs();

    // Get the voter's choice again
    choice = getVoterChoice();

    // Cast the voter's vote again
    castVote(voterIDs[2], choice);

    // Count the votes again
    totalVotes = countVotes();

    printf("Total votes cast: %d\n", totalVotes);

    return 0;
}