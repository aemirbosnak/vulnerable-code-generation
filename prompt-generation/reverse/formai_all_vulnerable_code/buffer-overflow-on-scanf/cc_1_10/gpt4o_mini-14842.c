//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
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
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Max candidates reached.\n");
        return;
    }
    printf("Enter Candidate ID: ");
    scanf("%d", &candidates[candidateCount].id);
    printf("Enter Candidate Name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate registered successfully!\n");
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Max voters reached.\n");
        return;
    }
    printf("Enter Voter ID: ");
    scanf("%d", &voters[voterCount].id);
    printf("Enter Voter Name: ");
    scanf("%s", voters[voterCount].name);
    voters[voterCount].voted = 0;
    voterCount++;
    printf("Voter registered successfully!\n");
}

void vote() {
    int voterId, candidateId;
    printf("Enter your Voter ID: ");
    scanf("%d", &voterId);

    // Check if the voter is registered
    int voterIndex = -1;
    for (int i = 0; i < voterCount; i++) {
        if (voters[i].id == voterId) {
            voterIndex = i;
            break;
        }
    }
    
    if (voterIndex == -1) {
        printf("Voter ID not found.\n");
        return;
    }

    if (voters[voterIndex].voted) {
        printf("You have already voted!\n");
        return;
    }
    
    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("ID: %d, Name: %s\n", candidates[i].id, candidates[i].name);
    }
    
    printf("Enter Candidate ID to vote for: ");
    scanf("%d", &candidateId);

    // Check if the candidate exists
    int candidateIndex = -1;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].id == candidateId) {
            candidateIndex = i;
            break;
        }
    }
    
    if (candidateIndex == -1) {
        printf("Candidate ID not found.\n");
        return;
    }

    // Register the vote
    candidates[candidateIndex].votes++;
    voters[voterIndex].voted = 1;
    printf("Vote cast successfully!\n");
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                vote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}