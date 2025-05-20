//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: active
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
int voterCount = 0;
int candidateCount = 0;

void addCandidate() {
    if (candidateCount < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[candidateCount].name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    } else {
        printf("Cannot add more candidates!\n");
    }
}

void castVote() {
    if (voterCount >= MAX_VOTERS) {
        printf("All voters have already voted!\n");
        return;
    }

    char voterID[20];
    printf("Enter your Voter ID: ");
    scanf("%s", voterID);

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            printf("You have already voted!\n");
            return;
        }
    }

    printf("Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice = 0;
    printf("Enter the candidate number to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    
    strcpy(voters[voterCount].voterID, voterID);
    voterCount++;

    printf("Vote casted successfully for %s!\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int maxVotes = 0;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
        }
    }

    printf("Winner(s):\n");
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes == maxVotes) {
            printf("%s\n", candidates[i].name);
        }
    }
}

int main() {
    int choice;
    
    do {
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
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}