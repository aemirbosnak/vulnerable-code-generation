//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int id;
    int vote;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

void initializeCandidates() {
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &totalCandidates);
    if (totalCandidates > MAX_CANDIDATES) {
        printf("Max candidates exceeded. Setting to %d\n", MAX_CANDIDATES);
        totalCandidates = MAX_CANDIDATES;
    }

    for (int i = 0; i < totalCandidates; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to zero
    }
}

void castVote() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Voting capacity reached. No more votes can be cast.\n");
        return;
    }

    int candidateNumber;
    printf("Available candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &candidateNumber);
    
    if (candidateNumber < 1 || candidateNumber > totalCandidates) {
        printf("Invalid candidate number.\n");
        return;
    }

    voters[totalVoters].id = totalVoters + 1;
    voters[totalVoters].vote = candidateNumber - 1; // Store index for the candidate
    candidates[candidateNumber - 1].votes++; // Increment candidate votes
    totalVoters++;
    printf("Thank you for voting!\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayVoteCount() {
    printf("\nVote Count:\n");
    for (int i = 0; i < totalVoters; i++) {
        printf("Voter ID %d voted for: %s\n", voters[i].id, candidates[voters[i].vote].name);
    }
}

int main() {
    int choice;

    initializeCandidates();

    do {
        printf("\nElectronic Voting System Menu:\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Display Vote Count\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                displayVoteCount();
                break;
            case 4:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}