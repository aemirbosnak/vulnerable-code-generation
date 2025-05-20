//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

// Struct to hold candidate information
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to display candidates
void displayCandidates(Candidate candidates[], int count) {
    printf("\nAvailable Candidates:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to cast a vote
void castVote(Candidate candidates[], int count, int voterID, int *voterIDs, int *votesCounter) {
    if (voterIDs[voterID] == 1) {
        printf("Voter has already voted.\n");
        return;
    }

    int choice;
    printf("Enter the candidate number you wish to vote for (1 to %d): ", count);
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid choice! Please select a valid candidate number.\n");
        return;
    }

    candidates[choice - 1].votes++;
    voterIDs[voterID] = 1;  // Mark the voter as having voted
    (*votesCounter)++;  // Increment the counter for total votes cast
    printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
}

// Function to display results
void displayResults(Candidate candidates[], int count) {
    printf("\nElection Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Diana", 0},
        {"Ethan", 0}
    };
    int voterIDs[MAX_VOTERS] = {0}; // 0 for not voted, 1 for voted
    int votesCounter = 0;
    int totalVoters = 0;
    char continueVoting = 'y';

    printf("***** Electronic Voting System *****\n");

    while (continueVoting == 'y' && totalVoters < MAX_VOTERS) {
        displayCandidates(candidates, MAX_CANDIDATES);
        castVote(candidates, MAX_CANDIDATES, totalVoters, voterIDs, &votesCounter);
        totalVoters++;

        printf("Do you want to vote again? (y/n): ");
        scanf(" %c", &continueVoting);
    } 

    printf("\nVoting has ended.\n");
    printf("Total Votes Cast: %d\n", votesCounter);
    displayResults(candidates, MAX_CANDIDATES);

    return 0;
}