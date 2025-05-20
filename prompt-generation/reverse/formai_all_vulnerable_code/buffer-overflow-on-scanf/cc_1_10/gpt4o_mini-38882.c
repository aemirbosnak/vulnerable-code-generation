//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[30];
    int votes;
} Candidate;

typedef struct {
    char name[30];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate();
void registerVoter();
void castVote();
void displayResults();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
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
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 5);
    return 0;
}

void displayMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached!\n");
        return;
    }
    
    printf("Enter candidate's name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate %s registered successfully!\n", candidates[candidateCount-1].name);
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum voter limit reached!\n");
        return;
    }
    
    printf("Enter voter's name: ");
    scanf("%s", voters[voterCount].name);
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter %s registered successfully!\n", voters[voterCount-1].name);
}

void castVote() {
    char voterName[30];
    printf("Enter your name: ");
    scanf("%s", voterName);
    
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Available Candidates:\n");
            for (int j = 0; j < candidateCount; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int voteIndex;
            printf("Select your candidate (1-%d): ", candidateCount);
            scanf("%d", &voteIndex);
            if (voteIndex < 1 || voteIndex > candidateCount) {
                printf("Invalid candidate selection!\n");
                return;
            }
            candidates[voteIndex - 1].votes++;
            voters[i].hasVoted = 1;
            printf("Vote casted for %s successfully!\n", candidates[voteIndex - 1].name);
            return;
        }
    }
    printf("Voter not found. Please register first!\n");
}

void displayResults() {
    printf("\n--- Voting Results ---\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}