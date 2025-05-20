//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[NAME_LENGTH];
    int voted; // 0: Not voted, 1: Voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate '%s' registered successfully!\n", candidates[candidateCount - 1].name);
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voters[voterCount].name);
    voters[voterCount].voted = 0;
    voterCount++;
    printf("Voter '%s' registered successfully!\n", voters[voterCount - 1].name);
}

void castVote() {
    char voterName[NAME_LENGTH];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted == 1) {
                printf("You have already voted!\n");
                return;
            }
            printf("Available candidates:\n");
            for (int j = 0; j < candidateCount; j++) {
                printf("%d: %s\n", j + 1, candidates[j].name);
            }
            int choice;
            printf("Enter candidate number to vote for: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > candidateCount) {
                printf("Invalid choice! Try again.\n");
                return;
            }

            candidates[choice - 1].votes++;
            voters[i].voted = 1; // Mark voter as having voted
            printf("Vote cast for '%s'. Thank you!\n", candidates[choice - 1].name);
            return;
        }
    }
    printf("Voter not found. Please register first.\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int maxVotes = 0;
    char winningCandidate[NAME_LENGTH];
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winningCandidate, candidates[i].name);
        }
    }
    printf("Winner is '%s' with %d votes!\n", winningCandidate, maxVotes);
}

int main() {
    int choice;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
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
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    
    return 0;
}