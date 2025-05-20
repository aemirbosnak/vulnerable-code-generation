//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
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
    char voterID[20];
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void addCandidate() {
    if (totalCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[totalCandidates].name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
    } else {
        printf("Maximum candidates reached.\n");
    }
}

void castVote() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum voters reached.\n");
        return;
    }
    
    char voterID[20];
    printf("Enter voter ID: ");
    scanf("%s", voterID);
    
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            printf("You have already voted.\n");
            return;
        }
    }
    
    printf("Available candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    int choice;
    printf("Select a candidate to vote (1-%d): ", totalCandidates);
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= totalCandidates) {
        candidates[choice - 1].votes++;
        strcpy(voters[totalVoters].voterID, voterID);
        totalVoters++;
        printf("Vote casted for %s successfully!\n", candidates[choice - 1].name);
    } else {
        printf("Invalid candidate selected.\n");
    }
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}