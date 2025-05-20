//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterId[20];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate(const char* name) {
    if (candidateCount < MAX_CANDIDATES) {
        strncpy(candidates[candidateCount].name, name, 50);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    } else {
        printf("Maximum number of candidates reached!\n");
    }
}

void registerVoter(const char* voterId) {
    if (voterCount < MAX_VOTERS) {
        strncpy(voters[voterCount].voterId, voterId, 20);
        voters[voterCount].hasVoted = 0;
        voterCount++;
    } else {
        printf("Maximum number of voters reached!\n");
    }
}

int findVoterIndex(const char* voterId) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterId, voterId) == 0) {
            return i;
        }
    }
    return -1;
}

int findCandidateIndex(const char* candidateName) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, candidateName) == 0) {
            return i;
        }
    }
    return -1;
}

void castVote(const char* voterId, const char* candidateName) {
    int voterIndex = findVoterIndex(voterId);
    
    if (voterIndex == -1) {
        printf("Voter ID not found.\n");
        return;
    }
    
    if (voters[voterIndex].hasVoted) {
        printf("Voter has already voted!\n");
        return;
    }

    int candidateIndex = findCandidateIndex(candidateName);
    
    if (candidateIndex == -1) {
        printf("Candidate not found.\n");
        return;
    }
    
    candidates[candidateIndex].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote cast successfully for %s!\n", candidateName);
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char tempName[50];
    char voterId[20];
    char candidateName[50];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", tempName);
                addCandidate(tempName);
                break;
            case 2:
                printf("Enter voter ID: ");
                scanf("%s", voterId);
                registerVoter(voterId);
                break;
            case 3:
                printf("Enter voter ID: ");
                scanf("%s", voterId);
                printf("Enter candidate name: ");
                scanf("%s", candidateName);
                castVote(voterId, candidateName);
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}