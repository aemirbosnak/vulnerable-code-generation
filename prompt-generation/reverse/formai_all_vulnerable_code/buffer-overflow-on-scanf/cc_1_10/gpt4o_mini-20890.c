//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int voteCount;
} Candidate;

typedef struct {
    char voterID[NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void registerCandidate();
void registerVoter();
void castVote();
void displayResults();
void initializeVotingSystem();

int main() {
    initializeVotingSystem();
    int choice;

    while (1) {
        printf("\n=== Electronic Voting System ===\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
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
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void initializeVotingSystem() {
    totalCandidates = 0;
    totalVoters = 0;
}

void registerCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached!\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[totalCandidates].name);
    candidates[totalCandidates].voteCount = 0;
    totalCandidates++;
    printf("Candidate '%s' registered successfully!\n", candidates[totalCandidates - 1].name);
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum number of voters reached!\n");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%s", voters[totalVoters].voterID);
    voters[totalVoters].hasVoted = 0;
    totalVoters++;
    printf("Voter '%s' registered successfully!\n", voters[totalVoters - 1].voterID);
}

void castVote() {
    char voterID[NAME_LENGTH];
    printf("Enter your voter ID: ");
    scanf("%s", voterID);

    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted!\n");
                return;
            }
            printf("Available candidates:\n");
            for (int j = 0; j < totalCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int candidateIndex;
            printf("Choose candidate number to vote: ");
            scanf("%d", &candidateIndex);
            if (candidateIndex < 1 || candidateIndex > totalCandidates) {
                printf("Invalid candidate number!\n");
                return;
            }
            candidates[candidateIndex - 1].voteCount++;
            voters[i].hasVoted = 1;
            printf("Vote casted for '%s' successfully!\n", candidates[candidateIndex - 1].name);
            return;
        }
    }
    printf("Voter ID not found!\n");
}

void displayResults() {
    printf("\n=== Voting Results ===\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].voteCount);
    }
}