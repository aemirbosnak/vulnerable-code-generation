//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: protected
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
    int voterId;
    int votedFor;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Candidate registration limit reached!\n");
        return;
    }
    
    Candidate newCandidate;
    newCandidate.id = candidateCount + 1;

    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;

    candidates[candidateCount++] = newCandidate;
    printf("Candidate %s registered successfully!\n", newCandidate.name);
}

void vote() {
    int voterId;
    printf("Enter your voter ID: ");
    scanf("%d", &voterId);
    
    for (int i = 0; i < voterCount; i++) {
        if (voters[i].voterId == voterId) {
            printf("You have already voted!\n");
            return;
        }
    }

    printf("Vote for a candidate (1-%d): ", candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        printf("\n%d. %s", candidates[i].id, candidates[i].name);
    }

    int choice;
    scanf("%d", &choice);
    
    if (choice < 1 || choice > candidateCount) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    voters[voterCount].voterId = voterId;
    voters[voterCount].votedFor = choice;
    voterCount++;

    printf("Vote recorded for %s!\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int winnerIndex = 0;
    for (int i = 1; i < candidateCount; i++) {
        if (candidates[i].votes > candidates[winnerIndex].votes) {
            winnerIndex = i;
        }
    }

    printf("\nWinner: %s with %d votes\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}