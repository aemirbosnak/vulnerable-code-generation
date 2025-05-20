//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[50];
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void initializeCandidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].id = i + 1;
        printf("Enter name for candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
        totalCandidates++;
    }
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Voter registration is full.\n");
        return;
    }
    printf("Registering voter %d\n", totalVoters + 1);
    printf("Enter name for voter: ");
    scanf("%s", voters[totalVoters].name);
    voters[totalVoters].id = totalVoters + 1;
    totalVoters++;
}

void castVote() {
    if (totalVoters == 0) {
        printf("No voters registered.\n");
        return;
    }
    
    int voterId;
    printf("Enter voter ID (1 to %d): ", totalVoters);
    scanf("%d", &voterId);
    
    if (voterId < 1 || voterId > totalVoters) {
        printf("Invalid voter ID.\n");
        return;
    }

    int candidateId;
    printf("Available candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("ID: %d, Name: %s\n", candidates[i].id, candidates[i].name);
    }
    
    printf("Vote for candidate ID: ");
    scanf("%d", &candidateId);
    
    if (candidateId < 1 || candidateId > totalCandidates) {
        printf("Invalid candidate ID.\n");
        return;
    }
    
    candidates[candidateId - 1].votes++;
    printf("Vote cast successfully for %s!\n", candidates[candidateId - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("Candidate: %s - Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
    
    int maxVotes = 0;
    int winnerId = -1;
    
    for (int i = 0; i < totalCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerId = i;
        }
    }
    
    if (winnerId != -1) {
        printf("Winner: %s with %d votes!\n", candidates[winnerId].name, maxVotes);
    } else {
        printf("No votes were cast.\n");
    }
}

int main() {
    int choice;
    
    printf("Welcome to the Electronic Voting System\n");
    initializeCandidates();

    do {
        printf("\nMenu:\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the voting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}