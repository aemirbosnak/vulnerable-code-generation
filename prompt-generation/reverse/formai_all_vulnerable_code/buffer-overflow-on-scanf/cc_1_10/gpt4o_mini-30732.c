//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[100];
    int votes;
} Candidate;

typedef struct {
    char name[100];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0;
int numVoters = 0;

// Function to register a candidate
void registerCandidate() {
    if (numCandidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[numCandidates].name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
    printf("Candidate %s registered successfully!\n", candidates[numCandidates - 1].name);
}

// Function to register a voter
void registerVoter() {
    if (numVoters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voters[numVoters].name);
    voters[numVoters].hasVoted = 0;
    numVoters++;
    printf("Voter %s registered successfully!\n", voters[numVoters - 1].name);
}

// Function to cast a vote
void castVote() {
    char voterName[100], candidateName[100];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }

            printf("Enter candidate name to vote for: ");
            scanf("%s", candidateName);
            for (int j = 0; j < numCandidates; j++) {
                if (strcmp(candidates[j].name, candidateName) == 0) {
                    candidates[j].votes++;
                    voters[i].hasVoted = 1;
                    printf("Vote for %s recorded successfully!\n", candidateName);
                    return;
                }
            }
            printf("Candidate %s not found!\n", candidateName);
            return;
        }
    }
    printf("Voter %s not registered!\n", voterName);
}

// Function to display results
void displayResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main menu
void mainMenu() {
    int choice;
    do {
        printf("\n--- Electronic Voting System ---\n");
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
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    mainMenu();
    return 0;
}