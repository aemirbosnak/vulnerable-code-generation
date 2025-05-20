//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
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
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

void addCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Maximum candidates reached!\n");
        return;
    }
    
    printf("Enter candidate name: ");
    scanf("%s", candidates[totalCandidates].name);
    candidates[totalCandidates].votes = 0;
    totalCandidates++;
    printf("Candidate %s added!\n", candidates[totalCandidates - 1].name);
}

void addVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum voters reached!\n");
        return;
    }
    
    voters[totalVoters].id = totalVoters + 1;
    voters[totalVoters].hasVoted = 0;
    totalVoters++;
    printf("Voter %d registered!\n", voters[totalVoters - 1].id);
}

void castVote() {
    int voterId, candidateIndex;
    printf("Enter your voter ID: ");
    scanf("%d", &voterId);

    if (voterId < 1 || voterId > totalVoters) {
        printf("Invalid voter ID!\n");
        return;
    }

    if (voters[voterId - 1].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &candidateIndex);

    if (candidateIndex < 1 || candidateIndex > totalCandidates) {
        printf("Invalid candidate selection!\n");
        return;
    }

    candidates[candidateIndex - 1].votes++;
    voters[voterId - 1].hasVoted = 1;
    printf("Vote casted for %s!\n", candidates[candidateIndex - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("------------------------------------------------\n");
}

void displayMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addCandidate();
                break;
            case 2:
                addVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    
    return 0;
}